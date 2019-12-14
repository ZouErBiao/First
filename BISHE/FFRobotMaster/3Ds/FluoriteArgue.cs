using Microsoft.VisualBasic;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using SlimDX;
using SlimDX.Direct3D9;
using System.Math;
/// <summary>
/// 表示一个碰撞盒。
/// </summary>
/// <remarks></remarks>
[Obsolete("推荐使用SlimDX.BoundingBox")]
public struct ArgueBox
{
	internal BoundingBox myBox;
	/// <summary>
	/// 通过两个对角点新建碰撞盒。
	/// </summary>
	/// <param name="A"></param>
	/// <param name="H"></param>
	/// <remarks></remarks>
	public ArgueBox(Vector3 A, Vector3 H)
	{
		float tmpa = 0;
		float tmpb = 0;
		float tmpc = 0;
		float tmpd = 0;
		float tmpe = 0;
		float tmpf = 0;
		tmpa = Min(A.X, H.X);
		tmpb = Max(A.X, H.X);
		tmpc = Min(A.Y, H.Y);
		tmpd = Max(A.Y, H.Y);
		tmpe = Min(A.Z, H.Z);
		tmpf = Max(A.Z, H.Z);
		myBox = new BoundingBox(new Vector3(tmpa, tmpc, tmpe), new Vector3(tmpb, tmpd, tmpf));
	}
	/// <summary>
	/// 通过一系列顶点新建碰撞盒。
	/// </summary>
	/// <param name="Vector3s"></param>
	/// <remarks>得到的碰撞盒能够包含所有的顶点。</remarks>
	public ArgueBox(Vector3[] Vector3s)
	{
		Vector3[] myV = null;
		int len = Vector3s.GetLength(0) - 1;
		 // ERROR: Not supported in C#: ReDimStatement

		int t = 0;
		for (t = 0; t <= len; t++) {
			myV(t) = Vector3s(t);
		}
		myBox = BoundingBox.FromPoints(myV);
	}
	/// <summary>
	/// 新建物体的碰撞盒。
	/// </summary>
	/// <param name="Model"></param>
	/// <remarks>得到的碰撞盒能够包含物体所有的顶点。</remarks>
	public ArgueBox(XModel Model)
	{
		int t = 0;
		int c = 0;
		Vector3[] myV = null;
		PositionNormalTextured[] myPNT = null;
		DataStream myStream = default(DataStream);
		VertexBuffer myBuffer = default(VertexBuffer);
		myBuffer = Model.myMesh.VertexBuffer;
		c = Model.myMesh.VertexCount;
		myStream = myBuffer.Lock(0, c * PositionNormalTextured.Length, LockFlags.None);
		myPNT = myStream.ReadRange<PositionNormalTextured>(c);
		 // ERROR: Not supported in C#: ReDimStatement

		for (t = 0; t <= c - 1; t++) {
			myV(t) = myPNT(t).Position;
		}
		myBox = BoundingBox.FromPoints(myV);
	}
	public float XMin {
		get { return myBox.Minimum.X; }
		set { myBox.Minimum.X = value; }
	}
	public float YMin {
		get { return myBox.Minimum.Y; }
		set { myBox.Minimum.Y = value; }
	}
	public float ZMin {
		get { return myBox.Minimum.Z; }
		set { myBox.Minimum.Z = value; }
	}
	public float XMax {
		get { return myBox.Maximum.X; }
		set { myBox.Maximum.X = value; }
	}
	public float YMax {
		get { return myBox.Maximum.Y; }
		set { myBox.Maximum.Y = value; }
	}
	public float ZMax {
		get { return myBox.Maximum.Z; }
		set { myBox.Maximum.Z = value; }
	}
	/// <summary>
	/// 返回碰撞盒的深度（Z轴）。
	/// </summary>
	/// <value></value>
	/// <returns></returns>
	/// <remarks></remarks>
	public float Depth {
		get { return myBox.Maximum.Z - myBox.Minimum.Z; }
	}
	/// <summary>
	/// 返回碰撞盒的宽度（X轴）。
	/// </summary>
	/// <value></value>
	/// <returns></returns>
	/// <remarks></remarks>
	public float Width {
		get { return myBox.Maximum.X - myBox.Minimum.X; }
	}
	/// <summary>
	/// 返回碰撞盒的高度（Y轴）。
	/// </summary>
	/// <value></value>
	/// <returns></returns>
	/// <remarks></remarks>
	public float Height {
		get { return myBox.Maximum.Y - myBox.Minimum.Y; }
	}
	/// <summary>
	/// 返回最小顶点。
	/// </summary>
	/// <value></value>
	/// <returns></returns>
	/// <remarks></remarks>
	public Vector3 A {
		get { return myBox.Minimum; }
		set { myBox.Minimum = value; }
	}
	/// <summary>
	/// 返回最大顶点。
	/// </summary>
	/// <value></value>
	/// <returns></returns>
	/// <remarks></remarks>
	public Vector3 H {
		get { return (myBox.Maximum); }
		set { myBox.Maximum = value; }
	}
	/// <summary>
	/// 检测此碰撞盒是否与另一个指定碰撞盒相交。
	/// </summary>
	/// <param name="Another"></param>
	/// <returns></returns>
	/// <remarks></remarks>
	public bool ArgueWith(ArgueBox Another)
	{
		return BoundingBox.Intersects(myBox, Another.myBox);
	}
	/// <summary>
	/// 检测此碰撞盒是否与指定碰撞球体相交。
	/// </summary>
	/// <param name="Sphere"></param>
	/// <returns></returns>
	/// <remarks></remarks>
	public bool ArgueWith(ArgueSphere Sphere)
	{
		return BoundingBox.Intersects(myBox, Sphere.mySphere);
	}
	/// <summary>
	/// 检测此碰撞盒是否与指定碰撞平面相交。
	/// </summary>
	/// <param name="Plane"></param>
	/// <returns></returns>
	/// <remarks></remarks>
	public bool ArgueWith(ArguePlane Plane)
	{
		return BoundingBox.Intersects(myBox, Plane.myPlane);
	}
	/// <summary>
	/// 检测此碰撞盒是否与指定射线相交。
	/// </summary>
	/// <param name="Ray"></param>
	/// <returns></returns>
	/// <remarks></remarks>
	public bool ArgueWith(ArgueRay Ray)
	{
		return BoundingBox.Intersects(myBox, Ray.myRay, Ray.myLength);
	}
	/// <summary>
	/// 检测此碰撞盒是否包含指定点。
	/// </summary>
	/// <param name="V"></param>
	/// <returns></returns>
	/// <remarks></remarks>
	public bool Contains(Vector3 V)
	{
		if (BoundingBox.Contains(myBox, V) > 0) {
			return true;
		} else {
			return false;
		}
	}
	/// <summary>
	/// 返回一个将当前碰撞盒指定平移的碰撞盒。
	/// </summary>
	/// <param name="TV"></param>
	/// <returns></returns>
	/// <remarks></remarks>
	public ArgueBox Translation(Vector3 TV)
	{
		return new ArgueBox(A + TV, H + TV);
	}
	/// <summary>
	/// 返回一个将当前碰撞盒指定缩放的碰撞盒。
	/// </summary>
	/// <param name="SV"></param>
	/// <returns></returns>
	/// <remarks>注意缩放以原点为基准。
	/// 所以通常要先进行缩放，再平移。</remarks>
	public ArgueBox Scaling(Vector3 SV)
	{
		Vector3 MyA = default(Vector3);
		Vector3 MyH = default(Vector3);
		MyA = A;
		MyH = H;
		var _with1 = SV;
		return new ArgueBox(new Vector3(MyA.X * _with1.X, MyA.Y * _with1.Y, MyA.Z * _with1.Z), new Vector3(MyH.X * _with1.X, MyH.Y * _with1.Y, MyH.Z * _with1.Z));
	}
}
/// <summary>
/// 表示一个碰撞球。
/// </summary>
/// <remarks></remarks>
[Obsolete("推荐使用SlimDX.BoundingSphere")]
public struct ArgueSphere
{
	internal BoundingSphere mySphere;
	/// <summary>
	/// 通过圆心和半径新建一个碰撞球。
	/// </summary>
	/// <param name="O"></param>
	/// <param name="R"></param>
	/// <remarks></remarks>
	public ArgueSphere(Vector3 O, float R)
	{
		mySphere = new BoundingSphere(O, R);
	}
	/// <summary>
	/// 通过一系列顶点新建一个碰撞球。
	/// </summary>
	/// <param name="Vector3s"></param>
	/// <remarks></remarks>
	public ArgueSphere(Vector3[] Vector3s)
	{
		Vector3[] myV = null;
		int len = Vector3s.GetLength(0) - 1;
		 // ERROR: Not supported in C#: ReDimStatement

		int t = 0;
		for (t = 0; t <= len; t++) {
			myV(t) = Vector3s(t);
		}
		mySphere = BoundingSphere.FromPoints(myV);
	}
	/// <summary>
	/// 通过一个模型新建一个碰撞球。
	/// </summary>
	/// <param name="Model"></param>
	/// <remarks></remarks>
	public ArgueSphere(XModel Model)
	{
		int t = 0;
		int c = 0;
		Vector3[] myV = null;
		PositionNormalTextured[] myPNT = null;
		DataStream myStream = default(DataStream);
		VertexBuffer myBuffer = default(VertexBuffer);
		myBuffer = Model.myMesh.VertexBuffer;
		c = Model.myMesh.VertexCount;
		myStream = myBuffer.Lock(0, c * PositionNormalTextured.Length, LockFlags.None);
		myPNT = myStream.ReadRange<PositionNormalTextured>(c);
		 // ERROR: Not supported in C#: ReDimStatement

		for (t = 0; t <= c - 1; t++) {
			myV(t) = myPNT(t).Position;
		}
		mySphere = BoundingSphere.FromPoints(myV);
	}
	/// <summary>
	/// 设置/返回球心。
	/// </summary>
	/// <value></value>
	/// <returns></returns>
	/// <remarks></remarks>
	public Vector3 Center {
		get { return (mySphere.Center); }
		set { mySphere.Center = value; }
	}
	/// <summary>
	/// 设置/返回半径。
	/// </summary>
	/// <value></value>
	/// <returns></returns>
	/// <remarks></remarks>
	public float Radius {
		get { return mySphere.Radius; }
		set { mySphere.Radius = value; }
	}
	/// <summary>
	/// 检测此碰撞球是否与另一个指定碰撞球相交。
	/// </summary>
	/// <param name="Another"></param>
	/// <returns></returns>
	/// <remarks></remarks>
	public bool ArgueWith(ArgueSphere Another)
	{
		return BoundingSphere.Intersects(mySphere, Another.mySphere);
	}
	/// <summary>
	/// 检测此碰撞球是否与指定碰撞盒相交。
	/// </summary>
	/// <param name="Box"></param>
	/// <returns></returns>
	/// <remarks></remarks>
	public bool ArgueWith(ArgueBox Box)
	{
		return BoundingSphere.Intersects(mySphere, Box.myBox);

	}

