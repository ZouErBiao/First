using FluoriteEngine;
using SlimDX;
using SlimDX.Direct3D9;
using System;
using System.Collections.Generic;
using System.Drawing;

namespace FFRobotMaster
{
    /// <summary>
    /// 机器人的定义。
    /// </summary>
    public class Robot
    {
        /// <summary>
        /// 这个机器人的原始数模。
        /// </summary>
        private XFile RobotModel;


        /// <summary>
        /// 将原始数模应用了动作的输出数模。
        /// </summary>
        public XFile UpdatedModel;
        /// <summary>
        /// 原始的骨骼信息。
        /// </summary>
        /// <param name="Index"></param>
        /// <returns></returns>
        private List<Bone> AllBones;        
        public Bone this[int Index]
        {
            get
            {
                return AllBones[Index];
            }
        }

        /// <summary>
        /// 地面的Y轴坐标。
        /// </summary>
        public float Ground
        {
            get
            {
                return myGround;
            }
        }

        private float myGround;

        /// <summary>
        /// 所有骨骼的中心位置。
        /// </summary>
        public Vector3 UpdatedCenter
        {
            get
            {
                Vector3 sum=Vector3.Zero;
                for (int t = 0; t < AllBones.Count; t++)
                {
                    sum += AllBones[t].myUpdatedPosition;
                }
                sum /= AllBones.Count;
                return sum;
            }
        }

        /// <summary>
        /// 机器人整体的变换。当需要设置机器人按重心、左脚触地、右脚触地时，需要设置这个参数。
        /// </summary>
        public Matrix Transform;

        /// <summary>
        /// 绘制指定的关节。
        /// </summary>
        /// <param name="Index"></param>
        public void Draw(int Index)
        {
            UpdatedModel.Draw(Matrix.Identity, AllBones[Index].Subset);
            //RobotModel.Draw(Matrix.Identity, AllBones[Index].Subset);
        }

        /// <summary>
        /// 根据各骨骼的角度，更新整个机器人模型。
        /// </summary>
        public void Update()
        {
            Matrix[] tmpm = new Matrix[AllBones.Count];
            float sumy=0;
            float tmpy = float.MaxValue;
            for (int t = 0; t < AllBones.Count; t++)
            {
                int tmpb = t;
                tmpm[t] = Matrix.Identity;//单位矩阵

                do
                {
                    tmpm[t] *= Matrix.Translation(-AllBones[tmpb].Position);//平移到基础位置
                    tmpm[t] *= Matrix.RotationAxis(AllBones[tmpb].Axis, AllBones[tmpb].Angle / 180 * 3.1416F);//旋转
                    tmpm[t] *= Matrix.Translation(AllBones[tmpb].Position);//平移
                } while ((tmpb = AllBones[tmpb].ParentIndex) != -1);//不是根骨

                tmpm[t] *= Transform;
                //位于屏幕中心
                AllBones[t].myUpdatedPosition = Vector3.Transform(AllBones[t].Position, tmpm[t]).ToVector3();
                sumy += AllBones[t].myUpdatedPosition.Y;
            }

            DataStream tmpsrc = RobotModel.LockVertex(), tmpdest = UpdatedModel.LockVertex();
            AttributeRange[] ar = RobotModel.myMesh.GetAttributeTable();
            sumy /= AllBones.Count;
            tmpy = float.MaxValue;

            for (int t = 0; t < AllBones.Count; t++)
            {
                if (AllBones[t].Subset >= 0)
                {
                    tmpsrc.Seek(ar[AllBones[t].Subset].VertexStart * PositionNormalTextureC.Length(), System.IO.SeekOrigin.Begin);
                    tmpdest.Seek(ar[AllBones[t].Subset].VertexStart * PositionNormalTextureC.Length(), System.IO.SeekOrigin.Begin);
                    if (AllBones[t].myUpdatedPosition.Y < sumy)
                    {
                        for (int tt = 0; tt < ar[AllBones[t].Subset].VertexCount; tt++)
                        {
                            PositionNormalTextureC pnt = tmpsrc.Read<PositionNormalTextureC>();
                            PositionNormalTextureC pnt2 = new PositionNormalTextureC(Vector3.Transform(pnt.Position, tmpm[t]).ToVector3(),
                                Vector3.TransformNormal(pnt.Normal, tmpm[t]),pnt.UV);
                            tmpy = Math.Min(tmpy, pnt2.Position.Y);
                            tmpdest.Write<PositionNormalTextureC>(pnt2);
                        }
                    }
                    else
                    {
                        for (int tt = 0; tt < ar[AllBones[t].Subset].VertexCount; tt++)
                        {
                            PositionNormalTextureC pnt = tmpsrc.Read<PositionNormalTextureC>();
                            PositionNormalTextureC pnt2 = new PositionNormalTextureC(Vector3.Transform(pnt.Position, tmpm[t]).ToVector3(),
                                Vector3.TransformNormal(pnt.Normal, tmpm[t]),pnt.UV);
                            tmpdest.Write<PositionNormalTextureC>(pnt2);
                        }
                    }
                }
            }
            myGround = tmpy;
            RobotModel.UnLockVertex();
            UpdatedModel.UnLockVertex();
        }

