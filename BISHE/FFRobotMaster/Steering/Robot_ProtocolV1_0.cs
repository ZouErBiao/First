using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.IO.Ports;
using System.Runtime.InteropServices;
using System.Diagnostics;
using System.Threading;

namespace FFRobotMaster
{
    class Robot_ProtocolV1_0
    {
        //===========================================================================================
        // 常量
        //===========================================================================================
        public const string version = "v1.5X";
        /// <summary>
        /// 指令标识表
        /// </summary>
        public enum DATAID : ushort
        {
            // 机器人信息
            ADDR = 0X0201,
            TYPE = 0X0202,
            SOFTWAREVER = 0X0204,
            HARDWAREVER = 0X0205,
            // 透传数据
            TRANSMISSION_STEER = 0X0301,
            // 文件下载
            DOWNLOAD_ACTION = 0X0500,
            DOWNLOAD_MODE = 0X0501,
            ACTION_INF = 0X0502,
            ACTION_BAG = 0X0503,
            DOWNLOAD_FIN = 0X0504,
            // 文件上载
            GET_ACTIONCOUNT = 0X0601,
            GET_ACTIONNAME = 0X0602,
            // 控制
            RUNACTION = 0X0701,
            CONTROL = 0X0702,
            DELACTION = 0X0703,
            WHEEL=0X0704,
            BROADCASTRUN= 0X0705,
            // 传感器
            GET_VOLTAGE = 0X0801,
            GET_ANGLE = 0X0802,
            GET_LOAD = 0X0803,
            SET_ANGLE = 0X0804,
            SET_JOINTTORQUE = 0X0805,
            SET_JOINTZEROADJUST = 0X0806,
        }
        public enum CCODE
        {
            MNW = 0x02,//主站发送无异常写
            MNR = 0x01,//主站发送无异常读

            SNW = 0x82,//从站发送无异常写
            SNR = 0x81,//从站发送无异常读

            SEW = 0xC2,//从站发送有异常写
            SER = 0xC1 //从站发送有异常读
        }
        //===========================================================================================
        // 公共变量
        //===========================================================================================
        public SerialPort com = new SerialPort();
        public List<byte> sendList = new List<byte>();
        /// <summary>
        /// 指令执行队列
        /// </summary>
        public Queue<exccmd> excuQueue = new Queue<exccmd>();
        /// <summary>
        /// 串口接收缓冲线性表
        /// </summary>
        public static List<byte> recBufList = new List<byte>();
        public protocolFrame recPFrame;

        public class exccmd
        {
            public DATAID dataId;
            public CCODE cCode;
            public List<byte> data;

            public exccmd(DATAID id, CCODE cCode, List<byte> data)
            {
                this.dataId = id;
                this.cCode = cCode;
                this.data = data;
            }
        }

        /// <summary>
        /// 数据更新事件
        /// </summary>
        /// <param name="index"></param>
        public delegate void SteerDataUpdateEventHandler(DATAID dataId, List<byte> data);
        public event SteerDataUpdateEventHandler SteerDataUpdate;
        /// <summary>
        /// 出错报告
        /// </summary>
        /// <param name="msg"></param>
        public delegate void reportErrorEventHandler(string msg);
        public event reportErrorEventHandler reportError;