	/// <summary>
	/// 检测此碰撞球是否与指定碰撞平面相交。
	/// </summary>
	/// <param name="Plane"></param>
	/// <returns></returns>
	/// <remarks></remarks>
	public bool ArgueWith(ArguePlane Plane)
	{
		return BoundingSphere.Intersects(mySphere, Plane.myPlane);
	}
	/// <summary>
	/// 检测此碰撞球是否与指定射线相交。
	/// </summary>
	/// <param name="Ray"></param>
	/// <returns></returns>
	/// <remarks></remarks>
	public bool ArgueWith(ArgueRay Ray)
	{
		return BoundingSphere.Intersects(mySphere, Ray.myRay, Ray.myLength);
	}
	/// <summary>
	/// 返回一个碰撞球是否包含指定点。
	/// </summary>
	/// <param name="V"></param>
	/// <returns></returns>
	/// <remarks></remarks>
	public bool Contains(Vector3 V)
	{
		if (BoundingSphere.Contains(mySphere, V) > 0) {
			return true;
		} else {
			return false;
		}
	}
	/// <summary>
	/// 返回一个将当前碰撞球指定平移的碰撞球。
	/// </summary>
	/// <param name="V"></param>
	/// <returns></returns>
	/// <remarks></remarks>
	public ArgueSphere Translation(Vector3 V)
	{
		Vector3 MyO = Center;
		return new ArgueSphere(MyO + V, mySphere.Radius);
	}
}
/// <summary>
/// 表示一条射线，有长度。
/// </summary>
/// <remarks></remarks>
[Obsolete("推荐使用SlimDX.Ray")]
public struct ArgueRay
{
	internal Ray myRay;
	internal float myLength;
	/// <summary>
	/// 通过起点和终点新建射线。
	/// </summary>
	/// <param name="Position"></param>
	/// <param name="Destination"></param>
	/// <remarks></remarks>
	public ArgueRay(Vector3 Position, Vector3 Destination)
	{
		myRay = new Ray(Position, (Destination - Position));
		myLength = Vector3.Distance(Position, Destination);
		myRay.Direction.Normalize();
	}
	/// <summary>
	/// 通过起点，方向和长度新建射线。
	/// </summary>
	/// <param name="Position"></param>
	/// <param name="Direction"></param>
	/// <param name="Length"></param>
	/// <remarks></remarks>
	public ArgueRay(Vector3 Position, Vector3 Direction, float Length)
	{
		myRay = new Ray(Position, Direction);
		myLength = Length;
		myRay.Direction.Normalize();
	}
	/// <summary>
	/// 设置/返回射线的起点。
	/// </summary>
	/// <value></value>
	/// <returns></returns>
	/// <remarks></remarks>
	public Vector3 Position {
		get { return (myRay.Position); }
		set { myRay.Position = value; }
	}
	/// <summary>
	/// 返回射线的终点。
	/// </summary>
	/// <value></value>
	/// <returns></returns>
	/// <remarks></remarks>
	public Vector3 Destination {
		get { return this.Position + this.Direction * this.Length; }
	}
	/// <summary>
	/// 设置/返回射线的方向。
	/// </summary>
	/// <value></value>
	/// <returns></returns>
	/// <remarks></remarks>
	public Vector3 Direction {
		get { return (myRay.Direction); }
		set {
			myRay.Direction = value;
			myRay.Direction.Normalize();
		}
	}
	/// <summary>
	/// 设置/返回射线的长度。
	/// </summary>
	/// <value></value>
	/// <returns></returns>
	/// <remarks></remarks>
	public float Length {
		get { return myLength; }
		set { myLength = value; }
	}
	/// <summary>
	/// 检测此射线是否与指定碰撞盒相交。
	/// </summary>
	/// <param name="Box"></param>
	/// <returns></returns>
	/// <remarks></remarks>
	public bool Intersects(ArgueBox Box)
	{
		return Ray.Intersects(myRay, Box.myBox, myLength);
	}
	/// <summary>
	/// 检测此射线是否与指定碰撞球相交。
	/// </summary>
	/// <param name="Sphere"></param>
	/// <returns></returns>
	/// <remarks></remarks>
	public bool Intersects(ArgueSphere Sphere)
	{
		return Ray.Intersects(myRay, Sphere.mySphere, myLength);
	}
}
public enum PlaneArgueType
{
	Front = 0,
	Back = 1,
	Intersection = 2
}
/// <summary>
/// 表示碰撞平面。
/// </summary>
/// <remarks></remarks>
[Obsolete("推荐使用SlimDX.Plane")]
public struct ArguePlane
{
	internal Plane myPlane;
	/// <summary>
	/// 指定一点和法线，新建碰撞平面。
	/// </summary>
	/// <param name="Position"></param>
	/// <param name="Normal"></param>
	/// <remarks></remarks>
	public ArguePlane(Vector3 Position, Vector3 Normal)
	{
		myPlane = new Plane(Position, Normal);
		myPlane.Normalize();
	}
	/// <summary>
	/// 指定三个点，新建碰撞平面。
	/// </summary>
	/// <param name="PA"></param>
	/// <param name="PB"></param>
	/// <param name="PC"></param>
	/// <remarks></remarks>
	public ArguePlane(Vector3 PA, Vector3 PB, Vector3 PC)
	{
		myPlane = new Plane(PA, PB, PC);
		myPlane.Normalize();
	}
	/// <summary>
	/// 设置/返回碰撞平面的法线。
	/// </summary>
	/// <value></value>
	/// <returns></returns>
	/// <remarks></remarks>
	public Vector3 Normal {
		get { return (myPlane.Normal); }
		set {
			myPlane.Normal = value;
			myPlane.Normalize();
		}
	}
	/// <summary>
	/// 设置/返回碰撞平面到原点的距离。
	/// </summary>
	/// <value></value>
	/// <returns></returns>
	/// <remarks></remarks>
	public float D {
		get { return myPlane.D; }
		set { myPlane.D = value; }
	}
	/// <summary>
	/// 检测此平面是否与指定碰撞盒相交。
	/// </summary>
	/// <param name="Box"></param>
	/// <returns></returns>
	/// <remarks></remarks>
	public bool ArgueWith(ArgueBox Box)
	{
		return (Plane.Intersects(myPlane, Box.myBox) == PlaneIntersectionType.Intersecting);
	}
	/// <summary>
	/// 检测此平面是否与指定碰撞球相交。
	/// </summary>
	/// <param name="Sphere"></param>
	/// <returns></returns>
	/// <remarks></remarks>
	public bool ArgueWith(ArgueSphere Sphere)
	{
		return (Plane.Intersects(myPlane, Sphere.mySphere) == PlaneIntersectionType.Intersecting);
	}
	/// <summary>
	/// 检测此平面是否与制定射线相交，并输出交点。
	/// </summary>
	/// <param name="Ray"></param>
	/// <param name="ArgueAtPoint"></param>
	/// <returns></returns>
	/// <remarks></remarks>
	public bool ArgueWith(ArgueRay Ray, ref Vector3 ArgueAtPoint)
	{
		Vector3 tmpv = default(Vector3);
		bool tmpb = false;
		tmpb = Plane.Intersects(myPlane, Ray.Position, Ray.Destination, tmpv);
		ArgueAtPoint = (tmpv);
		return tmpb;
	}

}
/// <summary>
/// 计算2D图形的碰撞。
/// </summary>
/// <remarks></remarks>
public sealed class Argue2D
{
	/// <summary>
	/// 检测两个矩形区域是否相交。
	/// </summary>
	/// <param name="RA"></param>
	/// <param name="RB"></param>
	/// <returns></returns>
	/// <remarks></remarks>
	public bool Argue2DWith(Rectangle RA, Rectangle RB)
	{
		if (RA.Right >= RB.Left && RA.Left <= RB.Right && RA.Bottom > RB.Top && RA.Top <= RB.Bottom) {
			return true;
		} else {
			return false;
		}
	}
	/// <summary>
	/// 检测两个矩形区域是否相交。
	/// </summary>
	/// <param name="RA"></param>
	/// <param name="RB"></param>
	/// <returns></returns>
	/// <remarks></remarks>
	public bool Argue2DWith(RectangleF RA, RectangleF RB)
	{
		if (RA.Right >= RB.Left && RA.Left <= RB.Right && RA.Bottom > RB.Top && RA.Top <= RB.Bottom) {
			return true;
		} else {
			return false;
		}
	}
	/// <summary>
	/// 检测矩形区域是否包含指定点。
	/// </summary>
	/// <param name="R"></param>
	/// <param name="P"></param>
	/// <returns></returns>
	/// <remarks></remarks>
	public bool Contains(Rectangle R, Point P)
	{
		if (P.X >= R.Left && P.X <= R.Right && P.Y >= R.Top && P.Y <= R.Bottom) {
			return true;
		} else {
			return false;
		}
	}
	/// <summary>
	/// 检测矩形区域是否包含指定点。
	/// </summary>
	/// <param name="R"></param>
	/// <param name="P"></param>
	/// <returns></returns>
	/// <remarks></remarks>
	public bool Contains(RectangleF R, PointF P)
	{
		if (P.X >= R.Left && P.X <= R.Right && P.Y >= R.Top && P.Y <= R.Bottom) {
			return true;
		} else {
			return false;
		}
	}
}