        /// <summary>
        /// 返回此机器人的骨骼数量。
        /// </summary>
        public int Count 
        {
            get{ return AllBones.Count; }
        }

        /// <summary>
        /// 设置机器人的动作帧。
        /// </summary>
        public void SetFrame(Frame f)
        {
            for (int t = 0; t < Count; t++)
            {
                AllBones[t].Angle = f[t];
            }
            Update();
        }

        /// <summary>
        /// 获取当前编辑的机器人的动作帧。
        /// </summary>
        /// <returns></returns>
        public void GetFrame(Frame f)
        {
            for(int t=0; t<Count; t++)
            {
                f[t] = AllBones[t].Angle;
            }
        }

        /// <summary>
        /// 将指定的关节依照指定的生长方向对齐。
        /// 例如，要设置”左脚触地“，就指定左脚关节和前方向，因为左脚触地时自然向前。
        /// </summary>
        public void Align(string Name, Vector3 d)
        {
            int Index = -1 ;
            for (int t = 0; t < this.Count; t++)
            {
                if (this[t].Name == Name)
                {
                    Index = t;
                    break;
                }
            }
            if (Index == -1)
                return;
            int tmpb = Index;
            Matrix tmpm = Matrix.Identity;
            do
            {
                tmpm *= Matrix.RotationAxis(AllBones[tmpb].Axis, AllBones[tmpb].Angle / 180 * 3.1416F);
            } while ((tmpb = AllBones[tmpb].ParentIndex) != -1);
            Vector3 v = Vector3.Normalize( Vector3.Transform(AllBones[Index].Direction, tmpm).ToVector3());
            Transform = Fluorite.Mathmatics.RotationDirectionToDirection(v, d);
        }

        /// <summary>
        /// 将指定的两个关节依照指定的生长方向对齐。
        /// 例如，要设置”左右脚触地“，就指定左脚关节、右脚关节和前方向。
        /// </summary>
        /// <param name="Index1"></param>
        /// <param name="Index2"></param>
        /// <param name="d1"></param>
        /// <param name="d2"></param>
        public void Align2(string Name1, string Name2, Vector3 d)
        {
            int Index1 = -1, Index2=-1;
            for (int t = 0; t < this.Count; t++)
            {
                if (this[t].Name == Name1)
                {
                    Index1 = t;
                    break;
                }
            }
            for (int t = 0; t < this.Count; t++)
            {
                if (this[t].Name == Name2)
                {
                    Index2 = t;
                    break;
                }
            }
            if (Index1 == -1 || Index2 == -1)
                return;

            int tmpb = Index1;
            Matrix tmpm = Matrix.Identity;
            do
            {
                tmpm *= Matrix.RotationAxis(AllBones[tmpb].Axis, AllBones[tmpb].Angle / 180 * 3.1416F);
            } while ((tmpb = AllBones[tmpb].ParentIndex) != -1);
            Vector3 v1 = Vector3.Normalize(Vector3.Transform(AllBones[Index1].Direction, tmpm).ToVector3());

            tmpb = Index2;
            tmpm = Matrix.Identity;
            do
            {
                tmpm *= Matrix.RotationAxis(AllBones[tmpb].Axis, AllBones[tmpb].Angle / 180 * 3.1416F);
            } while ((tmpb = AllBones[tmpb].ParentIndex) != -1);
            Vector3 v2 = Vector3.Normalize(Vector3.Transform(AllBones[Index2].Direction, tmpm).ToVector3());

            Vector3 v = Vector3.Normalize(v1 + v2);

            Transform = Fluorite.Mathmatics.RotationDirectionToDirection(v, d);
        }

        public void Mirror()
        {
            float tmpa;
            for(int t=0; t<Count; t++)
            {
                if (AllBones[t].Position.X<0 && AllBones[t].MirrorIndex>-1)
                {
                    tmpa = AllBones[t].Angle;
                    AllBones[t].Angle = AllBones[AllBones[t].MirrorIndex].Angle;
                    AllBones[AllBones[t].MirrorIndex].Angle = tmpa;
                }
            }
            Update();
        }
        /// <summary>
        /// 镜像左侧
        /// </summary>
        public void MirrorLeft()
        {
            for (int t = 0; t < Count; t++)
            {
                if (AllBones[t].Position.X > 0 && AllBones[t].MirrorIndex > -1)
                {
                    AllBones[t].Angle = AllBones[AllBones[t].MirrorIndex].Angle;
                }
            }
            Update();
        }
        /// <summary>
        /// 镜像右侧
        /// </summary>
        public void MirrorRight()
        {
            for (int t = 0; t < Count; t++)
            {
                if (AllBones[t].Position.X < 0 && AllBones[t].MirrorIndex > -1)
                {
                    AllBones[t].Angle = AllBones[AllBones[t].MirrorIndex].Angle;
                }
            }
            Update();
        }

