using System;
using System.Diagnostics;
using System.IO.Ports;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;

namespace FFRobotMaster.Steering
{
    class Robot_ProtocolV2_0
    {
        //===========================================================================================
        // 常量
        //===========================================================================================
        public const string version = "v2.0";
        /// <summary>
        /// 指令标识表
        /// </summary>
        public enum CMD_BYTE : byte
        {
            CMD_SHAKE = 0x01,   //	握手
            CMD_HEART = 0x02,   //	心跳
            CMD_SPEAK = 0x03,   //	文字发声
            CMD_SWKUP = 0x04,   //	设置唤醒词
            CMD_SLOCK = 0x05,   //	控制单个舵机掉电
            CMD_ALOCK = 0x06,   //	控制全部舵机掉电
            CMD_SMOVE = 0x07,   //	控制单个舵机运动
            CMD_AMOVE = 0x08,   //	控制多个舵机运动
            CMD_RSA = 0x09,     //	回读单个舵机角度
            CMD_RAA = 0x0A,     //	回读多个舵机角度
            CMD_SDIF = 0x0B,    //	设置单个舵机偏移
            CMD_ADIF = 0x0C,    //	设置多个舵机偏移
            CMD_RSDIF = 0x0D,   //	读取单个舵机偏移
            CMD_RADIF = 0x0E,   //	读取多个舵机偏移
            CMD_RSVER = 0x0F,   //	读取单个舵机版本
            CMD_RAVER = 0x10,   //	读取多个舵机版本
            CMD_RSTOR = 0x11,   //	读取单个舵机负载
            CMD_RATOR = 0x12,   //	读取多个舵机负载
            CMD_WHEEL = 0x13,   //	控制机器人轮子

            CMD_WAITDOWN = 0x14,// 创建动作文件并等待下载
            CMD_RUN = 0x15,     // 执行动作
            CMD_CTRL = 0x16,	// 动作暂停/继续/停止

            CMD_EXIST = 0x18,   // 动作文件是否存在
            CMD_DEL=0x19,       // 删除
            //
            CMD_WAIT_TTSDOWN =0x1A, // 创建交互文件并等待下载




        }

        public const byte PACKET_HEAD1  =   0x68;
        public const byte PACKET_HEAD2  =   0x97;
        public const byte PACKET_EOF    =   0x16;
        //===========================================================================================
        // 结构体
        //===========================================================================================
        [StructLayout(LayoutKind.Sequential, Pack = 1)]
        public struct CmdPacket_t
        {
            public byte stx1;
            public byte stx2;
            public byte len;// sizeof(data)
            public CMD_BYTE cmd;
            public IntPtr data;
            public byte check;
            public byte eof;
            public CmdPacket_t(CMD_BYTE cmd,byte[] data,byte count)
            {
                unsafe
                {
                    fixed (byte* point = data)
                    {
                        this.data = new IntPtr(point);
                    }
                }
                Marshal.Copy(data, 0, this.data, count);

                stx1 = PACKET_HEAD1;
                stx2 = PACKET_HEAD2;
                len = count;
                this.cmd = cmd;
                check =(byte)(len+cmd);                
                for (int i = 0; i < count; i++)
                {                    
                    check += data[i];
                }                
                eof = PACKET_EOF;
            }
        };

        //===========================================================================================
        // 发送与接收
        //===========================================================================================
        public SerialPort com = new SerialPort();        
        public delegate void reportErrorEventHandler(string msg);
        public event reportErrorEventHandler reportError;
        public delegate void reportBarEventHandle(int value);
        public delegate void reportBatEventHandle(int value,int per);
        public event reportBatEventHandle reportBat;

        public byte[] receiveBuffer=new byte[100];
        public void StartCommunicationServe(string comName, int rate)
        {
            try{
                com.PortName = comName;
                com.BaudRate = rate;
                com.Open();
                reportError?.Invoke("串口打开成功！");
            }
            catch{
                reportError?.Invoke("串口打开异常！");
            }
        }
        public void StopCommunicationServe()
        {
            try {
                com.Close();
                reportError?.Invoke("串口关闭成功！");
            }
            catch{
                reportError?.Invoke("串口打开异常！");
            }
        }

