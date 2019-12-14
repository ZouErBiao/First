using System;
using System.Collections.Generic;
using System.IO;

namespace FFRobotMaster
{
    public class ActionsFile:IDisposable
    {
        /// <summary>
        /// 动作集字节数组
        /// </summary>
        byte[] Data;
        public ActionsFile(List<Action> A){
            MemoryStream ms = new MemoryStream(4096 * 1024);
            ms.Write(BitConverter.GetBytes(A.Count), 0, 4);         // 总动作数
            for(int t=0; t<A.Count; t++){
                byte[] tmpa = A[t].ToBuffer();
                ms.Write(BitConverter.GetBytes(tmpa.Length), 0, 4); // 动作字节数
                ms.Write(tmpa, 0, tmpa.Length);                     // 动作数据
            }
            Data = ms.ToArray();
            ms.Dispose();
        }
        /// <summary>
        /// 保存这个动作列表文件。
        /// </summary>
        /// <param name="Filename"></param>
        public void Save(string Filename){
            FileStream fs = new FileStream(Filename, FileMode.OpenOrCreate);
            BinaryWriter bw = new BinaryWriter(fs);
            bw.Write(Data, 0, Data.Length);
            bw.Close();
            fs.Close();
        }
        /// <summary>
        /// 打开默认文件。
        /// </summary>
        public ActionsFile(){
            Data = Properties.Resources._default;
        }
        public ActionsFile(string Filename){
            FileStream fs = new FileStream(Filename, FileMode.Open);
            BinaryReader br = new BinaryReader(fs);
            Data = br.ReadBytes((int)fs.Length);
            fs.Close();
        }
        /// <summary>
        /// 解析动作集字节数据到动作和帧
        /// </summary>
        /// <returns>返回动作列表</returns>
        public List<Action> ToActions(){
            MemoryStream ms = new MemoryStream(Data);
            int tmpp = 0;
            int tmpc = BitConverter.ToInt32(Data, tmpp);// 开头4个字节存放动作集合总动作数
            tmpp += 4;
            List<Action> tmpl = new List<Action>(tmpc);
            for (int t = 0; t < tmpc; t++)// 逐个动作解析
            {
                int tmpd = BitConverter.ToInt32(Data, tmpp);// 之后4个字节存放单个动作字节数
                tmpp += 4;
                Action tmpa = new Action(Data, tmpp, tmpd);// 之后存放动作数据
                tmpp += tmpd;
                tmpl.Add(tmpa);
            }
            ms.Close();
            return tmpl;
        }
        #region IDisposable Support
        private bool disposedValue = false; // 要检测冗余调用

        protected virtual void Dispose(bool disposing)
        {
            if (!disposedValue)
            {
                if (disposing)
                {
                    // TODO: 释放托管状态(托管对象)。
                }
                Data = null;
                // TODO: 释放未托管的资源(未托管的对象)并在以下内容中替代终结器。
                // TODO: 将大型字段设置为 null。

                disposedValue = true;
            }
        }

        // TODO: 仅当以上 Dispose(bool disposing) 拥有用于释放未托管资源的代码时才替代终结器。
        // ~ActionsFile() {
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