        //===========================================================================================
        // 基本操作
        //===========================================================================================
        //----------------------------------------------------------------------------------------
        // 机器人信息
        //----------------------------------------------------------------------------------------
        public void GetRobotAddr()
        {
            excuQueue.Enqueue(new exccmd(DATAID.ADDR, CCODE.MNR, new List<byte>()));
        }
        public void GetRobotType()
        {
            excuQueue.Enqueue(new exccmd(DATAID.TYPE, CCODE.MNR, new List<byte>()));
        }
        //----------------------------------------------------------------------------------------
        // 数据透传
        //----------------------------------------------------------------------------------------
        public void TransmissionSteer()
        {

        }
        //----------------------------------------------------------------------------------------
        // 无线配置
        //----------------------------------------------------------------------------------------
        public void BluetoothConfig()
        {

        }
        public void ZigBeeConfig()
        {

        }
        //----------------------------------------------------------------------------------------
        // 文件下载
        //----------------------------------------------------------------------------------------
        public void DownLoadAction(int num)//(string name)
        {
            // 准备好动作数据
            //ActionTxt2HexTxt(num);//测试，用于生成动作文件
            //ActionTxt2Hex(name);
            //ActionTxt2Hex(num);// 实际下载
            //excuQueue.Enqueue(new exccmd(DATAID.DOWNLOAD_MODE, CCODE.MNW, new List<byte>()));                    
        }
        //----------------------------------------------------------------------------------------
        // 文件上载
        //----------------------------------------------------------------------------------------
        //----------------------------------------------------------------------------------------
        // 控制
        //----------------------------------------------------------------------------------------
        /// <summary>
        /// 执行指定动作文件
        /// </summary>
        /// <param name="data">动作名ANSI格式</param>
        public void RunAction(List<byte> data)//输入动作名，动作名是16B ANSI格式汉字
        {
            excuQueue.Enqueue(new exccmd(DATAID.RUNACTION, CCODE.MNW, data));
        }
        /// <summary>
        /// 机器人控制
        /// </summary>
        /// <param name="data">0x01停止/0x02暂停/0x03继续</param>
        public void RobotControl(List<byte> data)
        {
            excuQueue.Enqueue(new exccmd(DATAID.CONTROL, CCODE.MNW, data));
        }
        /// <summary>
        /// 删除某个动作文件
        /// </summary>
        /// <param name="data">动作名ANSI格式</param>
        public void DelAction(List<byte> data)
        {
            excuQueue.Enqueue(new exccmd(DATAID.DELACTION, CCODE.MNW, data));
        }
        /// <summary>
        /// 机器人轮子控制
        /// </summary>
        /// <param name="data">
        /// data[0]左侧轮子 data[1]右侧轮子
        /// 0-99 正转 100-199 反转
        /// </param>
        public void WheelControl(List<byte> data)
        {
            excuQueue.Enqueue(new exccmd(DATAID.WHEEL, CCODE.MNW, data));
        }

        public void BroadcastRunAction(List<byte> data)
        {
            excuQueue.Enqueue(new exccmd(DATAID.BROADCASTRUN, CCODE.MNW, data));
        }
        //----------------------------------------------------------------------------------------
        //  传感器
        //----------------------------------------------------------------------------------------
        /// <summary>
        /// 获取机器人关节角度
        /// </summary>
        /// <param name="data">关节编号</param>
        public void GetJointAngle(List<byte> data)
        {
            excuQueue.Enqueue(new exccmd(DATAID.GET_ANGLE, CCODE.MNR, data));
        }
        /// <summary>
        /// 设置机器人关节角
        /// </summary>
        /// <param name="data">关节编号+关节数据</param>
        public void SetJointAngle(List<byte> data)
        {
            excuQueue.Enqueue(new exccmd(DATAID.SET_ANGLE, CCODE.MNW, data));
        }
        public void GetRobotVoltage()
        {
            excuQueue.Enqueue(new exccmd(DATAID.GET_VOLTAGE, CCODE.MNR, new List<byte>()));
        }
        /// <summary>
        /// 获取机器人关节负载
        /// </summary>
        /// <param name="data">关节编号</param>
        public void GetJointLoad(List<byte> data)
        {
            excuQueue.Enqueue(new exccmd(DATAID.GET_LOAD, CCODE.MNR, data));
        }
        /// <summary>
        /// 释放关节扭力/恢复关节扭力
        /// </summary>
        /// <param name="data"></param>
        public void SetJointTorque(List<byte> data)
        {
            excuQueue.Enqueue(new exccmd(DATAID.SET_JOINTTORQUE, CCODE.MNW, data));
        }
        /// <summary>
        /// 设置机器人原点偏移量
        /// </summary>
        /// <param name="data"></param>
        public void SetJointZeroAdjust(List<byte> data)
        {
            excuQueue.Enqueue(new exccmd(DATAID.SET_JOINTZEROADJUST, CCODE.MNW, data));
        }
        /// <summary>
        /// 获取机器人原点偏移数值
        /// </summary>
        /// <param name="data"></param>
        public void GetJointZeroAdjust(List<byte> data)
        {
            excuQueue.Enqueue(new exccmd(DATAID.SET_JOINTZEROADJUST, CCODE.MNR, data));
        }
        //===========================================================================================
        // 通信线程
        //===========================================================================================
        // 发送处理线程
        private Thread sendThread;
        // 接收帧处理线程
        private Thread frameParse;
        // 超时判断线程
        private Thread timeoutJudge;
        // 收到完整返回帧标志
        public static bool frameFlag = false;
        // 链接状态
        public static bool connected;
        // 计时表
        public HashSet<DATAID> timeoutHashSet = new HashSet<DATAID>();
        //最大超时时间2000ms
        public long timeoutMax = 5000;//2秒

