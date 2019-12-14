using SlimDX;
using SlimDX.Direct3D9;

namespace FFRobotMaster
{
    /// <summary>
    /// 顶点位置、法线和贴图坐标。
    /// </summary>
    /// <remarks></remarks>
    public struct PositionNormalTextureC : IVertex
    {
        public Vector3 Position;
        public Vector3 Normal;
        public Vector2 UV;
        public PositionNormalTextureC(Vector3 P, Vector3 N, Vector2 T)
        {
            Position = P;
            Normal = N;
            UV = T;
        }
        public static int Length()
        {
            return 32;
        }
        public static VertexFormat Format()
        {
            return VertexFormat.PositionNormal | VertexFormat.Texture1;
        }

        public SlimDX.Direct3D9.VertexFormat getFormat()
        {
            return VertexFormat.PositionNormal | VertexFormat.Texture1;
        }

        public int getLength()
        {
            return 32;
        }
    }

    public interface IVertex
    {
        int getLength();
        VertexFormat getFormat();
    }
}