        public string[] scanBle()
        {
            com.Write("AT+INQ\r\n");
            string receiveData = null;
            string[] retList;
            long startTicks = DateTime.Now.Ticks;
            long endTicks = startTicks + 10000 * TimeSpan.TicksPerMillisecond;
            while (true){
                if (com.BytesToRead > 0){
                    receiveData += com.ReadExisting();
                }
                if ((DateTime.Now.Ticks > endTicks)){
                    break;
                }
            }
            retList = receiveData.Split(':');
            if (retList.Length > 1){
                string[] bleList = new string[retList.Length - 1];
                int indexStart = retList[1].IndexOf("=") + 1;
                int endIndex = retList[1].IndexOf("\r");
                for (int i = 1; i < retList.Length; i++)
                {                    
                    bleList[i - 1] = retList[i].Substring(indexStart, endIndex - indexStart);
                }
                return bleList;
            }
            else{
                return null;
            }            
        }

        public bool conBle(string mac)
        {
            com.Write("AT+CONA" + mac + "\r\n");
            string receiveData = null;
            string[] retList;
            long startTicks = DateTime.Now.Ticks;
            long endTicks = startTicks + 5000 * TimeSpan.TicksPerMillisecond;
            while (true)
            {
                if (com.BytesToRead > 0)
                {
                    receiveData += com.ReadExisting();
                }
                if ((DateTime.Now.Ticks > endTicks))
                {
                    break;
                }
            }
            retList = receiveData.Split('+');
            if (retList.Length > 1)
            {                
                return true;
            }
            else
            {
                return false;
            }
        }

        /// <summary>
        /// 发送协议指令
        /// </summary>
        /// <param name="exccmd"></param>
        /// <param name="retry"></param>
        /// <returns></returns>
        public bool SendProtocolFrame(CmdPacket_t exccmd,int retry=2)
        {
            if (!com.IsOpen) return false;
            byte[] temp = new byte[exccmd.len+6];
            temp[0] = exccmd.stx1;
            temp[1] = exccmd.stx2;
            temp[2] = exccmd.len;
            temp[3] = (byte)exccmd.cmd;
            Marshal.Copy(exccmd.data, temp, 4, exccmd.len);
            temp[exccmd.len + 4] = exccmd.check;
            temp[exccmd.len + 5] = exccmd.eof;
            int re = 0;
            while(true){
                if (re >= retry){
                    reportError?.Invoke("指令超时！");
                    return false;
                }
                com.Write(temp, 0, temp.Length);
                if (WaitResult(true, 1000)){//2000
                    break;
                }
                re++;
            }           
            return true;
        }
        /// <summary>
        /// 接收机器人回复
        /// </summary>
        /// <param name="expResult"></param>
        /// <param name="maxMs"></param>
        /// <returns></returns>
        public bool WaitResult(bool expResult=true, long maxMs=2000)
        {            
            if (!expResult){
                return true;
            }
            receiveBuffer.Initialize();
            if (maxMs < 10) maxMs = 10;
            if (maxMs > 3000) maxMs = 3000;
            long startTicks = DateTime.Now.Ticks;
            long endTicks = startTicks + maxMs * TimeSpan.TicksPerMillisecond;
            bool resultDetected = false;
            while (!resultDetected){
                if (com.BytesToRead > 0){
                    if (com.ReadByte() == PACKET_HEAD1){
                        System.Threading.Thread.Sleep(5);
                        if (com.ReadByte() == PACKET_HEAD2){
                            System.Threading.Thread.Sleep(5);
                            int len = com.ReadByte();
                            if (com.BytesToRead < len + 3){
                                System.Threading.Thread.Sleep((len + 3) * 15);
                            }
                            if (com.BytesToRead >= len + 3){
                                byte c = 0;
                                receiveBuffer[0] = (byte)len;
                                com.Read(receiveBuffer, 1, len + 3);
                                for (int i = 0; i <= len+1; i++){
                                    c += receiveBuffer[i];
                                }
                                if (c == receiveBuffer[len+2]){
                                    resultDetected = true;
                                }
                            }
                        }
                    }
                }
                if (!resultDetected){
                    if ((DateTime.Now.Ticks > endTicks)){
                        // 超时
                        break;
                    }
                }
            }
            return resultDetected;
        }
        
        //===========================================================================================
        // 功能
        //===========================================================================================
        public void robot_shake(byte flag)
        {
            byte[] data = { flag };
            if (SendProtocolFrame(new CmdPacket_t(CMD_BYTE.CMD_SHAKE, data, (byte)data.Length))){
                //Encoding.Default.GetBytes(say);
                //string Name = Encoding.Unicode.GetString(receiveBuffer, 2, receiveBuffer[0]);
                string Name = Encoding.Default.GetString(receiveBuffer, 2, receiveBuffer[0]-1);
                reportError?.Invoke(Name);
            }
        }