        public void StartCommunicationServe(string comName,int rate)
        {
            sendThread = new Thread(new ThreadStart(SendSub));
            frameParse = new Thread(new ThreadStart(FrameParseSub));
            timeoutJudge = new Thread(new ThreadStart(timeoutJudgeSub));
            sendThread.IsBackground = true;
            frameParse.IsBackground = true;
            timeoutJudge.IsBackground = true;            
            connected = true;
            try
            {
                com.PortName = comName;
                com.BaudRate = rate;
                com.Open();
                com.DataReceived += Com_DataReceived;
                reportError?.Invoke("串口打开成功！");
            }
            catch
            {
                reportError?.Invoke("串口打开异常！");
            }            
            sendThread.Start();
            frameParse.Start();
            timeoutJudge.Start();
        }
        public void StopCommunicationServe()
        {
            connected = false;
            timeoutJudge.Abort();
            sendThread.Abort();
            frameParse.Abort();
            try
            {
                com.Close();
                com.DataReceived -= Com_DataReceived;
                reportError?.Invoke("串口关闭成功！");
            }
            catch
            {
                reportError?.Invoke("串口打开异常！");
            }                        
        }
        /// <summary>
        /// 发送线程
        /// </summary>
        private void SendSub()
        {
            while (connected)
            {
                if (excuQueue.Count > 0)
                {
                    exccmd exccmd = excuQueue.Dequeue();
                    timeoutHashSet.Add(exccmd.dataId);//发送指令记录填入超时队列
                    SendProtocolFrame(0x01, exccmd.cCode, exccmd.dataId, exccmd.data);
                }
                Thread.Sleep(100);//最快间隔100ms
            }
        }
        /// <summary>
        /// 处理串口帧线程
        /// </summary>
        private void FrameParseSub()
        {
            while (connected)
            {
                if (frameFlag)
                {                    
                    frameFlag = false;
                    try
                    {
                        //帧解析与数据返回
                        timeoutHashSet.Remove(recPFrame.dataId);//去除
                        switch (recPFrame.dataId)
                        {
                            case DATAID.ADDR:
                                SteerDataUpdate(DATAID.ADDR, recPFrame.frameData);                                
                                break;
                            case DATAID.TYPE:
                                SteerDataUpdate(DATAID.TYPE, recPFrame.frameData);
                                break;
                            case DATAID.RUNACTION:
                                break;
                            case DATAID.CONTROL:
                                break;
                            case DATAID.DELACTION:
                                break;
                            case DATAID.WHEEL:
                                break;
                            case DATAID.BROADCASTRUN:
                                break;//
                            case DATAID.GET_VOLTAGE:
                                SteerDataUpdate(DATAID.GET_VOLTAGE, recPFrame.frameData);
                                break;
                            case DATAID.GET_ANGLE:
                                SteerDataUpdate(DATAID.GET_ANGLE, recPFrame.frameData);
                                break;
                            case DATAID.GET_LOAD:
                                SteerDataUpdate(DATAID.GET_LOAD, recPFrame.frameData);
                                break;
                            case DATAID.SET_ANGLE:
                                SteerDataUpdate(DATAID.SET_ANGLE, recPFrame.frameData);
                                break;
                            case DATAID.SET_JOINTTORQUE:
                                SteerDataUpdate(DATAID.SET_JOINTTORQUE, recPFrame.frameData);
                                break;
                            case DATAID.SET_JOINTZEROADJUST:
                                SteerDataUpdate(DATAID.SET_JOINTZEROADJUST, recPFrame.frameData);
                                break;
                            // 文件下载
                            case DATAID.DOWNLOAD_MODE:
                            case DATAID.ACTION_INF:
                            case DATAID.ACTION_BAG:
                            case DATAID.DOWNLOAD_FIN:
                                DownLoadAction(recPFrame.dataId,recPFrame.controlCode);
                                break;
                            default:
                                break;
                        }                        
                    }
                    catch(Exception ex)
                    {
                        reportError?.Invoke(ex.Message);
                    };
                }
                Thread.Sleep(10);//最快处理间隔10ms
            }
        }
        
