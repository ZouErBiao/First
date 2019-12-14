using FluoriteEngine;
using SlimDX;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.IO.Ports;
using System.Text;
using System.Threading;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Forms;
using System.Windows.Media.Imaging;
using System.Collections.ObjectModel;
using FFRobotMaster.Steering;
using System.Windows.Threading;
using System.Windows.Controls.Primitives;
using System.Linq;
using System.Management;
using System.Runtime.InteropServices;
using System.Windows.Interop;
using FFRobotMaster.Capture;

namespace FFRobotMaster
{
    public partial class MainWindow : Window
    {

        string path = System.Windows.Forms.Application.StartupPath;
        Robot myRobot;
        ViewMouseEnum myViewMouse;
        bool amUsingMirror;
        XModel mySky;
        XModel myPoint;
        XModel myGround;
        Picture myRobotPic, myHighLightPic, mySelectedPic;
        Picture myGroundPic;
        Animate mySelectedAni;
        Picture mySkyPic;
        Picture myUpPic, myUpPressedPic, myDownPic, myDownPressedPic;

        Picture myBlackPic, myWhitePic;
        bool amCapturing = false;
        float myCaptureDelta;

        StringBuilder myAngleBuilder;

        Ray myMouseRay;
        int myHilightIndex, mySelectedIndex = 0;//回来在此处修改
        int Charone = 0;
        int CharTen = 0;


        Layer myLayer;
        Writting myWritting;
        int C;
        Bitmap frameBitmap;
        Graphics frameCathe;
        private float myViewX, myViewY, myViewZ;
        private Vector3 myViewPos;
        private int myMouseButton;
        private Vector2 myMouseStart;
        private SunLight mySun;
        private Vector2 myMousePos;
        private bool myWheelReady;
        private enum ViewMouseEnum
        {
            Select = 0,
            Translate = 1,
            Rotate = 2,
            Scale = 3
        }
        private enum ViewAlignEnum
        {
            TwoFeet = 0,
            LeftFoot = 1,
            RightFoot = 2
        }

        ViewAlignEnum myViewAlign;
        private int mySelectedActionBefore = -1, mySelectedAction = -1;
        private int mySelectedFrame = -1;
        private string mySelectedActionName;
        private bool amPlaying = false;
        private bool amPaused = false;
        private float lastTime;
        private float myPlayTime;
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        List<Action> myActions;
        Robot_ProtocolV2_0 robotProtocol = new Robot_ProtocolV2_0();
        ManualResetEvent userReset = new ManualResetEvent(true);
        private bool follow = false;//是否跟随
        private bool reflash = false;//是否更新实体
        private List<Uc.JointButtonUC> jointBtnList;

        public MainWindow()
        {
            InitializeComponent();
            this.Width = SystemParameters.WorkArea.Width;
            this.Height = SystemParameters.WorkArea.Height;
        }

        private DispatcherTimer autoDetectionTimer = new DispatcherTimer();//串口检测


        #region UI 窗体--------------->
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            ActionsFile af = new ActionsFile();
            myActions = af.ToActions();
            UpdateActionList(myActions);
            obtainComAndList();
            // 设置自动检测1秒1次
            autoDetectionTimer.Interval = new TimeSpan(0, 0, 0, 0, 100);//500ms
            autoDetectionTimer.Tick += new EventHandler(AutoDectionTimer_Tick);
            //开启定时器
            autoDetectionTimer.Start();

            Fluorite.Load += Fluorite_Load;
            Fluorite.Render += Fluorite_Render;
            Fluorite.InitializeControl(virtualRobot.Handle);
            Fluorite.Run();//运行引擎加载事件
            virtualRobot.MouseWheel += VirtualRobot_MouseWheel;
            virtualRobot.MouseDown += VirtualRobot_MouseDown;
            virtualRobot.MouseUp += VirtualRobot_MouseUp;
            virtualRobot.MouseMove += VirtualRobot_MouseMove;
            virtualRobot.MouseEnter += VirtualRobot_MouseEnter;
            virtualRobot.MouseLeave += VirtualRobot_MouseLeave;
            // 着地情况
            myRobot.Align2("左脚", "右脚", Vector3.UnitY);
            myViewAlign = ViewAlignEnum.TwoFeet;
            backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            backgroundWorker1.WorkerReportsProgress = false;
            backgroundWorker1.WorkerSupportsCancellation = true;
            backgroundWorker1.DoWork += new System.ComponentModel.DoWorkEventHandler(this.backgroundWorker1_DoWork);
            //backgroundWorker1.ProgressChanged += new System.ComponentModel.ProgressChangedEventHandler(this.backgroundWorker1_ProgressChanged);
            //backgroundWorker1.RunWorkerCompleted += new System.ComponentModel.RunWorkerCompletedEventHandler(this.backgroundWorker1_RunWorkerCompleted);
            // 按照控件添加的顺序放入
            jointBtnList = FindChirldHelper.FindVisualChild<Uc.JointButtonUC>(this.Expand);
            DataGrid2.ItemsSource = cfgList;
            //System.Windows.MessageBox.Show("目前基本包含旧版软件所有功能，如果发现Bug,请及时反馈！");
        }

        private void window_Closing(object sender, CancelEventArgs e)
        {
            MessageBoxResult result = System.Windows.MessageBox.Show("确定退出程序？", "提示", MessageBoxButton.YesNo, MessageBoxImage.Warning, MessageBoxResult.No);
            if (result == MessageBoxResult.No)
            {
                e.Cancel = true;
                return;                
            }
            robotProtocol.robot_shake(0x01);
        }

        private void Window_Closed(object sender, EventArgs e)
        {
            Fluorite.Terminate();
            System.Windows.Forms.Application.Exit();
        }

        private void KeyClick(object sender, RoutedEventArgs e)
        {
            conf.IsEnabled = !conf.IsEnabled;
        }

        #endregion
        /// <summary>
        /// 获取串口编号以及显示到combox中
        /// </summary>
        /// <param name="obj"></param>
        /// <param name="name"></param>
        private void obtainComAndList()
        {
            string[] serialPortName = SerialPort.GetPortNames();
            if (portComboBox.Items.Count != serialPortName.Length)
            {
                portComboBox.Items.Clear();
                foreach (string name in serialPortName)
                {
                    portComboBox.Items.Add(name);
                }
                portComboBox.SelectedIndex = 0;
            }
        }

        public static int progress = 0;
        private void AutoDectionTimer_Tick(object sender, EventArgs e)
        {
            string[] serialPortName = SerialPort.GetPortNames();
            if (portComboBox.Items.Count != serialPortName.Length)
            {
                portComboBox.Items.Clear();
                foreach (string name in serialPortName)
                {
                    portComboBox.Items.Add(name);
                }
                portComboBox.SelectedIndex = 0;
            }

            //更新UI进度条
            statusInfoPB.Value = progress;
        }

        #region UI工具栏--------------------------->    
        private void connectButton_ClickEvent(object sender, System.Windows.Input.MouseButtonEventArgs e)
        {
            if (robotProtocol.com.IsOpen)//串口已经打开
            {
                try{
                    robotProtocol.StopCommunicationServe();
                    this.connectButton.m_Border.Background = new System.Windows.Media.SolidColorBrush(System.Windows.Media.Colors.White);
                }
                catch (Exception)
                { };
            }
            else{
                robotProtocol.reportError += RobotProtocol_reportError;
                robotProtocol.reportBat += RobotProtocol_reportBat;
                robotProtocol.StartCommunicationServe(portComboBox.Text, 9600);
                this.connectButton.m_Border.Background = new System.Windows.Media.SolidColorBrush(System.Windows.Media.Colors.Red);
            }
        }
        private void blescanButton_ClickEvent(object sender, System.Windows.Input.MouseButtonEventArgs e)
        {
            string[] bleList = robotProtocol.scanBle();
            if (bleList != null){
                bleComboBox.Items.Clear();
                foreach (string mac in bleList){
                    bleComboBox.Items.Add(mac);
                }
                bleComboBox.SelectedIndex = 0;
                RobotProtocol_reportError("搜索机器人完毕");
            }
            else
            {
                System.Windows.MessageBox.Show("没有搜索到机器人或者机器人已经连接");
            }
        }
        private void bleconButton_ClickEvent(object sender, System.Windows.Input.MouseButtonEventArgs e)
        {
            if (robotProtocol.conBle(bleComboBox.Text)){
                robotProtocol.robot_shake(0x00);
                System.Windows.MessageBox.Show("连接成功");
            }
            else{
                System.Windows.MessageBox.Show("连接失败");
            }
        }

        static string batInf = null;
        private void RobotProtocol_reportBat(int value,int per){      
            Dispatcher.BeginInvoke(new System.Action(delegate { batInf = "机器人电量：" + per + "%("+((double)value*0.1).ToString("#0.0") + "V)"; }));
        }