        public void robot_heart()
        {
            byte[] data = { 0x00 };
            if (SendProtocolFrame(new CmdPacket_t(CMD_BYTE.CMD_HEART, data, (byte)data.Length))){
                reportBat(receiveBuffer[2], receiveBuffer[3]);
            }
        }

        public void robot_speak(string say)
        {
            byte[] data = Encoding.Default.GetBytes(say);
            SendProtocolFrame(new CmdPacket_t(CMD_BYTE.CMD_SPEAK, data, (byte)data.Length), 1);
        }

        public void robot_wakeup()
        {

        }
        public void robot_lock(byte[] data)
        {
            SendProtocolFrame(new CmdPacket_t(CMD_BYTE.CMD_SLOCK, data, (byte)data.Length), 1);
        }

        public void robot_lockAll(byte[] data)
        {
            SendProtocolFrame(new CmdPacket_t(CMD_BYTE.CMD_ALOCK, data, (byte)data.Length), 1);
        }

        public void robot_move(byte[] data)
        {
            SendProtocolFrame(new CmdPacket_t(CMD_BYTE.CMD_SMOVE, data, (byte)data.Length), 1);
        }

        public void robot_moveMult(byte[] data)
        {
            SendProtocolFrame(new CmdPacket_t(CMD_BYTE.CMD_AMOVE, data, (byte)data.Length), 1);
        }

        public void robot_readAngle()
        {

        }

        public UInt16[] robot_readAllAngle()
        {
            UInt16[] angle=new UInt16[14];
            byte[] data = new byte[] { 0x00 };
            if(SendProtocolFrame(new CmdPacket_t(CMD_BYTE.CMD_RAA, data, (byte)data.Length), 1)){
                for (int i = 1,j=2; i <= 13; i++){
                    angle[i] =(UInt16)(receiveBuffer[j] + receiveBuffer[j+1] * 256);
                    j = j + 2;
                }
            }
            return angle;
        }
        // 设置单个舵机偏移值
        public void robot_setDif(byte[] data)
        {
            if (SendProtocolFrame(new CmdPacket_t(CMD_BYTE.CMD_SDIF, data, (byte)data.Length), 1)){
                reportError?.Invoke("设置成功");
            }
        }
        // 读取单个/多个舵机偏移
        public UInt16[] robot_readDif()
        {
            UInt16[] dif = new UInt16[15+1];
            byte[] data = new byte[] { 0x00 };
            if (SendProtocolFrame(new CmdPacket_t(CMD_BYTE.CMD_RADIF, data, (byte)data.Length), 1)){
                for (int i = 1, j = 2; i <= 13; i++){
                    dif[i] = (UInt16)(receiveBuffer[j] + receiveBuffer[j + 1] * 256);
                    j = j + 2;
                }
                reportError?.Invoke("读取成功");
            }
            else{
                reportError?.Invoke("读取失败");
            }
            return dif;
        }
        // 读取单个/多个舵机版本
        public void robot_readSteerVer()
        {
            
        }

        // 读取单个/多个舵机负载
        public void robot_readSteerTor()
        {
           
        }

        // 机器人轮子控制
        public void robot_wheel(byte[] data){
            SendProtocolFrame(new CmdPacket_t(CMD_BYTE.CMD_WHEEL, data, (byte)data.Length), 1);
        }