        /// <summary>
        /// 超时判断线程
        /// </summary>
        private void timeoutJudgeSub()
        {
            //如果里面的项目在指定的超时时间内仍然没有被去除，则认为是超时了
            Stopwatch st = new Stopwatch();            
            while (connected)
            {
                // 还需要改
                if (timeoutHashSet.Count != 0)
                {
                    st.Start();//开始计时
                    if (st.ElapsedMilliseconds > timeoutMax)
                    {
                        StringBuilder str = new StringBuilder();
                        foreach (DATAID dataId in timeoutHashSet)
                        {
                            str.Append(dataId.ToString());
                        }
                        timeoutHashSet.Clear();//暂时用
                        reportError(str.ToString()+"请求超时！");
                    }
                    else
                    {
                        Thread.Sleep(10);
                        continue;
                    }
                }
                st.Reset();//重置并停止计时
                Thread.Sleep(10);//最快处理间隔100ms
            }
        }
        private void Com_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            // C# 串口一次收到数据大小不定，即使ReceivedBytesThreshold设置为1
            int frameLen=0;
            int len = com.BytesToRead;
            try
            {
                while (len-- != 0)
                {
                    recBufList.Add((byte)com.ReadByte());
                }
                if (recBufList.Count >= 6)//获取了长度数据
                {
                    if (recBufList[0] == 0X68 && recBufList[2] == 0x68)//stx1,stx2正确
                    {
                        frameLen = recBufList[5] << 8 | recBufList[4];
                    }
                    else
                    {
                        recBufList.Clear();
                        return;
                    }
                    if (recBufList.Count == frameLen + 8)//接收到完整帧
                    {
                        if (recBufList[recBufList.Count - 1] == 0x16)//是否收到帧结束符
                        {
                            recPFrame = new protocolFrame(
                                (byte)(recBufList[1]),
                                (CCODE)recBufList[3],
                                (DATAID)(recBufList[7] << 8 | recBufList[6]),
                                recBufList.GetRange(8, (ushort)frameLen));
                            recBufList.Clear();
                            frameFlag = true;
                            return;
                        }
                        else
                        {
                            recBufList.Clear();
                            reportError?.Invoke("帧结尾出错！");
                            return;
                        }
                    }
                    if (recBufList.Count > frameLen + 8)//超长度
                    {
                        recBufList.Clear();
                        return;
                    }
                }                
                return;
            }
            catch (TimeoutException ex)
            {
                recBufList.Clear();
                reportError?.Invoke(ex.Message);
            }
        }
        //===========================================================================================
        // 协议格式包装帧数据并发送
        //===========================================================================================
        public class protocolFrame
        {
            // 通信协议格式
            public byte stx1 = 0x68;
            public byte robotAddr;
            public byte stx2 = 0x68;
            public CCODE controlCode;
            public ushort dataLen = 0;
            public DATAID dataId;
            public List<byte> frameData;
            public byte cs;
            public byte eof = 0x16;