        /// <summary>
        /// 读入模型资源文件和定义文件，新建机器人。
        /// </summary>
        /// <param name="modelfn">模型文件</param>
        /// <param name="datafn">文本文件</param>
        public Robot(string modelfn, string datafn)
        {
            RobotModel = new XFile(modelfn);
            UpdatedModel = new XFile(modelfn);

            System.IO.StreamReader sr;//字节流中按指定编码读字符
            sr = new System.IO.StreamReader(datafn);
            string tmpl;
            AllBones = new List<Bone>();//骨骼列表
            Transform = Matrix.Identity;//4*4矩阵
            
            while ((tmpl = sr.ReadLine()) != null)
            {
                if (tmpl.Length == 0)
                    continue;
                string[] tmpw = tmpl.Split(new char[] { ',' , '|' });//以，和|为分隔符号
                //给机器人的每个骨骼添加信息
                Bone tmpb = new Bone()
                {
                    //骨骼序号，父骨骼序号，模型序号，对称骨骼序号
                    Index = int.Parse(tmpw[0]),
                    ParentIndex = int.Parse(tmpw[1]),
                    Subset = int.Parse(tmpw[2]),
                    MirrorIndex = int.Parse(tmpw[3]),
                    //基础位置
                    Position = new Vector3(int.Parse(tmpw[4]), int.Parse(tmpw[5]), int.Parse(tmpw[6])),
                    //基础生长方向
                    Direction = new Vector3(int.Parse(tmpw[7]), int.Parse(tmpw[8]), int.Parse(tmpw[9])),
                    //基础旋转方向，左手系
                    Axis = new Vector3(int.Parse(tmpw[10]), int.Parse(tmpw[11]), int.Parse(tmpw[12])),
                    //当前角度，角度极限
                    AngleLimitA = float.Parse(tmpw[14]),
                    AngleLimitB = float.Parse(tmpw[15]),
                    Angle = float.Parse(tmpw[13]),
                    //骨骼名字
                    Name = tmpw[16],
                    //骨骼颜色
                    C = Color.FromArgb(240,int.Parse(tmpw[17]), int.Parse(tmpw[18]), int.Parse(tmpw[19])),
                    //骨骼零点，比例
                    Zero = int.Parse(tmpw[20]),
                    Proportion = float.Parse(tmpw[21])
                };
                tmpb.Pic = new Picture(tmpb.C);
                AllBones.Add(tmpb);
            }
            sr.Close();
            sr.Dispose();
        }

        /// <summary>
        /// 保存机器人文件
        /// </summary>
        /// <param name="datafn">将要保存的文件名</param>
        public void Save(string datafn)
        {
            System.IO.StreamWriter sr;
            sr = new System.IO.StreamWriter(datafn);

            for (int t = 0; t < Count; t++)
            {
                sr.Write(t);
                sr.Write(",");
                sr.Write(this[t].ParentIndex);
                sr.Write(",");
                sr.Write(this[t].Subset);
                sr.Write(",");
                sr.Write(this[t].MirrorIndex);
                sr.Write("|");

                sr.Write(this[t].Position.X);
                sr.Write(",");
                sr.Write(this[t].Position.Y);
                sr.Write(",");
                sr.Write(this[t].Position.Z);
                sr.Write("|");

                sr.Write(this[t].Direction.X);
                sr.Write(",");
                sr.Write(this[t].Direction.Y);
                sr.Write(",");
                sr.Write(this[t].Direction.Z);
                sr.Write("|");

                sr.Write(this[t].Axis.X);
                sr.Write(",");
                sr.Write(this[t].Axis.Y);
                sr.Write(",");
                sr.Write(this[t].Axis.Z);
                sr.Write("|");

                sr.Write(this[t].Angle);
                sr.Write(",");
                sr.Write(this[t].AngleLimitA);
                sr.Write(",");
                sr.Write(this[t].AngleLimitB);
                sr.Write("|");

                sr.Write(this[t].Name);
                sr.Write("|");

                sr.Write(this[t].C.R);
                sr.Write(",");
                sr.Write(this[t].C.G);
                sr.Write(",");
                sr.Write(this[t].C.B);
                sr.Write("|");

                sr.Write(this[t].Zero);
                sr.Write(",");
                sr.Write(this[t].Proportion);
                sr.WriteLine();
            }
            sr.Close();
            sr.Dispose();
        }
    }    
}