        //-----------------文件下载相关操作--------------------------------
        // 创建一个动作文件并使机器人进入动作文件/交互文本/HEX固件接收准备状态
        public void robot_createAction(string name,byte[] da, byte flag)//0x01,0x02,0x03
        {
            byte[] data = System.Text.Encoding.Default.GetBytes(name);
            bool state = false;
            if (flag == 0x01)
            {
                state = SendProtocolFrame(new CmdPacket_t(CMD_BYTE.CMD_WAITDOWN, data, (byte)data.Length), 1);
            }
            else if (flag == 0x02)
            {
                state = SendProtocolFrame(new CmdPacket_t(CMD_BYTE.CMD_WAIT_TTSDOWN, data, (byte)data.Length), 1);
            }
            else if (flag == 0x03)
            {

            }
            if (state)
            {
                // 进入下载状态
                int states = 0;
                StartFlag = 1;// 开始下载
                com.DiscardInBuffer();com.DiscardOutBuffer();
                try{
                    while (StartFlag != 0){
                        switch (states)
                        {
                            case 0:// 验证
                                com.Write("LY");
                                int w = 0;
                                for (; w < 500; w++){
                                    Thread.Sleep(10);
                                    if (com.BytesToRead >= 1) break;
                                }
                                if (w >= 500){
                                    System.Windows.MessageBox.Show("联机超时！");
                                    return ;
                                }
                                if (com.BytesToRead == 1){
                                    if (com.ReadByte() == 'C'){
                                        states = 1;
                                    }
                                }
                                else if (com.BytesToRead > 0){
                                    if (com.ReadByte() == 67){
                                        states = 1;
                                    }
                                }
                                break;
                            case 1:
                                if (send_actionData(da))
                                {
                                    System.Windows.MessageBox.Show("下载完成！");
                                }
                                else
                                {
                                    System.Windows.MessageBox.Show("下载失败！");
                                }
                                StartFlag = 0;
                                break;
                        }
                    }
                }
                catch (Exception ex) { Debug.Print(ex.Message);}
            }
            else{ reportError("未能正确进入下载模式");}
            FFRobotMaster.MainWindow.progress = 0;
        }
        //===========================================================================================
        // 下载处理
        //===========================================================================================        
        private int StartFlag = 0;
        private const int framesize = 46;
        // 发送动作数据
        private bool send_actionData(byte[] data)
        {
            byte[] array = new byte[data.Length];
            checked
            {
                for (int i = 0; i < data.Length; i++)
                {
                    array[i] = byte.MaxValue;
                }
                data.CopyTo(array, 0);
                int total_bytes = data.Length;
                int frame_count = 0;
                // 以46字节为单位块，字节数
                frame_count = ((unchecked(total_bytes % framesize) != 0) ? ((unchecked(total_bytes / framesize) + 1) * framesize) : total_bytes);
                // 一包数据
                byte[] subbag = new byte[framesize + 3];
                int fail_count = 0;
                // 发送几次46字节块
                int cake = unchecked(frame_count / framesize) - 1;
                for (int i = 0; i <= cake; i++)
                {
                    subbag[0] = (i == cake) ? (byte)4 : (byte)1;
                    subbag[1] = (byte)(i + 1);//块号1-xxx
                    subbag[2] = (byte)(255 - unchecked((int)subbag[1]));//块号补数
                    if (StartFlag == 0)
                    {
                        return false;
                    }
                    for (int j = 3; j < framesize + 3; j++)
                    {
                        subbag[j] = array[i * framesize + j - 3];//复制填充
                    }
                    com.DiscardInBuffer();
                    com.DiscardOutBuffer();
                    com.Write(subbag, 0, framesize + 3);
                    int w = 0;
                    for (; w < 400; w++)
                    {
                        Thread.Sleep(10);
                        if (com.BytesToRead >= 1)
                        {
                            break;
                        }
                    }
                    if (w >= 400)
                    {
                        return false;
                    }
                    switch ((byte)com.ReadByte())
                    {
                        case 6:// 接收成功                            
                            if (frame_count == framesize)
                            {
                                //reportBar(100);
                                FFRobotMaster.MainWindow.progress = 100;
                            }
                            else
                            {
                                //unchecked {reportBar(checked(i * 100) / checked(unchecked(frame_count / framesize) - 1));}
                                FFRobotMaster.MainWindow.progress = checked(i * 100) / checked(unchecked(frame_count / framesize) - 1);
                            }
                            fail_count = 0;
                            break;
                        case 21:// 接收失败
                            fail_count++;
                            if (fail_count == 10)
                            {
                                return false;
                            }
                            i--;
                            break;
                        default:
                            return false;
                    }
                }
                return true;
            }
        }

        // 执行动作
        public void robot_run(string name,byte flag)
        {
            byte[] temp = System.Text.Encoding.Default.GetBytes(name);
            byte[] data = new byte[temp.Length + 1];
            temp.CopyTo(data, 1);
            data[0] = flag;//0x01 单机，0x02 广播
            SendProtocolFrame(new CmdPacket_t(CMD_BYTE.CMD_RUN, data, (byte)data.Length));
        }

        ///暂停/继续/停止
        public void robot_ctr(byte s)
        {
            byte[] data = new byte[1] {s};
            SendProtocolFrame(new CmdPacket_t(CMD_BYTE.CMD_CTRL, data, (byte)data.Length));
        }
        public bool robot_exist(string name)
        {
            byte[] data = System.Text.Encoding.Default.GetBytes(name);
            if (SendProtocolFrame(new CmdPacket_t(CMD_BYTE.CMD_EXIST, data, (byte)data.Length))){
                if (receiveBuffer[2] == 0x00){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
}