            // 发送数据流
            public byte[] sendBuf = new byte[1];
            public int frameLen;
            public protocolFrame(byte robotAddr, CCODE controlCode, DATAID dataId, List<byte> frameData)
            {
                this.robotAddr = robotAddr;
                this.controlCode = controlCode;
                this.dataLen = (ushort)(frameData.Count + 2);
                this.dataId = dataId;
                this.frameData = frameData;
                this.frameLen = 6 + dataLen + 2;
                sendBuf = new byte[frameLen];

                // 填充发送数据流
                sendBuf[0] = stx1;
                sendBuf[1] = (byte)(robotAddr);
                sendBuf[2] = stx2;
                sendBuf[3] = (byte)controlCode;
                sendBuf[4] = (byte)(dataLen);//先发低位
                sendBuf[5] = (byte)(dataLen>>8);
                sendBuf[6] = (byte)(dataId);//先发低位
                sendBuf[7] = (byte)((short)dataId>>8);
                frameData.CopyTo(0, sendBuf, 8, frameData.Count);                
                // 计算CS = ( A0 + A1 + ...+ Data ) % 256
                for (int i = 1; i < frameLen - 2; i++)
                {
                    sendBuf[frameLen - 2] += sendBuf[i];
                }
                sendBuf[frameLen - 1] = 0x16;
            }            
        }
        /// <summary>
        /// 创建一个通信协议帧并发送
        /// </summary>
        /// <param name="frameAddr"></param>
        /// <param name="controlCode"></param>
        /// <param name="frameData"></param>
        public void SendProtocolFrame(byte robotAddr, CCODE controlCode,DATAID dataId, List<byte> frameData)
        {
            protocolFrame pFrame = new protocolFrame(robotAddr, controlCode, dataId, frameData);
            // 帧数据通过串口发送
            com.Write(pFrame.sendBuf, 0, pFrame.frameLen);
        }
        //===========================================================================================
        // 舵机透传数据帧创建
        //===========================================================================================
        #region//舵机协议帧
        /// <summary>
        /// 创建读取舵机数据帧
        /// </summary>
        /// <param name="size"></param>
        /// <returns></returns>
        public List<byte> CreateReadSteerDataFrame(byte id, byte regAddr, byte size)
        {
            List<byte> repyData = new List<byte>();
            // 帧头
            repyData.Add(0xFF);
            repyData.Add(0xFF);
            // 目标地址
            repyData.Add(id);
            // 帧长度
            repyData.Add(0x04);
            // 指令类型
            repyData.Add(0x02);//read
            // 地址
            repyData.Add(regAddr);
            // 长度
            repyData.Add(size);
            // 校验
            repyData.Add((byte)(~(repyData[2] + repyData[3] + repyData[4] + repyData[5] + repyData[6])));
            return repyData;
        }
        /// <summary>
        /// 创建写舵机数据数据帧
        /// </summary>
        /// <param name="id"></param>
        /// <param name="regAddr"></param>
        /// <param name="data"></param>
        /// <param name="size"></param>
        /// <returns></returns>
        public List<byte> CreateWriteSteerDataFrame(byte id, byte regAddr, ushort data, byte size)
        {
            List<byte> repyData = new List<byte>();
            // 帧头
            repyData.Add(0xFF);
            repyData.Add(0xFF);
            // 目标地址
            repyData.Add(id);
            // 帧长度
            repyData.Add(0x05);
            // 指令类型
            repyData.Add(0x03);//write
            // 地址
            repyData.Add(regAddr);
            // 数据
            repyData.Add((byte)(data / 256));
            repyData.Add((byte)(data % 256));
            if (size == 1)
            {
                repyData[3] = 0x04;
                repyData[6] = repyData[7];
                //校验
                repyData[7] = (byte)(~(repyData[2] + repyData[3] + repyData[4] + repyData[5] + repyData[6]));
            }
            else
            {
                // 校验
                repyData.Add((byte)(~(repyData[2] + repyData[3] + repyData[4] + repyData[5] + repyData[6] + repyData[7])));
            }
            return repyData;
        }
        #endregion
        //===========================================================================================
        // 动作文件转换
        //===========================================================================================      
        public string actionName=null;
        public List<actionData> action = new List<actionData>();
        public actionData oneAction = new actionData();// 一个待下载的动作文件
        public byte flag = 0x00;//下载过程标志

        //------------------------------动作帧数据格式----------------------------------------------------
        //开始标志（1B）：0xFA
        //标志（1B）：01表示开始帧，02表示中间帧，03表示结束帧
        //位置数据（2B*20）：DataH,DataL//绝对位置
        //运动时间（2B）：//单位10ms
        //等待时间（2B）：//单位10ms
        //校验（1B）：（帧标志+位置数据+运动时间+等待时间）mod 256
        //结束标志（1B）：0xED
        //-------------------------------------------------------------------------------------------------
        public class frameData
        {
            public byte stx=0xFA;
            public byte flag=0x00;
            public byte[] angle = new byte[40];
            public byte[] time = new byte[2];
            public byte[] delay = new byte[2];
            public byte check=0x00;
            public byte eof=0xED;
        }

