using System;

namespace ActionFileIO
{
    public class PoseInf
    {
        /// <summary>
        /// 姿态号
        /// </summary>
        public UInt16 PoseId { get; set; }
        /// <summary>
        /// 关节角度
        /// </summary>
        public UInt16[] ServoAngle = new UInt16[CONST.MAX_SERVO + 1];// 数组下标直接与关节编号对应
        /// <summary>
        /// 执行时间
        /// </summary>
        public UInt16 ExecuteTime { get; set; }
        /// <summary>
        /// 保持时间
        /// </summary>
        public UInt16 WaitTime { get; set; }

        public PoseInf(UInt16 poseId)
        {
            this.PoseId = poseId;
            this.Reset();
        }

        public void Reset()
        {
            this.ExecuteTime = 0;
            this.WaitTime = 0;
        }
    }
}
