using System;
using System.Drawing;
using SlimDX;
using FluoriteEngine;

namespace FFRobotMaster
{
    /// <summary>
    /// 一段骨骼的数据。
    /// </summary>
    public class Bone
    {
        /// <summary>
        /// 这个骨骼的序号。
        /// </summary>
        public int Index { get; set; }
        /// <summary>
        /// 这个骨骼的父骨骼的序号。
        /// </summary>
        public int ParentIndex { get; set; }
        /// <summary>
        /// 这个骨骼的模型的序号。
        /// </summary>
        public int Subset { get; set; }
        /// <summary>
        /// 与这个骨骼对称的骨骼的序号。
        /// </summary>
        public int MirrorIndex { get; set; }
        /// <summary>
        /// 当前骨骼的基础位置（例如，上臂的基础位置是肩关节位置）。
        /// </summary>
        public Vector3 Position { get; set; }
        /// <summary>
        /// 当前骨骼的基础生长方向（例如，头的基础生长方向是垂直向上）。
        /// </summary>
        public Vector3 Direction { get; set; }
        /// <summary>
        /// 当前骨骼的基础旋转轴方向，遵循左手法则。
        /// </summary>
        public Vector3 Axis { get; set; }
        /// <summary>
        /// 当前骨骼的零点。
        /// </summary>
        public int Zero { get; set; }
        /// <summary>
        /// 当前骨骼的比例。
        /// </summary>
        public float Proportion { get; set; }
        private float myAngle;
        /// <summary>
        /// 当前骨骼的旋转角度。
        /// </summary>
        public float Angle
        {
            get
            {
                return myAngle;
            }
            set
            {
                myAngle = Math.Max(Math.Min(value, AngleLimitB), AngleLimitA);
            }
        }
        /// <summary>
        /// 当前骨骼的旋转角度下限。
        /// </summary>
        public float AngleLimitA { get; set; }
        /// <summary>
        /// 当前骨骼的旋转角度上限。
        /// </summary>
        public float AngleLimitB { get; set; }
        internal Vector3 myUpdatedPosition;
        /// <summary>
        /// 考虑到所有的亲代骨骼后此骨骼的基础生长位置。
        /// </summary>
        public Vector3 UpdatedPosition
        {
            get
            {
                return myUpdatedPosition;
            }
        }
        /// <summary>
        /// 骨骼的名字
        /// </summary>
        public string Name;
        /// <summary>
        /// 
        /// </summary>
        public Picture Pic;
        /// <summary>
        /// 
        /// </summary>
        public Color C;
    }
}