        /// <summary>
        /// 包数据格式
        /// </summary>
        public class bagData
        {
            public byte stx=0xAA;                               //包头
            public ushort size=0x00;                            //包大小
            public List<frameData> buf=new List<frameData>();   //包中帧数据            
            public byte check=0x00;                             //包校验=帧校验求和
            public List<byte> bagbuf = new List<byte>();        //包字节数据
            // 计算包数据
            public void bagBufCalc()
            {
                bagbuf.Add(stx);
                bagbuf.Add((byte)(size >> 8));
                bagbuf.Add((byte)size);
                foreach (frameData fd in buf)
                {
                    bagbuf.Add(fd.stx);
                    bagbuf.Add(fd.flag);
                    bagbuf.AddRange(fd.angle);
                    bagbuf.AddRange(fd.time);
                    bagbuf.AddRange(fd.delay);
                    bagbuf.Add(fd.check);
                    bagbuf.Add(fd.eof);
                }
            }
        }
        /// <summary>
        /// 动作文件
        /// </summary>
        public class actionData
        {
            public byte[] name = new byte[16];//ANSI格式存储
            public ushort frameCount=0;
            public ushort size=0;

            public List<byte> inf = new List<byte>();
            public Queue<bagData> bagData= new Queue<bagData>();

            public void infCalc()
            {
                for(int i=0;i<16;i++)
                {
                    if (i<name.Length)
                    {
                        inf.Add(name[i]);
                    }
                    else
                    {
                        inf.Add(0x00);
                    }
                }
                inf.Add((byte)(frameCount >> 8));
                inf.Add((byte)(frameCount));
                inf.Add((byte)(size >> 8));
                inf.Add((byte)(size));
            }
        }

        /// <summary>
        /// 将动作文件提取关键数据转存为字节流//ok
        /// </summary>
        /// <param name="path"></param>
        /// <returns></returns>
        //public void ActionTxt2Hex(string actionName)
        //{
        //    ushort bagCount = 0;
        //    foreach (LeleServo.Action action in LeleServo.ResolveAction.actionlist)
        //    {
        //        if (action.ActionName == actionName)
        //        {
        //            Encoding e1 = Encoding.GetEncoding(936);
        //            oneAction.name = e1.GetBytes(actionName);//unicode -> ansi
        //            oneAction.frameCount = (ushort)action.FrameCount;//帧数
        //            oneAction.size = (ushort)(action.FrameCount * 48);//一帧48字节                    

        //            bagCount = (ushort)Math.Ceiling((double)action.FrameCount / 10);//包数

        //            for (int bagIndex = 0; bagIndex < bagCount; bagIndex++)
        //            {
        //                // 装包
        //                bagData bD = new bagData();
        //                for (int frameIndex = 0; frameIndex < 10; frameIndex++)
        //                {
        //                    if (bagIndex * 10 + frameIndex < action.FrameCount)
        //                    {
        //                        frameData fd = new frameData();//帧
        //                        LeleServo.Frame frame = action.KeyFrames[bagIndex * 10 + frameIndex];
        //                        int i = 2;
        //                        for (int j = 0; j < 17; j++)//2-18编号
        //                        {
        //                            ushort angle = (ushort)frame[j];
        //                            fd.angle[i++] = (byte)(angle >> 8);
        //                            fd.angle[i++] = (byte)(angle);
        //                        }
        //                        fd.flag = 0x02;
        //                        fd.time[0] = (byte)((ushort)(frame.Duration) >> 8);
        //                        fd.time[1] = (byte)((ushort)frame.Duration);
        //                        fd.delay[0] = (byte)((ushort)(frame.Speed) >> 8);
        //                        fd.delay[1] = (byte)((ushort)frame.Speed);
        //                        bD.buf.Add(fd);
        //                    }
        //                }
        //                bD.size = (ushort)(bD.buf.Count * 48);
        //                bD.buf[0].flag = 0x01;
        //                bD.buf[bD.buf.Count - 1].flag = 0x03;
        //                bD.bagBufCalc();
        //                oneAction.bagData.Enqueue(bD);//添加一包                                                                     
        //            }
        //            oneAction.infCalc();
        //        }
        //    }
        //}
        string dir = Environment.GetFolderPath(Environment.SpecialFolder.DesktopDirectory);
        int actionnum = 1;//数组号
        /// <summary>
        /// 动作文件转换位hex文本
        /// </summary>
        /// <param name="actionNum"></param>
        //public void ActionTxt2HexTxt(int actionNum)//ok
        //{
        //    StringBuilder hextxt = new StringBuilder();
        //    foreach (FFRobotMaster.Action action in FFRobotMaster.ResolveAction.actionlist)
        //    {
        //        if (action.ActionNum == actionNum)
        //        {
        //            act subact = new act();
        //            subact.inf = "{" + $"\"name\",{action.ActionNum}," + $"(u8*)framedata{actionnum},sizeof(framedata{actionnum})/24" + "},\r\n";
        //            actionlist.Add(subact);