        private void loadButton_ClickEvent(object sender, System.Windows.Input.MouseButtonEventArgs e)
        {
            Microsoft.Win32.OpenFileDialog dlg = new Microsoft.Win32.OpenFileDialog();
            dlg.DefaultExt = ".af";
            dlg.Filter = "机器人动作文件|*.af;*.txt";
            dlg.InitialDirectory = path + "\\Actions";
            Nullable<bool> result = dlg.ShowDialog();
            if (result == true && dlg.FileName.Contains(".af"))
            {
                string filename = dlg.FileName;
                ActionsFile af = new ActionsFile(filename);
                myActions = af.ToActions();
                UpdateActionList(myActions);
            }
            else if (result == true && dlg.FileName.Contains(".txt"))
            {
                string filename = dlg.FileName;
                ActionsFile af = new ActionsFile(filename);
                myActions = af.ToActions();
            }
        }

        private void saveButton_ClickEvent(object sender, System.Windows.Input.MouseButtonEventArgs e)
        {
            Microsoft.Win32.SaveFileDialog slg = new Microsoft.Win32.SaveFileDialog();
            slg.DefaultExt = ".af";
            slg.Filter = "机器人动作文件|*.af";
            slg.InitialDirectory = path + "\\Actions";
            Nullable<bool> result = slg.ShowDialog();
            if (result == true){
                string filename = slg.FileName;
                ActionsFile af = new ActionsFile(myActions);
                af.Save(filename);
                af.Dispose();
            }
        }

        private void helpButton_ClickEvent(object sender, System.Windows.Input.MouseButtonEventArgs e)
        {
            try
            {
                System.Diagnostics.Process.Start(path + "\\Help\\help.pdf");
            }
            catch (Exception)
            {
                System.Windows.MessageBox.Show("帮助文件打开失败，请安装PDF阅读器！");
            }
        }

        #endregion

        #region UI 虚拟机器人------------>
        private void VirtualRobot_MouseWheel(object sender, MouseEventArgs e)
        {
            
            if (myWheelReady)
            {
                /*
                myViewZ -= e.Delta / 2;
                if (myViewZ < 500)
                    myViewZ = 500;
                if (myViewZ > 1400)
                    myViewZ = 1400;
                    */
                myViewZ = 750;
            }
            
            
        }

        private void VirtualRobot_MouseLeave(object sender, EventArgs e)
        {
            myWheelReady = false;
        }

        private void VirtualRobot_MouseEnter(object sender, EventArgs e)
        {
            myWheelReady = true;
        }

        
        private void VirtualRobot_MouseMove(object sender, System.Windows.Forms.MouseEventArgs e)
        {
            myMousePos = e.Location.ToVector2();

            //此处鼠标控制摄像机运动，右键点下，则myMouseButton被赋值为2,；
            if (myMouseButton == 2)// 摄像机运动
             {
                
                Vector2 tmpMouse = new Vector2(e.X, e.Y);
                 myViewY += (tmpMouse.Y - myMouseStart.Y) / 100F;
                 myViewX += (tmpMouse.X - myMouseStart.X) / 100F;
                 if (myViewY < -1.57F)
                     myViewY = -1.57F;
                 if (myViewY > 1.57F)
                     myViewY = 1.57F;
                 myMouseStart = tmpMouse;
                 /*
                myViewY = -1.2F / 100F;
                myViewX = -1.2F / 100F;
                */
            }
            /*
            //原程序
            if (myMouseButton == 4)// 物体变形
            {
                Vector2 tmpMouse = new Vector2(e.X, e.Y);
                int d = (int)((tmpMouse.Y - myMouseStart.Y) / 2);
                myRobot[mySelectedIndex].Angle += d;

                if (amUsingMirror && myRobot[mySelectedIndex].MirrorIndex > -1)
                    myRobot[myRobot[mySelectedIndex].MirrorIndex].Angle = myRobot[mySelectedIndex].Angle;
                if (d != 0)
                    myMouseStart = tmpMouse;
            }
            

            //修改部分
            if (myMouseButton == 4)// 物体变形
            {
                //Vector2 tmpMouse = new Vector2(e.X, e.Y);
               // int d = (int)((tmpMouse.Y - myMouseStart.Y) / 2);
                myRobot[mySelectedIndex].Angle += 10;

                if (amUsingMirror && myRobot[mySelectedIndex].MirrorIndex > -1)
                    myRobot[myRobot[mySelectedIndex].MirrorIndex].Angle = myRobot[mySelectedIndex].Angle;
               // if (d != 0)
               //     myMouseStart = tmpMouse;
            }
            */
        }
        


        private void VirtualRobot_MouseUp(object sender, System.Windows.Forms.MouseEventArgs e)
        {
            myMouseButton = 0;
        }


        //源程序
        
        private void VirtualRobot_MouseDown(object sender, System.Windows.Forms.MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                myMouseButton = 4;
                myMouseStart = new Vector2(e.X, e.Y);
            /*
                float tmpd = 0F, tmpe = float.MaxValue;//MaxValue = 3.40282347E+38F;
                int tmpi = mySelectedIndex;

                myRobot[mySelectedIndex].Angle += 10;//自己加

                Thread.Sleep(1 * 1000);


                // 判断被选模型号
                for (int t = 0; t < myRobot.Count; t++)
                {
                    int tmpt = (mySelectedIndex + t) % myRobot.Count;//tmpt=0、2/4/6/8/10/12、1、3/5/7/9/11

                    if (myRobot.UpdatedModel.Intersects(myMouseRay, myRobot[tmpt].Subset, ref tmpd) && tmpd < tmpe)
                    {
                        tmpe = tmpd;
                        tmpi = tmpt;
                    }
                }
                mySelectedIndex = tmpi;
            */
            }
            
