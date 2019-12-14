using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace FFRobotMaster
{
    public class Action:IDisposable
    {
        private int myBoneCount;
        /// <summary>
        /// 设置/返回此动作序列中关键帧的关节数。
        /// </summary>
        public int BoneCount
        {
            get{return myBoneCount;}
        }
        /// <summary>
        /// 返回此动作序列中关键帧数。
        /// </summary>
        public int Count
        {
            get{return KeyFrames.Count;}
        }
        /// <summary>
        /// 返回此动作的总长度。//ms
        /// </summary>
        public float Duration
        {
            get
            {
                float sum = 0;
                for (int t = 1; t < KeyFrames.Count; t++)
                {
                    sum += KeyFrames[t].Duration+ KeyFrames[t].Pause;//总时间=运动时间+停顿时间
                }
                return sum;
            }
        }
        /// <summary>
        /// 返回指定关键帧的开始时间。//ms
        /// </summary>
        /// <param name="Index"></param>
        /// <returns></returns>
        public float StartTime(int Index)
        {
            float sum = 0;
            for (int t = 1; t < Index; t++){
                sum += KeyFrames[t].Duration;
            }
            return sum;
        }
        /// <summary>
        /// 关键帧。
        /// </summary>
        public List<Frame> KeyFrames;
       /// <summary>
       /// 动作的名字。
       /// </summary>
        public string Name { get; set; }
        public string Downloaded { get; set; } = "×";//√×
        /// <summary>
        /// 指定一个机器人，新建一个其动作序列。
        /// </summary>
        /// <param name="r"></param>
        public Action(Robot r){
            myBoneCount = r.Count;
            KeyFrames = new List<Frame>();
            AddZeroFrame();
            Name = "";
        }
       /// <summary>
       /// 指定时间，返回此时间的帧。
       /// </summary>
       /// <param name="time"></param>
       /// <returns></returns>
        public Frame LerpFrame( float time){          
            if (time <= StartTime(0))
                return KeyFrames[0];
            if (time >= Duration)
                return KeyFrames[Count - 1];
            int i = 0;
            for(int t=1; t<KeyFrames.Count; t++){
                if (time > StartTime(t))
                    i = t-1 ;
                else
                    break;
            }
            Frame tmpf = Frame.Lerp(KeyFrames[i], KeyFrames[i + 1], BoneCount, (time - StartTime(i + 1)) / KeyFrames[i + 1].Duration);
            return tmpf;
        }
        /// <summary>
        /// 新建一个默认关键帧。
        /// </summary>
        /// <param name="Index">指定插入此关键帧的位置。如果未指定或指定无效，那么默认在最后插入。</param>
        public void AddZeroFrame(int Index = -1){
            if (Index == -1)
                KeyFrames.Add(new Frame(myBoneCount));
            else
                KeyFrames.Insert(Index + 1, new Frame(myBoneCount));
        }
        /// <summary>
        /// 复制指定的一帧并插入其后。
        /// </summary>
        /// <param name="Index">指定复制的关键帧，如果未指定或指定无效，那么默认复制最后一帧或建立空帧。</param>
        public void AddCopyFrame(int Index = -1){
            Frame f = new Frame(myBoneCount);
            for (int t=0; t<myBoneCount; t++){
                f[t] = KeyFrames[Index][t];
            }
            f.SetSnapShot(KeyFrames[Index].SnapShot);
            KeyFrames.Insert(Index + 1, f);
        }
        /// <summary>
        /// 删除指定的关键帧。
        /// </summary>
        /// <param name="Index"></param>
        public void RemoveFrame(int Index){
            if (Count>1)
                KeyFrames.RemoveAt(Index);
        }
        /// <summary>
        /// 指定第一个关键帧的序号，交换两个相邻关键帧的位置。
        /// </summary>
        /// <param name="Index"></param>
        public void SwapFrame(int Index)
        {
            if (Index>=0 && Index<Count-1){
                Frame tmpf = KeyFrames[Index];
                KeyFrames[Index] = KeyFrames[Index + 1];
                KeyFrames[Index + 1] = tmpf;
            }
        }
        /// <summary>
        /// 插入一个关键帧。
        /// </summary>
        /// <param name="Index"></param>
        /// <param name="F"></param>
        public void InsertFrame(int Index, Frame F){
            KeyFrames.Insert(Index, F);
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="b"></param>
        /// <param name="StartIndex"></param>
        /// <param name="Length"></param>
        public Action(byte[] b, int StartIndex, int Length){
            int tmpp = StartIndex;
            myBoneCount = BitConverter.ToInt32(b, tmpp);//骨骼数
            tmpp += 4;
            int tmpfc = BitConverter.ToInt32(b, tmpp);  //帧数
            tmpp += 4;
            KeyFrames = new List<Frame>(tmpfc);         //帧序列
            // 关键帧列表中填充帧数据
            for (int t = 0; t < tmpfc; t++){
                int tmpfl= BitConverter.ToInt32(b, tmpp);//动作总时长
                tmpp += 4;
                KeyFrames.Add(new Frame(b, tmpp, tmpfl));
                tmpp += tmpfl;
            }
            int tmpsl = BitConverter.ToInt32(b, tmpp);
            tmpp += 4;
            Name = System.Text.Encoding.Unicode.GetString(b, tmpp, tmpsl);//动作名
            tmpp += tmpsl;
        }
        /// <summary>
        /// 将动作转字节
        /// </summary>
        /// <returns></returns>
        public byte[] ToBuffer(){
            MemoryStream ms = new MemoryStream(256 * 1024);
            ms.Write(BitConverter.GetBytes(myBoneCount), 0, 4);         // 骨骼数
            ms.Write(BitConverter.GetBytes(KeyFrames.Count), 0, 4);     // 帧数
            for (int t=0; t<KeyFrames.Count; t++){
                byte[] tmpb = KeyFrames[t].ToBuffer();
                ms.Write(BitConverter.GetBytes(tmpb.Length), 0, 4);
                ms.Write(tmpb, 0, tmpb.Length);
            }
            byte[] tmps = System.Text.Encoding.Unicode.GetBytes(Name);  
            ms.Write(BitConverter.GetBytes(tmps.Length), 0, 4);         // 动作名长度 
            ms.Write(tmps, 0, tmps.Length);                             // 动作名
            byte[] b = ms.ToArray();
            ms.Dispose();
            return b;
        }
        #region IDisposable Support
        private bool disposedValue = false; // 要检测冗余调用
        protected virtual void Dispose(bool disposing){
            if (!disposedValue){
                if (disposing){
                    // TODO: 释放托管状态(托管对象)。
                }
                // TODO: 释放未托管的资源(未托管的对象)并在以下内容中替代终结器。
                // TODO: 将大型字段设置为 null。
                disposedValue = true;
            }
        }

        // TODO: 仅当以上 Dispose(bool disposing) 拥有用于释放未托管资源的代码时才替代终结器。
        // ~Action() {
        //   // 请勿更改此代码。将清理代码放入以上 Dispose(bool disposing) 中。
        //   Dispose(false);
        // }

        // 添加此代码以正确实现可处置模式。
        public void Dispose(){
            // 请勿更改此代码。将清理代码放入以上 Dispose(bool disposing) 中。
            Dispose(true);
            // TODO: 如果在以上内容中替代了终结器，则取消注释以下行。
            // GC.SuppressFinalize(this);
        }
        #endregion
    }
}