        //            hextxt.Append($"const u16 framedata{actionnum++}[{action.FrameCount.ToString()}*24]=\r\n");
        //            hextxt.Append("{\r\n");
        //            for (int frameIndex = 0; frameIndex < action.FrameCount; frameIndex++)
        //            {
        //                byte flag;
        //                if (frameIndex == 0)//第一帧
        //                { flag = 0x01; }
        //                else if (frameIndex > 0 && frameIndex < action.FrameCount - 1)//中间帧
        //                { flag = 0x02; }
        //                else//结尾帧
        //                { flag = 0x03; }
        //                hextxt.AppendFormat("0xFA{0},0x0000,", flag.ToString("X2"));
        //                LeleServo.Frame frame = action.KeyFrames[frameIndex];
        //                for (int j = 0; j < 17; j++)//2-18编号
        //                {
        //                    hextxt.AppendFormat("0X{0},", ((ushort)frame[j]).ToString("X4"));
        //                }
        //                hextxt.AppendFormat("0X0000,0x0000,0X{0},0X{1},0X00ED,\r\n", ((ushort)(frame.Duration)).ToString("X4"), ((ushort)(frame.Speed)).ToString("X4"));
        //            }
        //            hextxt.Append("};\r\n");
        //            // 写入指定文件中，追加方式
        //            System.IO.File.AppendAllText(dir + @"\\hextxt.txt", hextxt.ToString(), Encoding.Default);
        //        }
        //    }
        //    //reportError?.Invoke("动作转换完成");
        //}

        public void print()
        {
            // 输出列表文件
            System.IO.File.AppendAllText(dir + @"\\hextxt.txt", "act actlist[30]=\r\n{\r\n", Encoding.Default);//这里要注意 
            foreach (act a in actionlist)
            {
                System.IO.File.AppendAllText(dir + @"\\hextxt.txt", a.inf, Encoding.Default);//这里要注意 
            }
            System.IO.File.AppendAllText(dir + @"\\hextxt.txt", "};\r\n", Encoding.Default);//这里要注意 

            reportError?.Invoke("动作转换完成");
        }

        public class act
        {
            public string inf;
        };
        public List<act> actionlist = new List<act>();

        /// <summary>
        /// 完成整个下载流程
        /// </summary>
        /// <param name="dataId"></param>
        /// <param name="controlCode"></param>
        private void DownLoadAction(DATAID dataId,CCODE controlCode)
        {
            if (controlCode == CCODE.SEW)
            {
                reportError("下载失败!\n错误码" + dataId + " " + flag + "\n");
                return;
            }
            switch (dataId)
            {
                // 文件下载
                case DATAID.DOWNLOAD_MODE:
                    flag = 1;
                    Thread.Sleep(100);
                    excuQueue.Enqueue(new exccmd(DATAID.ACTION_INF, CCODE.MNW, oneAction.inf));
                    break;
                case DATAID.ACTION_INF:
                    flag = 2;
                    Thread.Sleep(100);
                    excuQueue.Enqueue(new exccmd(DATAID.ACTION_BAG, CCODE.MNW, oneAction.bagData.Dequeue().bagbuf));
                    break;
                case DATAID.ACTION_BAG:
                    flag = 3;
                    Thread.Sleep(100);
                    if (oneAction.bagData.Count > 0)
                    {
                        excuQueue.Enqueue(new exccmd(DATAID.ACTION_BAG, CCODE.MNW, oneAction.bagData.Dequeue().bagbuf));
                    }
                    else
                    {
                        excuQueue.Enqueue(new exccmd(DATAID.DOWNLOAD_FIN, CCODE.MNW, new List<byte>()));
                    }
                    break;
                case DATAID.DOWNLOAD_FIN:
                    flag = 0;
                    //SteerDataUpdate(DATAID.DOWNLOAD_FIN, recPFrame.frameData);//下载完成
                    reportError("下载完成");
                    break;
                default:
                    break;
            }                        
        }
    }
}
