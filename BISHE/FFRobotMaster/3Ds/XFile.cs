using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using SlimDX;
using SlimDX.Direct3D9;
using FluoriteEngine;
using System.Drawing;

namespace FFRobotMaster
{
    public class XFile
    {
        public Mesh myMesh;
        public AttributeRange[] myAr;
        public Material[] myM;
        public int mySub;


        /// <summary>
        /// 导入.X模型文件
        /// </summary>
        /// <param name="FileName">.X文件的文件名和路径</param>
        public XFile(string FileName)
        {
            myMesh = Mesh.FromFile(Fluorite.Device, ((Fluorite.ResourcePath.Length) > 0 ? Fluorite.ResourcePath + "\\" + FileName : FileName), MeshFlags.Managed);
            myMesh.OptimizeInPlace(MeshOptimizeFlags.AttributeSort);

            myAr = myMesh.GetAttributeTable();

            mySub = myMesh.GetMaterials().Length;

            ExtendedMaterial[] tmpm = myMesh.GetMaterials();
            myM = new Material[tmpm.Length - 1];
            for (int t = 0; t < tmpm.Length - 1; t++)
            {
                Material tmpl = tmpm[t].MaterialD3D;
                tmpl.Ambient = Color.Gray;
                myM[t] = tmpl;
            }
        }

        /// <summary>
        /// 面数
        /// </summary>
        public int FaceCount
        {
            get
            {
                return myMesh.FaceCount;
            }
        }

        /// <summary>
        /// 获取模型的索引数量
        /// </summary>
        public int IndexCount
        {
            get
            {
                return myMesh.FaceCount * 3;
            }
        }

        /// <summary>
        /// 获取模型数
        /// </summary>
        public int SubsetCount
        {
            get
            {
                return mySub;
            }
        }

        /// <summary>
        /// 获取模型顶点数目
        /// </summary>
        public int VertexCount
        {
            get
            {
                return myMesh.VertexCount;
            }
        }

        /// <summary>
        /// 绘制模型
        /// </summary>
        /// <param name="M">指定的变换矩阵</param>
        /// <param name="SubSet">指定模型号</param>
        public void Draw(Matrix M, int SubSet = 0)
        {
            Fluorite.Device.SetTransform(TransformState.World, M);
            myMesh.DrawSubset(SubSet);
        }

        /// <summary>
        /// 绘制模型
        /// </summary>
        /// <param name="Position"></param>
        /// <param name="RotationY"></param>
        /// <param name="Scaling"></param>
        /// <param name="Subset"></param>
        public void Draw(Vector3 Position, float RotationY = 0, float Scaling = 1, int Subset = 0)
        {
            Fluorite.Device.SetTransform(TransformState.World, Matrix.Scaling(Scaling, Scaling, Scaling) * Matrix.RotationY(RotationY) * Matrix.Translation(Position));
            myMesh.DrawSubset(Subset);
        }
        
        /// <summary>
        /// 获取模型顶点列表数据
        /// </summary>
        /// <returns></returns>
        public DataStream LockVertex()
        {
            return myMesh.LockVertexBuffer(LockFlags.None);
        }

        /// <summary>
        /// 取消获得顶点列表的数据流
        /// </summary>
        public void UnLockVertex()
        {
            myMesh.UnlockVertexBuffer();
        }

        /// <summary>
        /// 获得索引列表的数据流
        /// </summary>
        /// <returns></returns>
        public DataStream LockIndex()
        {
            return myMesh.LockIndexBuffer(LockFlags.None);
        }

        /// <summary>
        /// 取消获取索引列表数据流
        /// </summary>
        public void UnLockIndex()
        {
            myMesh.UnlockIndexBuffer();
        }

        /// <summary>
        /// 返回模型子集与射线是否相交，并计算交点的距离。
        /// </summary>
        /// <param name="R"></param>
        /// <param name="Subset"></param>
        /// <param name="Distance"></param>
        /// <returns></returns>
        public bool Intersects(Ray R, int Subset, ref float Distance)
        {
            return myMesh.IntersectsSubset(R, Subset, out Distance);  
        }
    }
}