            if (e.Button == MouseButtons.Right)
            {
                myMouseButton = 2;
                myMouseStart = new Vector2(e.X, e.Y);
            }
            
        }
        #endregion


    
        #region UI 展开视图
        /// <summary>
        /// 路有事件，关节点击事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
       private void Expand_Click(object sender, RoutedEventArgs e)
        {
            int sel_id = int.Parse((e.Source as Uc.JointButtonUC).ID);
            mySelectedIndex = ID2Model(sel_id);
            myHilightIndex = mySelectedIndex;
        }

        /// <summary>
        /// 恢复默认配置
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void defaultCfg_Click(object sender, RoutedEventArgs e)
        {
            int index = DataGrid2.SelectedIndex;
            if (index >= 0 & index < DataGrid2.Items.Count)
            {
                int mod = Num2Model(index);
                int id = Model2ID(mod);

                robotProtocol.robot_lock(new byte[]{(byte)id, 0x00 });//松

                robotProtocol.robot_setDif(new byte[]{(byte)id,(byte)0,(byte)200});

                robotProtocol.robot_lock(new byte[]{(byte)id, 0x01 });//锁

                System.Windows.MessageBox.Show("关节ID{0}偏移已经设为初始值200！", id.ToString());
            }
        }
        private void getValue_Click(object sender, RoutedEventArgs e)
        {            
            UInt16[] angle = robotProtocol.robot_readAllAngle();
            for (int j = 0; j < 13; j++)
            {
                int i = Num2Model(j); int k = Model2ID(i);
                cfgList[j].cur = angle[k];
            }
            for (int i = 1; i <= 13; i++)
            {
                currentPosition[i] = angle[i];
                int k = ID2Model(i);
                myRobot[k].Angle = (float)((currentPosition[i] - myRobot[k].Zero) * 270f / 4095 * myRobot[k].Proportion);
            }
            updateCfg(myRobot);
        }

        private void setZero_Click(object sender, RoutedEventArgs e)
        {
            int index = DataGrid2.SelectedIndex;
            if (index >= 0 & index < DataGrid2.Items.Count){
                int mod = Num2Model(index);
                int id = Model2ID(mod);
                int value = (int)Math.Floor(200 + (cfgList[index].cur - cfgList[index].zero) / 1.28f);
                if (value >= 0 && value <= 400){
                    //byte[] data = new byte[]{
                    //    (byte)id,(byte)value,(byte)(value >> 8 & 0xFF)
                    //};
                    //robotProtocol.robot_setDif(data);

                    robotProtocol.robot_lock(new byte[] { (byte)id, 0x00 });//松

                    robotProtocol.robot_setDif(new byte[] { (byte)id, (byte)value, (byte)(value >> 8 & 0xFF) });

                    robotProtocol.robot_lock(new byte[] { (byte)id, 0x01 });//锁

                }
                else{
                    System.Windows.MessageBox.Show("当前关节超出可调范围！");
                }
            }
        }

        private void getDv_Click(object sender, RoutedEventArgs e)
        {
            updateCfg(myRobot);
            UInt16[] dif = robotProtocol.robot_readDif();            
            for (int j = 0; j < 13; j++){
                int i = Num2Model(j);int k = Model2ID(i);
                cfgList[j].dv = dif[k];
            }
        }

        // 下载语音交互文件
        private void setTTS_Click(object sender, RoutedEventArgs e)
        {
            // 
            //robotProtocol.robot_createAction(mySelectedAction.ToString() + "-" + myActions[mySelectedAction].Name, Action2FFByte(mySelectedAction));
        }

        private ObservableCollection<robotCfg> cfgList = new ObservableCollection<robotCfg>();
        private class robotCfg
        {
            public string name { get; set; }
            public int zero { get; set; }
            public string dir { get; set; }
            public int dv { get; set; }
            public float amin { get; set; }
            public float amax { get; set; }
            public float cur { get; set; }
        }

        private void updateCfg(Robot r)
        {
            cfgList.Clear();
            for (int j = 0; j <= 12; j++){
                int i = Num2Model(j);
                cfgList.Add(new robotCfg(){
                    name = r[i].Name,
                    zero = r[i].Zero,
                    dir = r[i].Proportion.ToString(),
                    dv = currentDv[j+1],
                    amin = r[i].AngleLimitA,
                    amax = r[i].AngleLimitB,
                    cur = currentPosition[j+1],
                });
            }
        }

        private void up_btn_Click(object sender, RoutedEventArgs e)
        {
            byte[] data = new byte[2] {
                (byte)(int.Parse(speed_tb.Text)|0x80),
                (byte)int.Parse(speed_tb.Text)
            };
            robotProtocol.robot_wheel(data);
        }

        private void down_btn_Click(object sender, RoutedEventArgs e)
        {
            byte[] data = new byte[2] {               
               (byte)int.Parse(speed_tb.Text),
               (byte)(int.Parse(speed_tb.Text)|0x80)
            };
            robotProtocol.robot_wheel(data);
        }

        private void left_btn_Click(object sender, RoutedEventArgs e)
        {
            byte[] data = new byte[2] {
                (byte)int.Parse(speed_tb.Text),
                (byte)int.Parse(speed_tb.Text)
            };
            robotProtocol.robot_wheel(data);
        }

        private void right_btn_Click(object sender, RoutedEventArgs e)
        {
            byte[] data = new byte[2] {
                (byte)(int.Parse(speed_tb.Text)|0x80),
                (byte)(int.Parse(speed_tb.Text)|0x80),
            };
            robotProtocol.robot_wheel(data);
        }

        private void stop_btn_Click(object sender, RoutedEventArgs e)
        {
            byte[] data = new byte[2] {
                0x00,
                0x00
            };
            robotProtocol.robot_wheel(data);
        }

        #endregion

        #region UI 操作面板----------------------->

        private void op_GB_Click(object sender, RoutedEventArgs e)
        {
            System.Windows.Controls.Button btn = e.Source as System.Windows.Controls.Button;
            switch ((string)(btn.Content))
            {
                case "电池电量":
                    robotProtocol.robot_heart();                    
                    break;
                case "姿态回读":
                    UInt16[] angle =  robotProtocol.robot_readAllAngle();
                    for (int i = 1; i <= 13; i++){
                        currentPosition[i] = angle[i];
                        int k = ID2Model(i);
                        myRobot[k].Angle = (float)((currentPosition[i] - myRobot[k].Zero) * 270f / 4095 * myRobot[k].Proportion);
                    }
                    break;
                case "全身锁定":
                    robotProtocol.robot_lockAll(new byte[] { 0x01 });
                    break;
                case "全身解锁":
                    robotProtocol.robot_lockAll(new byte[] { 0x00 });
                    break;
                case "关节解锁":
                    robotProtocol.robot_lock(new byte[] { (byte)Model2ID(mySelectedIndex), 0x00 });
                    break;
                case "关节锁定":
                    robotProtocol.robot_lock(new byte[] { (byte)Model2ID(mySelectedIndex), 0x01 });
                    break;
                case "-":
                    myRobot[mySelectedIndex].Angle -= 1; //myRobot[mySelectedIndex].Angle--> 0 ? myRobot[mySelectedIndex].Angle : 0;
                    if (follow){
                        short angle1 = (short)(myRobot[mySelectedIndex].Angle * myRobot[mySelectedIndex].Proportion * 4095 / 270 + myRobot[mySelectedIndex].Zero);
                        byte[] data = new byte[]{
                            (byte)(Model2ID(mySelectedIndex)) ,
                            (byte)angle1 ,
                            (byte)(angle1 >> 8),
                            0x01
                        };
                        robotProtocol.robot_move(data);
                    }
                    break;
                case "+":
                    myRobot[mySelectedIndex].Angle = myRobot[mySelectedIndex].Angle++ >= 270 ? 270 : myRobot[mySelectedIndex].Angle;
                    if (follow){
                        short angle2 = (short)(myRobot[mySelectedIndex].Angle * myRobot[mySelectedIndex].Proportion * 4095 / 270 + myRobot[mySelectedIndex].Zero);
                        byte[] data = new byte[]{
                            (byte)(Model2ID(mySelectedIndex)) ,
                            (byte)angle2 ,
                            (byte)(angle2 >> 8),
                            0x01
                        };
                        robotProtocol.robot_move(data);
                    }
                    break;
                case "虚实同步":
                    if (follow == false){
                        btn.Background = new System.Windows.Media.SolidColorBrush(System.Windows.Media.Colors.Red);
                        follow = true;
                    }
                    else{
                        btn.Background = new System.Windows.Media.SolidColorBrush(System.Windows.Media.Colors.Transparent);
                        follow = false;
                    }
                    break;
                case "姿态控制":
                    byte[] ang = new byte[26+1];
                    int x = 0;
                    for (int j = 1; j <= 13; j++){
                        int k = ID2Model(j);
                        short d = (short)(myRobot[k].Angle * myRobot[k].Proportion * 4095 / 270 + myRobot[k].Zero);
                        ang[x++] = (byte)d;
                        ang[x++] = (byte)(d >> 8);
                    }
                    ang[x] = (byte)(int.Parse(runTime_tb.Text)/100);//5;//500ms                    
                    robotProtocol.robot_moveMult(ang);
                    break;
                case "虚拟姿态锁定":
                    if (reflash == false)
                    {
                        btn.Background = new System.Windows.Media.SolidColorBrush(System.Windows.Media.Colors.Red);
                        reflash = true;
                    }
                    else
                    {
                        btn.Background = new System.Windows.Media.SolidColorBrush(System.Windows.Media.Colors.Transparent);
                        reflash = false;
                    }
                    break;
                default:
                    break;
            }
        }

        private void RobotProtocol_reportError(string msg)
        {
            Dispatcher.BeginInvoke(new System.Action(delegate{ statusInfoTB.Text = msg;}));
        }

        private void Mirror_Click(object sender, RoutedEventArgs e)
        {
            System.Windows.Controls.Button btn = e.Source as System.Windows.Controls.Button;
            Frame tmpf = new Frame(myRobot.Count);
            switch ((string)btn.Content)
            {
                case "R"://使右侧对称
                    myRobot.MirrorLeft();                    
                    myRobot.GetFrame(tmpf);
                    break;
                case "L"://使左侧对称
                    myRobot.MirrorRight();
                    myRobot.GetFrame(tmpf);
                    break;
                case "M"://镜像
                    myRobot.Mirror();
                    myRobot.GetFrame(tmpf);
                    break;
                case "A"://自动对称
                    if (amUsingMirror == false)
                    {
                        btn.Background = new System.Windows.Media.SolidColorBrush(System.Windows.Media.Colors.Red);
                        amUsingMirror = true;
                    }
                    else
                    {
                        btn.Background = new System.Windows.Media.SolidColorBrush(System.Windows.Media.Colors.Transparent);
                        amUsingMirror = false;
                    }
                    break;
                case "5":
                    break;
                default:
                    break;
            }            
        }
        /// <summary>
        /// 当前关节位置
        /// </summary>
        public int[] currentPosition = new int[16]; // 1-15
        /// <summary>
        /// 当前关节偏移
        /// </summary>
        public int[] currentDv = new int[16];       // 1-15 // 当前偏移
        #endregion

        #region UI 动作列表操作-------------------------->
        private void actionLt_MouseLeftButtonUp(object sender, System.Windows.Input.MouseButtonEventArgs e)
        {
            if (actionLt.Items.Count > 0){
                mySelectedAction = actionLt.SelectedIndex;
                if (mySelectedAction != -1){
                    ActionNameTB.Text = actionLt.SelectedItem.ToString().Split(new char[] { ' ', '=', ',' })[14];
                    UpdateFrameList(myActions[mySelectedAction]);
                }
            }
        }


        Thread listen;
        /// <summary>
        /// 动作列表操作按钮
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void wrapPanelEdit_Click(object sender, RoutedEventArgs e)
        {
            string btn_name = (e.Source as System.Windows.Controls.Button).Content.ToString();
            switch (btn_name)
            {
                case "更改":
                    if (ActionNameTB.Text.Length < 7 && mySelectedAction != -1){
                        myActions[mySelectedAction].Name = ActionNameTB.Text;
                        UpdateActionList(myActions);//！！！
                    }
                    break;
                case "执行"://
                    if (ActionNameTB.Text.Length < 7 && mySelectedAction != -1){
                        robotProtocol.robot_run(mySelectedAction.ToString() + "-" + myActions[mySelectedAction].Name,0x01);
                    }
                    break;
                case "广播执行":
                    if (ActionNameTB.Text.Length < 7 && mySelectedAction != -1)
                    {
                        robotProtocol.robot_run(mySelectedAction.ToString() + "-" + myActions[mySelectedAction].Name, 0x02);
                    }
                    break;
                case "暂停":
                    ActionPause();
                    break;
                case "停止":
                    ActionStop();
                    break;
                case "预演":
                    ActionPlay(0);
                    break;
                case "下载"://
                    Thread listen = new Thread(() => robotProtocol.robot_createAction(mySelectedAction.ToString() + "-" + myActions[mySelectedAction].Name, Action2FFByte(mySelectedAction), 0x01));
                    listen.Start();
                    //robotProtocol.robot_createAction(mySelectedAction.ToString() + "-" + myActions[mySelectedAction].Name, Action2FFByte(mySelectedAction), 0x01);
                    break;
                case "导出数组"://导出下载txt动作文本
                    if (ActionNameTB.Text.Length < 7 && mySelectedAction != -1 && ActionNameTB.Text != ""){
                        Action2HexText(mySelectedAction);
                    }
                    else{
                        System.Windows.MessageBox.Show("导出无效！");
                    }
                    break;
                case "导出txt"://导出txt动作文本
                    if (ActionNameTB.Text.Length < 7 && mySelectedAction != -1 && ActionNameTB.Text != ""){
                        covTxt();
                    }
                    else{
                        System.Windows.MessageBox.Show("导出无效！");
                    }
                    break;
                case "导出ff":// 导出可以下载到机器人内部的.ff文件
                    if (ActionNameTB.Text.Length < 7 && mySelectedAction != -1 && ActionNameTB.Text != ""){
                        Action2FFHex(mySelectedAction);
                    }
                    else{
                        System.Windows.MessageBox.Show("导出无效！");
                    }
                    break;
                case "导入ff":// 导入旧action文件
                    ResolveAction re = new ResolveAction(path + "\\Actions\\action.txt");
                    if (actionLt.Items.Count > 0)
                    {
                        mySelectedAction = actionLt.SelectedIndex;
                        if (mySelectedAction != -1)
                        {                    
                            foreach(Frame f in re.KeyFrames)
                            {                                
                                Frame tempframe = new Frame(myRobot.Count);
                                tempframe.SetSnapShot(Fluorite.Screenshot());
                                //                                
                                tempframe[ID2Model(1)] = f[0];//2

                                tempframe[ID2Model(2)] = f[1];
                                tempframe[ID2Model(3)] = f[2];
                                tempframe[ID2Model(4)] = f[3];

                                tempframe[ID2Model(5)] = f[4];
                                tempframe[ID2Model(6)] = f[5];
                                tempframe[ID2Model(7)] = f[6];

                                tempframe[ID2Model(8)] = f[7];
                                tempframe[ID2Model(9)] = f[9];
                                tempframe[ID2Model(10)] = f[10];
                                tempframe[ID2Model(15)] = f[8];//右侧轮子

                                tempframe[ID2Model(11)] = f[12];
                                tempframe[ID2Model(12)] = f[14];
                                tempframe[ID2Model(13)] = f[15];
                                tempframe[ID2Model(14)] = f[13];//左侧轮子

                                tempframe.Duration = f.Duration;
                                tempframe.Pause = f.Pause;
                                myActions[mySelectedAction].KeyFrames.Add(tempframe);
                            }
                        }
                    }
                    
                    break;
                case "是否已下载":
                    myActions[mySelectedAction].Downloaded = 
                        (robotProtocol.robot_exist(mySelectedAction.ToString() + "-" + myActions[mySelectedAction].Name)) ? "√": "×" ;
                    UpdateActionList(myActions);
                    break;
                default:
                    break;
            }
        }

        string Desktop_dir = Environment.GetFolderPath(Environment.SpecialFolder.DesktopDirectory);
        //转换动作信息
        public class act
        {
            public string inf;
        };
        public List<act> actionlist = new List<act>();//转换动作列表
        int actionnum = 0;//数组号

        /// <summary>
        /// 动作文件转换为HexText文本
        /// </summary>
        public void Action2HexText(int actionNum)
        {
            StringBuilder hextxt = new StringBuilder();                        
            act subact = new act();//myActions[actionNum]
            //{"name",2,(u8*)framedata1,sizeof(framedata1)/24},
            subact.inf = "{" + $"\"{myActions[actionNum].Name}\",{actionNum}," + $"(u8*)framedata{actionnum},sizeof(framedata{actionnum})/24" + "},\r\n";
            actionlist.Add(subact);
            hextxt.Append($"const u16 framedata{actionnum++}[{myActions[actionNum].Count.ToString()}*24]=\r\n");
            hextxt.Append("{\r\n");
            for (int frameIndex = 0; frameIndex < myActions[actionNum].Count; frameIndex++)
            {
                byte flag;
                if (frameIndex == 0)//第一帧
                { flag = 0x01; }
                else if (frameIndex > 0 && frameIndex < myActions[actionNum].Count - 1)//中间帧
                { flag = 0x02; }
                else//结尾帧
                { flag = 0x03; }
                hextxt.AppendFormat("0xFA{0},0x0000,", flag.ToString("X2"));
                // 关节数据转化
                for (int j = 0; j < 17; j++)//data[0-17] - 2-18
                {
                    int k = Num2Model(j);
                    short d = (short)(myActions[actionNum].KeyFrames[frameIndex][k] * myRobot[k].Proportion * 4095 / 270 + myRobot[k].Zero);
                    hextxt.AppendFormat("0X{0},", d.ToString("X4"));
                }
                //运动时间,停顿时间
                float time = myActions[mySelectedAction].KeyFrames[frameIndex].Duration;//ms
                float pau = myActions[mySelectedAction].KeyFrames[frameIndex].Pause;
                hextxt.AppendFormat("0X0000,0x0000,0X{0},0X{1},0X00ED,\r\n", ((ushort)(time)).ToString("X4"), ((ushort)(pau)).ToString("X4"));
            }
            hextxt.Append("};\r\n");
            // 写入指定文件中，追加方式
            System.IO.File.AppendAllText(Desktop_dir + @"\\hextxt.txt", hextxt.ToString(), Encoding.Default);
            print();
            actionlist.Clear();
            actionnum = 0;
        }

        /// <summary>
        /// 某个编号的动作转换为可下载的动作文件
        /// </summary>
        /// <param name="actionNum"></param>
        public void Action2FFHex(int actionNum)
        {
            BinaryWriter bw;
            bw = new BinaryWriter(new FileStream(Desktop_dir + @"\\action_file.ff", FileMode.Create)); //创建文件            
            for (int frameIndex = 0; frameIndex < myActions[actionNum].Count; frameIndex++)
            {
                byte[] frame = new byte[46];
                // 头部
                frame[0] = 0xFA;
                // 标识
                if (frameIndex == 0)//第一帧
                { frame[1] = 0x01; }
                else if (frameIndex > 0 && frameIndex < myActions[actionNum].Count - 1)//中间帧
                { frame[1] = 0x02; }
                else
                { frame[1] = 0x03; }

                // 关节数据
                // id=1;
                frame[2] = 0;
                frame[3] = 0;
                for (int j = 0; j < 20; j++)//data[0-17] - 2-18 共17个 ，13 和18 方方没有
                {
                    if (j < 16)//0-15 -2-17 13 方方没有,没有的赋值0
                    {
                        int k = Num2Model(j);
                        short d = (short)(myActions[actionNum].KeyFrames[frameIndex][k] * myRobot[k].Proportion * 4095 / 270 + myRobot[k].Zero);
                        frame[4 + j * 2] = (byte)d;
                        frame[4 + j * 2 + 1] = (byte)(d >> 8);
                    }
                    else
                    {
                        frame[4 + j * 2] = 0;
                        frame[4+ j * 2 + 1] = 0;
                    }
                }
                //运动时间,停顿时间
                short time = (short)(myActions[mySelectedAction].KeyFrames[frameIndex].Duration/100);//100ms
                short pau = (short)(myActions[mySelectedAction].KeyFrames[frameIndex].Pause/100);//100ms

                frame[42] = (byte)time;
                frame[43] = (byte)pau;
                for (int i = 1; i < 44; i++)
                {
                    frame[44] += frame[i];
                }
                //frame[44] = (byte)~frame[44];
                frame[45] = 0xED;

                bw.Write(frame, 0, 46); 
            }
            bw.Close();
            System.Windows.MessageBox.Show("选中的动作生成完毕！");
        }

        public byte[] Action2FFByte(int actionNum)
        {
            byte[] data = new byte[myActions[actionNum].Count*46];
            
            for (int frameIndex = 0; frameIndex < myActions[actionNum].Count; frameIndex++)
            {
                byte[] frame = new byte[46];
                // 头部
                frame[0] = 0xFA;
                // 标识
                if (frameIndex == 0)//第一帧
                { frame[1] = 0x01; }
                else if (frameIndex > 0 && frameIndex < myActions[actionNum].Count - 1)//中间帧
                { frame[1] = 0x02; }
                else
                { frame[1] = 0x03; }
                // 关节数据
                for (int j = 0; j < 15; j++)
                {
                    int k = Num2Model(j);
                    if (k != 15 && k != 7)
                    {
                        short d = (short)(myActions[actionNum].KeyFrames[frameIndex][k] * myRobot[k].Proportion * 4095 / 270 + myRobot[k].Zero);
                        frame[2 + j * 2] = (byte)d;
                        frame[2 + j * 2 + 1] = (byte)(d >> 8);
                    }
                    else//轮子模型左15 右7
                    {
                        short d = (short)(myActions[actionNum].KeyFrames[frameIndex][k] * myRobot[k].Proportion);
                        frame[2 + j * 2] = (byte)(0x00);
                        frame[2 + j * 2 + 1] = (byte)(0x00);
                    }                  
                }
                //运动时间,停顿时间
                short time = (short)(myActions[mySelectedAction].KeyFrames[frameIndex].Duration / 100);//100ms
                short pau = (short)(myActions[mySelectedAction].KeyFrames[frameIndex].Pause / 100);//100ms
                frame[42] = (byte)time;
                frame[43] = (byte)pau;
                for (int i = 1; i < 44; i++){
                    frame[44] += frame[i];
                }
                frame[45] = 0xED;
                frame.CopyTo(data, frameIndex * 46);
            }
            return data;
        }

        public void print()
        {
            // 输出列表文件
            System.IO.File.AppendAllText(Desktop_dir + @"\\hextxt.txt", "act actlist[30]=\r\n{\r\n", Encoding.Default);//这里要注意 
            foreach (act a in actionlist){
                System.IO.File.AppendAllText(Desktop_dir + @"\\hextxt.txt", a.inf, Encoding.Default);//这里要注意 
            }
            System.IO.File.AppendAllText(Desktop_dir + @"\\hextxt.txt", "};\r\n", Encoding.Default);//这里要注意 
            System.Windows.MessageBox.Show("选中的动作生成完毕！");
        }

        /// <summary>
        /// 动作集导出TXT
        /// </summary>
        /// <param name="list"></param>
        private void covTxt()
        {
            StringBuilder sb = new StringBuilder();
            //打印头
            sb.AppendLine("Total:" + myActions.Count);
            sb.AppendLine("Fall:off");
            sb.Append("Zero:");
            //原点帧
            for (int j = 0; j < 17; j++)//data[0-17] - 2-18 （17自由度）
            {
                int k = Num2Model(j);
                if (j < 16)
                {
                    sb.AppendFormat("{0},", myRobot[k].Zero);
                }
                else{
                    sb.AppendFormat("{0}\r\n", myRobot[k].Zero);
                }
            }
            for(int i=0;i<myActions.Count;i++)
            {
                //打印动作内容
                //Num: 100
                //Name: zero1
                //N:2
                sb.AppendLine("Num:" + i);
                sb.AppendLine("Name:" + myActions[i].Name);
                sb.AppendLine("N:" + myActions[i].Count);
                //{}:                        
                for (int x = 0; x < myActions[i].KeyFrames.Count; x++)
                {
                    sb.Append("{");
                    // 关节数据转化
                    for (int j = 0; j < 17; j++)//data[0-17] - 2-18
                    {
                        int k = Num2Model(j);
                        short d = (short)(myActions[i].KeyFrames[x][k] * myRobot[k].Proportion * 4095 / 270);
                        if (j < 16)//// 值 = 绝对位置 - 原点
                        {
                            sb.Append(d.ToString()+",");
                        }
                        else
                        {
                            sb.Append(d.ToString());
                        }                    
                    }
                    sb.Append("}");
                    //运动时间,停顿时间
                    float time = myActions[i].KeyFrames[x].Duration;//ms
                    float pau = myActions[i].KeyFrames[x].Pause;
                    sb.AppendFormat(":{0}:{1}\r\n", ((ushort)(pau)).ToString(), ((ushort)(time)).ToString());
                }
            }
            System.IO.File.AppendAllText(Desktop_dir + @"\\action.txt",sb.ToString(), Encoding.UTF8);//这里要注意
            System.Windows.MessageBox.Show("动作文件生成完毕！");
        }

        /// <summary>
        /// 初始化动作列表
        /// </summary>
        /// <param name="actions"></param>
        private void InitActionList()
        {
            actionLt.Items.Clear();
            for (int i = 0; i < 100; i++)
            {
                actionLt.Items.Add(new
                {
                    actionDownloaded = "×",
                    actionIdStr = actionLt.Items.Count,
                    actionName = "",
                    frameCnt = i,
                    totalTime = 0,
                });
            }
        }

        /// <summary>
        /// 更新动作列表
        /// </summary>
        /// <param name="actions">动作集合</param>
        private void UpdateActionList(List<Action> actions)
        {
            actionLt.Items.Clear();
            foreach (Action action in actions){
                actionLt.Items.Add(new{
                    actionDownloaded = action.Downloaded,
                    actionIdStr = actionLt.Items.Count,
                    actionName = action.Name,
                    frameCnt = action.Count,
                    totalTime = action.Duration.ToString()
                });
            }
        }
       
        //播放-------->
        public bool runs = false;
        /// <summary>
        /// 模拟动画演示
        /// </summary>
        /// <param name="time"></param>
        private void ActionPlay(int time)
        {
            amPlaying = true;
            amPaused = false;
            myPlayTime = 0;
            if (!backgroundWorker1.IsBusy)
            {
                backgroundWorker1.RunWorkerAsync();
            }
            else
            {
                backgroundWorker1.CancelAsync();
            }
        }

        private void ActionPause()
        {
            amPaused = !amPaused;
            if (!backgroundWorker1.IsBusy)//未运行中
            {
                userReset.Set();
                robotProtocol.robot_ctr(0x00);
            }
            else//运行中
            {
                userReset.Reset();
                robotProtocol.robot_ctr(0x01);
            }
        }

        private void ActionStop()
        {
            amPlaying = false;
            myPlayTime = 0;
            backgroundWorker1.CancelAsync();
            robotProtocol.robot_ctr(0x02);
        }

        private void backgroundWorker1_DoWork(object sender, DoWorkEventArgs e)
        {
            Stopwatch sw = new Stopwatch();List<byte> data = new List<byte>();
            for (int i = 1; i < myActions[mySelectedAction].KeyFrames.Count; i++){
                userReset.WaitOne();//支持暂停
                sw.Reset();
                sw.Start();
                float time = 0, pau = 0;
                data.Clear();                    
                for (int j = 0; j < 15; j++)
                {
                    int k = Num2Model(j);
                    short d = (short)(myActions[mySelectedAction].KeyFrames[i][k] * myRobot[k].Proportion * 4095 / 270 + myRobot[k].Zero);
                    data.Add((byte)(d >> 8));
                    data.Add((byte)(d));
                }
                //运动时间
                time = myActions[mySelectedAction].KeyFrames[i].Duration;//ms
                pau = myActions[mySelectedAction].KeyFrames[i].Pause;
                ushort t = (ushort)time;
                data.Add((byte)(t >> 8));
                data.Add((byte)t);
                if (follow){
                    //robotProtocol.SetJointAngle(data);//运动
                }                    
                //等待时间
                while (sw.Elapsed.TotalMilliseconds < time + pau){
                    System.Threading.Thread.Sleep(TimeSpan.FromMilliseconds(1));
                    //System.Threading.Thread.Sleep(TimeSpan.FromMilliseconds(100));                        
                    // 取消操作
                    if (backgroundWorker1.CancellationPending){
                        i = myActions[mySelectedAction].KeyFrames.Count;
                        break;
                    }
                }
            }
        }

        private void backgroundWorker1_ProgressChanged(object sender, System.ComponentModel.ProgressChangedEventArgs e)
        {

        }

        private void backgroundWorker1_RunWorkerCompleted(object sender, System.ComponentModel.RunWorkerCompletedEventArgs e)
        {
            
        }

        #endregion

        #region UI 帧列表操作----------------------------->

        private void lbInfos_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            mySelectedFrame = 0;
            if (lbInfos.Items.Count > 0){
                mySelectedFrame = lbInfos.SelectedIndex;

                if (!reflash)     // 机器人3d视图动作同步           
                    myRobot.SetFrame(myActions[mySelectedAction].KeyFrames[mySelectedFrame]);

                // 执行时间与等待时间显示
                runTime_tb.Text = myActions[mySelectedAction].KeyFrames[mySelectedFrame].Duration.ToString();
                dealyTime_tb.Text = myActions[mySelectedAction].KeyFrames[mySelectedFrame].Pause.ToString();
            }
        }

        /// <summary>
        /// 更新姿态
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnChangePose_Click(object sender, RoutedEventArgs e)
        {
            if (actionLt.SelectedItems.Count > 0 && mySelectedFrame != -1){
                Frame tempframe = new Frame(myRobot.Count);
                tempframe.SetSnapShot(Fluorite.Screenshot());
                myRobot.GetFrame(tempframe);
                tempframe.Duration = int.Parse(runTime_tb.Text);
                tempframe.Pause = int.Parse(dealyTime_tb.Text);
                myActions[mySelectedAction].KeyFrames[mySelectedFrame] = tempframe;
                // 更新
                UpdateFrameList(myActions[mySelectedAction]);
            }
        }

        /// <summary>
        /// 新增最后
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnNewPoseEnd_Click(object sender, RoutedEventArgs e)
        {
            if (actionLt.SelectedItems.Count > 0 ){
                // 机器人当前姿态创建一帧
                Frame tempframe = new Frame(myRobot.Count);
                tempframe.SetSnapShot(Fluorite.Screenshot());
                tempframe.Duration = int.Parse(runTime_tb.Text);
                tempframe.Pause = int.Parse(dealyTime_tb.Text);
                myRobot.GetFrame(tempframe);
                // 动作集中对应动作添加此帧
                myActions[mySelectedAction].KeyFrames.Add(tempframe);
                // 帧画板中在尾部添加一帧
                AddFrameToFrameList(tempframe);
            }
        }
        /// <summary>
        /// 新增在前
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnInsertPoseBefore_Click(object sender, RoutedEventArgs e)
        {
            if (actionLt.SelectedItems.Count > 0 && mySelectedFrame != -1){
                // 机器人当前姿态创建一帧
                Frame tempframe = new Frame(myRobot.Count);
                tempframe.SetSnapShot(Fluorite.Screenshot());
                tempframe.Duration = int.Parse(runTime_tb.Text);
                tempframe.Pause = int.Parse(dealyTime_tb.Text);
                myRobot.GetFrame(tempframe);
                // 动作集中对应动作插入此帧
                myActions[mySelectedAction].KeyFrames.Insert(mySelectedFrame,tempframe);
                // 在指定位置插入
                InsertFrameToFrameList(mySelectedFrame, tempframe);
                // 更新
                UpdateFrameList(myActions[mySelectedAction]);
            }
        }

        /// <summary>
        /// 新增在后
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnInsertPoseAfter_Click(object sender, RoutedEventArgs e)
        {
            if (actionLt.SelectedItems.Count > 0 && mySelectedFrame != -1){
                // 机器人当前姿态创建一帧
                Frame tempframe = new Frame(myRobot.Count);
                tempframe.SetSnapShot(Fluorite.Screenshot());
                tempframe.Duration = int.Parse(runTime_tb.Text);
                tempframe.Pause = int.Parse(dealyTime_tb.Text);
                myRobot.GetFrame(tempframe);
                // 动作集中对应动作插入此帧
                myActions[mySelectedAction].KeyFrames.Insert(mySelectedFrame + 1, tempframe);
                // 在指定位置插入
                InsertFrameToFrameList(mySelectedFrame + 1, tempframe);
                // 更新
                UpdateFrameList(myActions[mySelectedAction]);
            }
        }

        /// <summary>
        /// 删除选中
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnDeletePose_Click(object sender, RoutedEventArgs e)
        {
            if (actionLt.SelectedItems.Count >0 && mySelectedFrame !=-1){
                // 动作集中移除
                myActions[mySelectedAction].KeyFrames.RemoveAt(mySelectedFrame);
                // 帧列表中移除
                DelFrameFromFrameList(mySelectedFrame);
                // 更新
                UpdateFrameList(myActions[mySelectedAction]);
            }
        }

        /// <summary>
        /// 全部删除
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnDeleteAllPose_Click(object sender, RoutedEventArgs e)
        {
            if (actionLt.SelectedItems.Count > 0 ){
                mySelectedFrame = 0;
                // 动作集中移除
                myActions[mySelectedAction].KeyFrames.Clear();
                // 帧列表中移除
                DelAllFrameFromFrameList();
            }
        }
        /// <summary>
        /// 向前移动当前帧
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnForwardPose_Click(object sender, RoutedEventArgs e)
        {
            if (actionLt.SelectedItems.Count > 0 && mySelectedFrame != -1 && mySelectedFrame>0 && mySelectedFrame < myActions[mySelectedAction].KeyFrames.Count)
            {
                // 机器人当前帧
                Frame tempframe = myActions[mySelectedAction].KeyFrames[mySelectedFrame].Clone();
                // 动作集中对应动作插入此帧
                myActions[mySelectedAction].KeyFrames.Reverse(mySelectedFrame - 1,2);
                // 在指定位置反转
                ReverseFrameToFrameList(mySelectedFrame-1, tempframe);
                // 更新
                UpdateFrameList(myActions[mySelectedAction]);
            }
        }
        /// <summary>
        /// 向后移动当前帧
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnBackwardPose_Click(object sender, RoutedEventArgs e)
        {

        }
        #endregion

        #region 帧列表基本操作-------------------------->
        /// <summary>
        /// 更新帧列表
        /// </summary>
        /// <param name="actions">动作集合</param>
        private void UpdateFrameList(Action action)
        {
            lbInfos.Items.Clear();            
            foreach (Frame f in action.KeyFrames)
            {
                AddFrameToFrameList(f);
            }
        }
        
        /// <summary>
        /// 添加一帧动作
        /// </summary>
        /// <param name="tempframe"></param>
        private void AddFrameToFrameList(Frame tempframe)
        {            
            lbInfos.Items.Add(new
            {
                thumbnail = BitmapToBitmapImage(tempframe.SnapShot),
                Index = lbInfos.Items.Count.ToString(),
                Time = tempframe.Duration.ToString(),
                Pause = tempframe.Pause
            });
        }

        /// <summary>
        /// 移除某一帧
        /// </summary>
        /// <param name="index">索引编号</param>
        private void DelFrameFromFrameList(int index)
        {
            lbInfos.Items.RemoveAt(index);
        }
        
        /// <summary>
        /// 移除所有帧
        /// </summary>
        /// <param name="index"></param>
        private void DelAllFrameFromFrameList()
        {
            lbInfos.Items.Clear();
        }

        /// <summary>
        /// 在指定索引处插入一帧
        /// </summary>
        /// <param name="tempframe"></param>
        /// <param name="index">指定索引</param>
        private void InsertFrameToFrameList(int index, Frame tempframe)
        {
            lbInfos.Items.Insert(index,
            new
            {
                thumbnail = BitmapToBitmapImage(tempframe.SnapShot),
                Index = index.ToString(),
                Time = tempframe.Duration.ToString(),
                Pause = tempframe.Pause.ToString()
            });             
        }


        
        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            /*
            amCapturing = !amCapturing;
            if(amCapturing)
            {
                for (int t = 0; t < myRobot.Count; t++)
                    myRobot[t].Angle = myRobot[t].AngleLimitA;
                myViewX = float.Parse(ViewXText.Text);
                myViewY = float.Parse(ViewYText.Text);
                myViewZ = float.Parse(ViewZText.Text);
                myCaptureDelta = float.Parse(DeltaText.Text);
                if (myAngleBuilder == null)
                    myAngleBuilder = new StringBuilder();
            }
            */
        }


        private void WindowsFormsHost_ChildChanged(object sender, System.Windows.Forms.Integration.ChildChangedEventArgs e)
        {

        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Bitmap shot = Fluorite.Screenshot();
            shot.Save($"{Environment.CurrentDirectory}\\sc.png", System.Drawing.Imaging.ImageFormat.Png);
            shot.Dispose();
        }



        /// <summary>
        /// 翻转指定索引处开始的两个帧
        /// </summary>
        /// <param name="index"></param>
        /// <param name="tempframe">被选中帧</param>
        private void ReverseFrameToFrameList(int index, Frame tempframe)
        {
            lbInfos.Items.Insert(index, new
            {
                thumbnail = BitmapToBitmapImage(tempframe.SnapShot),
                Index = index.ToString(),
                Time = tempframe.Duration.ToString(),
                Pause = tempframe.Pause.ToString()
            }); 
            lbInfos.Items.RemoveAt(index + 1);            
        }
        #endregion

        /// <summary>
        /// Bitmap --> BitmapImage
        /// </summary>
        /// <param name="bitmap"></param>
        /// <returns></returns>
        /// https://blog.csdn.net/wangshubo1989/article/details/47296339
        public static BitmapImage BitmapToBitmapImage(Bitmap bitmap)
        {
            using (MemoryStream stream = new MemoryStream())
            {
                // 坑点:参考代码 bitmap.Save(ms, bitmap.RawFormat);有问题，总报异常
                bitmap.Save(stream, System.Drawing.Imaging.ImageFormat.Png);
                stream.Position = 0;
                BitmapImage result = new BitmapImage();
                result.BeginInit();
                result.CacheOption = BitmapCacheOption.OnLoad;
                result.StreamSource = stream;
                result.EndInit();
                result.Freeze();
                return result;
            }
        }
        
        private void viewInitialize()
        {
            myViewZ = 800F;
            myViewX = 0F; // 经度 -pi,pi
            //myViewY = (float)(Math.PI) / 5F; // 纬度 -pi/2,pi/2
            myViewY = 0F;
            myViewPos = myRobot.UpdatedCenter;
            mySun = new SunLight(Vector3.UnitY, Color.White);
            myWheelReady = false;
            myViewMouse = ViewMouseEnum.Select;
        }




        /// <summary>
        /// 引擎加载事件处理
        /// </summary>
        private void Fluorite_Load()
        {
            Fluorite.ResourcePath = System.Windows.Forms.Application.StartupPath + "\\Res";
            Fluorite.UsingLight = true;
            myRobot = new Robot("\\fangfang.x", path + "\\Robots\\FangFangRobot.txt");
            updateCfg(myRobot);   //更新机器人的参数
            myPoint = Fluorite.Geometries.CreateSphere(1);
            mySkyPic = new Picture("sky.jpg", true);//此处略作修改、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、
            mySky = new XModel("sky.x");            
            myGround = new XModel("ground.x");
            myRobot.Update();
            frameBitmap = new Bitmap(120, 120, System.Drawing.Imaging.PixelFormat.Format32bppArgb);
            frameCathe = Graphics.FromImage(frameBitmap);
            myRobotPic = new Picture(Color.White);
            myHighLightPic = new Picture(Color.FromArgb(32, 32, 32));
            mySelectedPic = new Picture("spark.png");
            myUpPic = new Picture("up.png");
            myUpPressedPic = new Picture("uppressed.png");
            myDownPic = new Picture("down.png");
            myDownPressedPic = new Picture("downpressed.png");
            myGroundPic = new Picture("ground.png", true);
            mySelectedAni = new Animate(mySelectedPic, FrameCountEnum.SixtyFour);
            myLayer = new Layer();
            myWritting = new Writting("宋体", 11,System.Drawing.FontStyle.Bold);

            myBlackPic = new Picture(Color.Black);
            myWhitePic = new Picture(Color.White);

            viewInitialize();
            /////////////////////////////此处是为了截屏
            amCapturing = true;
            if (amCapturing)
            {
                //for (int t = 0; t < myRobot.Count; t++)
                //myRobot[t].Angle = myRobot[t].AngleLimitA;//AngleLimitA为当前骨骼旋转角度的下限，AngleLimitB为当前骨骼旋转角度的上限
                myViewX = float.Parse(ViewXText.Text);
                myViewY = float.Parse(ViewYText.Text);
                myViewZ = float.Parse(ViewZText.Text);
                myCaptureDelta = float.Parse(DeltaText.Text);
                if (myAngleBuilder == null)
                    myAngleBuilder = new StringBuilder();
            }
        }



        //自定义函数
        int ChangeAngle(int Transform)
        {
            //从上面程序复制过来的
            float tmpdd = 0F, tmpee = float.MaxValue;//MaxValue = 3.40282347E+38F;//此处把源程序中的局部变量tmpd/tmpe改写的成了tmpdd和tmpee
            int tmpi = Transform;

            myRobot[Transform].Angle += 10;//自己加

            if (myRobot[Transform].Angle > 100)
            {
                myRobot[Transform].Angle = 100;
            }

            Thread.Sleep(1 * 500);


            // 判断被选模型号
            for (int t = 0; t < myRobot.Count; t++)
            {
                int tmpt = (Transform + t) % myRobot.Count;//tmpt=0、2/4/6/8/10/12、1、3/5/7/9/11

                if (myRobot.UpdatedModel.Intersects(myMouseRay, myRobot[tmpt].Subset, ref tmpdd) && tmpdd < tmpee)
                {
                    tmpee = tmpdd;
                    tmpi = tmpt;
                }
            }
            return tmpi;
            //到这呢
        }

        //程序会一直在此处旋转
        //自定义角
        /*
        private void SelfAddAngle_Eight(int myIndexone)
        {
            myRobot[myIndexone].Angle += 20;
            if (myRobot[myIndexone].Angle > 240) { Charone += 1;myRobot[myIndexone].Angle = 0; }
        
        }
        private void SelfAddAngle_Nine(int myIndexone, int Charzero)
        {
            myRobot[myIndexone].Angle = 20* Charzero;
            if (myRobot[myIndexone].Angle > 150) { CharTen += 1; Charone = 0; myRobot[myIndexone].Angle = 0; }
        }
        private void SelfAddAngle_Ten(int myIndexone, int Chartwo)
        {
            myRobot[myIndexone].Angle = 20 * Chartwo;
            if (myRobot[myIndexone].Angle > 100) { CharTen = 0; myRobot[myIndexone].Angle = 100; }
        }
        */
        private void SelfAddAngle_Eight(int myIndexone)
        {
            myRobot[myIndexone].Angle += 10;
            if (myRobot[myIndexone].Angle > 240) { Charone += 1; myRobot[myIndexone].Angle = 0; }
        }
        private void SelfAddAngle_Nine(int myIndexone, int Charzero)
        {
            myRobot[myIndexone].Angle = 10 * Charzero;
            if (myRobot[myIndexone].Angle > 150) { CharTen += 1; Charone = 0; myRobot[myIndexone].Angle = 0; }
        }
        private void SelfAddAngle_Ten(int myIndexone, int Chartwo)
        {
            myRobot[myIndexone].Angle = 10 * Chartwo;
            if (myRobot[myIndexone].Angle > 100) { CharTen = 0; myRobot[myIndexone].Angle = 100; }
        }
        /// <summary>
        /// 引擎渲染事件
        /// </summary>
        /// <param name="Time"></param>
        private void Fluorite_Render(float Time)
        {

            C = (C + 1) % 64;
            Fluorite.Cls(System.Drawing.Color.CadetBlue);
            Fluorite.SetCamera(myViewPos, myViewX, myViewY, myViewZ);
            mySun.Direction = Fluorite.CameraDirect;
            Fluorite.SetColor(Color.White, Color.White);
            Fluorite.SetFogDisabled();
            if (amCapturing)
                myBlackPic.SelectAsTexture();
            else
                mySkyPic.SelectAsTexture();
            mySky.Draw(new Vector3(Fluorite.CameraPosition.X, 0, Fluorite.CameraPosition.Z), 0F, 500);
            if(amCapturing)
                Fluorite.SetColor(Color.Red, Color.Red);////////////////////////////////我把White换成了Red
            else
                Fluorite.SetColor(Color.FromArgb(167, 53, 32), Color.FromArgb(156, 123, 77), Color.FromArgb(206, 207, 158), 15);//粗糙
            Fluorite.SetCamera(myViewPos, myViewX, myViewY, myViewZ);


            //从上面程序复制过来的
            //mySelectedIndex = ChangeAngle(mySelectedIndex);
            //到这呢

            if (myRobot != null)
            {
                if (amPlaying){
                    myRobot.SetFrame(myActions[mySelectedAction].LerpFrame(myPlayTime * 1000));
                    if (!amPaused){
                        myPlayTime += Time - lastTime;
                        if (myPlayTime * 1000 > myActions[mySelectedAction].Duration){
                            amPlaying = false;
                            myPlayTime = 0;
                            myRobot.SetFrame(myActions[mySelectedAction].KeyFrames[myActions[mySelectedAction].KeyFrames.Count - 1]);
                        }
                    }
                }
                if (myViewMouse == ViewMouseEnum.Select){
                    myMouseRay = new Ray(Fluorite.CameraPosition,
                    Vector3.Normalize(Fluorite.Mathmatics.UnprojectVector3FromScreen(myMousePos, 1) - Fluorite.CameraPosition));
                    float tmpd = 0F, tmpe = float.MaxValue;
                    bool tmpb = false;
                    for (int t = 0; t < myRobot.Count; t++){
                        int tmpt = (mySelectedIndex + t) % myRobot.Count;
                        if (myRobot.UpdatedModel.Intersects(myMouseRay, myRobot[tmpt].Subset, ref tmpd) && tmpd < tmpe){
                            tmpb = true;
                            tmpe = tmpd; 
                            if (myMouseButton == 0){
                                myHilightIndex = tmpt;
                            }
                        }
                    }
                    if (tmpb)
                    {
                        myPoint.Draw(myMouseRay.Position + myMouseRay.Direction * tmpd);
                    }
                }
         
                if (amCapturing)
                {
                    myAngleBuilder.Clear();
                    myAngleBuilder.Append("ff");
                    for (int t = 0; t < myRobot.Count; t++)
                    {
                        myAngleBuilder.Append(",");
                        myAngleBuilder.Append(myRobot[t].Angle.ToString("000;000"));//把+000;-000换为000;000
                    }
                    Bitmap a = Fluorite.Screenshot();
                    a.Save($"{System.Windows.Forms.Application.StartupPath}\\Png\\{myAngleBuilder.ToString()}.png", System.Drawing.Imaging.ImageFormat.Png);
                    a.Dispose();
                    /*
                    for (int t = 0; t < myRobot.Count; t++)
                    {
                        if (myRobot[t].Angle >= myRobot[t].AngleLimitB)
                        {
                            myRobot[t].Angle = myRobot[t].AngleLimitA;
                            if (t == myRobot.Count - 1)
                                amCapturing = false;
                        }
                        else
                        {
                            myRobot[t].Angle += myCaptureDelta;
                            break;
                        }
                    }
                    */
                }
                // 足部着地
                Align();
                myRobot.Update();
                Fluorite.SetStageOperation(0, StageOperation.Default);
                Fluorite.SetStageOperation(1, StageOperation.Add);
                Fluorite.SetStageOperation(2, StageOperation.End);



                for (int t = 0; t < myRobot.Count; t++){
                    if (mySelectedIndex == t)
                        mySelectedAni.get_Frame(C).SelectAsTexture(1);
                    else if (myHilightIndex == t)
                        myHighLightPic.SelectAsTexture(1);
                    else
                        Picture.DeselectTexture(1);

                    if (amCapturing)
                    {
                        Picture.DeselectTexture(1);
                        myWhitePic.SelectAsTexture();
                    }
                    else
                        myRobot[t].Pic.SelectAsTexture();
                    myRobot.Draw(t);//此处可画出各关节////////////////////////
                }


                Picture.DeselectTexture(1);
                if (!amCapturing)
                {
                    Fluorite.SetColor(Color.White, Color.White);
                    myGroundPic.SelectAsTexture();
                    myGround.Draw(Matrix.Scaling(5, 5, 5) * Matrix.Translation(0, myRobot.Ground, 100));
                    myGround.Draw(Matrix.Scaling(5, 5, 5) * Matrix.RotationX(3.1416F) * Matrix.Translation(0, myRobot.Ground, 100));
                    // 新层绘制角度
                    // 留作绘制机器人提示信息

                    myLayer.BeginPaint();
                    //Vector3 tmpv = Fluorite.Mathmatics.ProjectVector3ToScreen(myRobot[mySelectedIndex].UpdatedPosition);
                    myWritting.Say(batInf, 0, 0, Color.Red);//"机器人电量：80%"
                    /*
                    myWritting.Say("选中" + myRobot[mySelectedIndex].Name + "角度: " + myRobot[mySelectedIndex].Angle.ToString("0.##"), 0, 30, Color.Black);
                    for (int i = 1; i <= 13; i++)///////未执行
                    {
                        int k = ID2Model(i);
                        myWritting.Say(myRobot[k].Name, 0, 150 + i * 20, Color.Black);
                        myWritting.Say("舵机值 " + currentPosition[i].ToString("0.##"), 80, 150 + i * 20, Color.Blue);
                        //myWritting.Say("关节角 " + ((currentPosition[i] - myRobot[k].Zero) * 270f / 4095 * myRobot[k].Proportion).ToString("0.##"),80, 150 + (i - 1) * 20, Color.Red);
                    }
                   */
                    myLayer.EndPaint();
                }
                else
                {
                    myLayer.BeginPaint();
                    myAngleBuilder.Clear();
                    /*
                    myAngleBuilder.Append("ff");
                    for(int t=0; t<myRobot.Count; t++)
                    {
                        myAngleBuilder.Append("_");
                        myAngleBuilder.Append(myRobot[t].Angle.ToString("+000;-000"));
                    }
                    */
                    myWritting.Say(myAngleBuilder.ToString(), 0, 0, Color.White);
                    myLayer.EndPaint();
                 
                }
            //
            ToBitmapTool.ToBitmap(rootPanel, 400, 600, 200, 600);//相当重要
            //
            lastTime = Time;
            if (mySelectedIndex <= 13)
            {
                
                if (mySelectedIndex == 7)
                {
                    mySelectedIndex = 8;
                }

                    switch (mySelectedIndex)
                    {
                        case 0: myRobot[mySelectedIndex].Angle = 180; break;
                        case 1: myRobot[mySelectedIndex].Angle = 90; break;
                        case 2: myRobot[mySelectedIndex].Angle = 0; break;
                        case 3: myRobot[mySelectedIndex].Angle = 180; break;
                        case 4: myRobot[mySelectedIndex].Angle = 180; break;
                        case 5: myRobot[mySelectedIndex].Angle = 90; break;
                        case 6: myRobot[mySelectedIndex].Angle = 90; break;
                        //case 8: SelfAddAngle_Eight(mySelectedIndex); break;
                        //case 9: SelfAddAngle_Nine(mySelectedIndex, Charone); break;
                        //case 10: SelfAddAngle_Ten(mySelectedIndex,CharTen); break;
                        case 10: SelfAddAngle_Ten(mySelectedIndex, CharTen); break;
                        case 9: SelfAddAngle_Nine(mySelectedIndex, Charone); break;
                        case 8: SelfAddAngle_Eight(mySelectedIndex); break;
                        case 11: myRobot[mySelectedIndex].Angle = 180; break;
                        case 12: myRobot[mySelectedIndex].Angle = 180; break;
                        case 13: myRobot[mySelectedIndex].Angle = 90; break;

                    }
                    mySelectedIndex = mySelectedIndex + 1;
                }
                else { mySelectedIndex = 0; }
                
            }
            /*
            private void SelfAddAngle_Eight(int myIndexone)
            {
                myRobot[myIndexone].Angle += 20;
                if (myRobot[myIndexone].Angle > 240) { Charone += 1; myRobot[myIndexone].Angle = 0; }

            }
            private void SelfAddAngle_Nine(int myIndexone, int Charzero)
            {
                myRobot[myIndexone].Angle = 20 * Charzero;
                if (myRobot[myIndexone].Angle > 150) { CharTen += 1; Charone = 0; myRobot[myIndexone].Angle = 0; }
            }
            private void SelfAddAngle_Ten(int myIndexone, int Chartwo)
            {
                myRobot[myIndexone].Angle = 20 * Chartwo;
                if (myRobot[myIndexone].Angle > 100) { CharTen = 0; myRobot[myIndexone].Angle = 100; }
            }
            */

        }

        public void Align()
        {
            switch (myViewAlign)
            {
                case ViewAlignEnum.LeftFoot:
                    myRobot.Align("左脚", Vector3.UnitY);
                    break;
                case ViewAlignEnum.RightFoot:
                    myRobot.Align("右脚", Vector3.UnitY);
                    break;
                case ViewAlignEnum.TwoFeet:
                    myRobot.Align2("左脚", "右脚", Vector3.UnitY);
                    break;
            }
        }

        //-------------------------ID映射------------------------->      
        private int Num2Model(int x)
        { 
                                   //0  1  2  3  4   5  6  7  8  9  10  11  12  13 14  
            int[] data = new int[] { 6, 2, 1, 0, 10, 9, 8, 3, 4, 5, 11, 12, 13, 7, 15};
            return data[x];
        }
        /// <summary>
        /// 模型编号转换为舵机ID
        /// </summary>
        /// <param name="x"></param>
        /// <returns></returns>
        private int Model2ID(int x)
        {                          //0  1  2  3  4  5   6  7   8  9  10 11  12  13  14 15 
            int[] data = new int[] { 4, 3, 2, 8, 9, 10, 1, 15, 7, 6, 5, 11, 12, 13, 0, 14};
            return data[x];
        }
        /// <summary>
        /// 将机器人实体舵机编号转换为机器人模型编号
        /// </summary>
        /// <param name="x"></param>
        /// <returns></returns>
        private int ID2Model(int x)// 0<->躯体
        {                          // 0  1  2  3  4   5  6  7  8  9  10 11  12  13  14 15                    
            int[] data = new int[] { 14, 6, 2, 1, 0, 10, 9, 8, 3, 4, 5, 11, 12, 13, 15, 7 };
            return data[x];
        }
    }

    public static class FindChirldHelper
    {
        public static List<T> FindVisualChild<T>(DependencyObject obj) where T : DependencyObject
        {
            try{
                List<T> TList = new List<T> { };
                for (int i = 0; i < System.Windows.Media.VisualTreeHelper.GetChildrenCount(obj); i++){
                    DependencyObject child = System.Windows.Media.VisualTreeHelper.GetChild(obj, i);
                    if (child != null && child is T){
                        TList.Add((T)child);
                        List<T> childOfChildren = FindVisualChild<T>(child);
                        if (childOfChildren != null){
                            TList.AddRange(childOfChildren);
                        }
                    }
                    else{
                        List<T> childOfChildren = FindVisualChild<T>(child);
                        if (childOfChildren != null){
                            TList.AddRange(childOfChildren);
                        }
                    }
                }
                return TList;
            }
            catch (Exception)
            {
                return null;
            }
        }
    }
}
