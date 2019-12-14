using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using System.IO;

namespace FFRobotMaster
{
    public class Frame : IDisposable
    {
        private MemoryStream myStream;
        public Bitmap SnapShot;
        private Graphics myCathe;
        private float[] myAngle;
        private bool amEmpty;
        
        /// <summary>
        /// 单位ms
        /// </summary>
        public float Duration 
        {
            get; set;
        }

        /// <summary>
        /// 单位ms
        /// </summary>
        public float Pause
        {
            get; set;
        }

        public Frame Clone()
        {
            Frame f = new Frame(myAngle.Length, false);
            f.myAngle = (float[])this.myAngle.Clone();
            f.amEmpty = this.amEmpty;
                f.Duration = this.Duration;
            if (SnapShot != null)
                f.SnapShot = (Bitmap)this.SnapShot.Clone();
            return f;
        }
        /// <summary>
        /// 设置/返回指定骨骼的角度。
        /// </summary>
        /// <param name="Index"></param>
        /// <returns></returns>
        public float this[int Index]
        {
            get
            {
                return myAngle[Index];
            }
            set
            {
                myAngle[Index] = value;
            }
        }

        /// <summary>
        /// 机器人图片绘制成120*120缩略图
        /// </summary>
        /// <param name="Screenshot"></param>
        public void SetSnapShot(Bitmap Screenshot)
        {
            int tmpk = Math.Min(Screenshot.Width, Screenshot.Height);
            int tmpt = (Screenshot.Height - tmpk) / 2,
                    tmpl = (Screenshot.Width - tmpk) / 2;
            if (amEmpty)
            {
                SnapShot = new Bitmap(120, 120, System.Drawing.Imaging.PixelFormat.Format32bppArgb);
                myCathe = Graphics.FromImage(SnapShot);
                amEmpty = false;
            }
            //要绘制的图像，绘制到指定位置，要绘制的图像的部分
            myCathe.DrawImage(Screenshot, new Rectangle(0,0, SnapShot.Width, SnapShot.Height), 
                new Rectangle(tmpl, tmpt, tmpk, tmpk), GraphicsUnit.Pixel);
        }

        /// <summary>
        /// 指定骨骼数，新建一个姿态。所有的角度数据都是0。
        /// </summary>
        /// <param name="Count"></param>
        public Frame(int Count, bool withShot = true)
        {
            myAngle = new float[Count];
            if (withShot)
            {
                SnapShot = Properties.Resources.DefaultFrame;
                // 没有图片则创建一个默认图片
                //SnapShot = new Bitmap(120, 120, System.Drawing.Imaging.PixelFormat.Format32bppArgb);
            }
            amEmpty = true;
            Duration = 1;
        }

        /// <summary>
        /// 计算两个帧的插值。
        /// </summary>
        /// <param name="f1"></param>
        /// <param name="f2"></param>
        /// <param name="C"></param>
        /// <param name="d"></param>
        /// <returns></returns>
        static public Frame Lerp(Frame f1, Frame f2,int C, float d)
        {
            Frame f3 = new Frame(C, false);
            for(int t=0; t<C; t++)
            {
                f3[t] = f1[t] + (f2[t] - f1[t]) * d;
            }
            return f3;
        }

        /// <summary>
        /// 使用一个Byte数组新建Frame。
        /// </summary>
        /// <param name="b"></param>
        public Frame(byte[] b, int StartIndex, int Length)
        {
            int tmpp = StartIndex;                              //指示关节个数
            myAngle = new float[BitConverter.ToInt32(b, tmpp)]; //角度数组
            tmpp += 4;
            for (int t = 0; t < myAngle.Length; t++)            //填充角度值
            {
                myAngle[t] = BitConverter.ToSingle(b, tmpp);
                tmpp += 4;
            }
            Duration = BitConverter.ToSingle(b, tmpp);//持续时间 单位ms
            tmpp += 4;

            Pause = BitConverter.ToSingle(b, tmpp);//停顿时间 单位ms
            tmpp += 4;

            long tmpl = BitConverter.ToInt64(b, tmpp);//机器人图片字节数
            tmpp += 8;
            if (tmpl > 0)
            {
                MemoryStream ms = new MemoryStream(b, tmpp, (int)tmpl);
                SnapShot = new Bitmap(ms);
                myCathe = Graphics.FromImage(SnapShot);
            }
            else
            {
                // 没有图片则创建一个默认图片
                SnapShot = new Bitmap(120, 120, System.Drawing.Imaging.PixelFormat.Format32bppArgb);
                myCathe = Graphics.FromImage(SnapShot);
                //myCathe.DrawImage(Properties.Resources.DefaultFrame, new Rectangle(0, 0, 120, 120),
                //new Rectangle(0, 0, 120, 120), GraphicsUnit.Pixel);
            }
        }

        /// <summary>
        /// 将此Frame转换成Byte数组表示。
        /// </summary>
        /// <returns></returns>
        public byte[] ToBuffer()
        {
            MemoryStream ms = new MemoryStream(16384);
            ms.Write(BitConverter.GetBytes(myAngle.Length), 0, 4);
            for (int t=0; t<myAngle.Length; t++)
                ms.Write(BitConverter.GetBytes(myAngle[t]), 0, 4);
            ms.Write(BitConverter.GetBytes(Duration), 0, 4);
            ms.Write(BitConverter.GetBytes(Pause), 0, 4);//
            if (amEmpty){
                ms.Write(BitConverter.GetBytes(0L), 0, 8);
            }
            else{
                MemoryStream pngms = new MemoryStream();
                SnapShot.Save(pngms, System.Drawing.Imaging.ImageFormat.Png);
                ms.Write(BitConverter.GetBytes(pngms.Length), 0, 8);
                pngms.WriteTo(ms);
                pngms.Dispose();
            }            
            byte[] b = ms.ToArray();
            ms.Dispose();
            return b;
        }
        #region IDisposable Support
        private bool disposedValue = false; // 要检测冗余调用
        protected virtual void Dispose(bool disposing)
        {
            if (!disposedValue){
                if (disposing){
                    // TODO: 释放托管状态(托管对象)。
                    if (SnapShot != null)
                        SnapShot.Dispose();
                    if (myCathe != null)
                        myCathe.Dispose();
                    if (myStream != null)
                        myStream.Dispose();
                }
                // TODO: 释放未托管的资源(未托管的对象)并在以下内容中替代终结器。
                // TODO: 将大型字段设置为 null。
                myAngle = null;
                disposedValue = true;
            }
        }

        // TODO: 仅当以上 Dispose(bool disposing) 拥有用于释放未托管资源的代码时才替代终结器。
        // ~Frame() {
        //   // 请勿更改此代码。将清理代码放入以上 Dispose(bool disposing) 中。
        //   Dispose(false);
        // }

        // 添加此代码以正确实现可处置模式。
        public void Dispose()
        {
            // 请勿更改此代码。将清理代码放入以上 Dispose(bool disposing) 中。
            Dispose(true);
            // TODO: 如果在以上内容中替代了终结器，则取消注释以下行。
            // GC.SuppressFinalize(this);
        }
        #endregion
    }
}
