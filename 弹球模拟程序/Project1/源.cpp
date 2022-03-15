/*本程序根据物理原理模拟一个球自由落体并持续弹跳的效果，小球只受重力作用，反弹时速度耗损10%。*/
#include<graphics.h>
#include<conio.h>
int main()
{
	double h = 300;//高度
    double v = 0;//速度（方向向下）
	double dv = 9.8 / 50;//加速度（每1 / 50秒）
	//初始化绘图窗口
	initgraph(640, 480);
	//画地平线
	line(100, 421, 540, 421);
	while (!_kbhit())
	{
		v += dv;//根据加速度计算速度
		h -= (v - dv / 2);//计算高度
		//如果高度低于地平线，实现反弹，速度方向相反
		if (h <= 0)
		{
			h += (v - dv / 2);
			v = -v * 0.9;//反弹时能量耗损10%
		}
		//画绿色球
		setcolor(GREEN);
		circle(320, 400 - int(h), 20);
		Sleep(20);//延时（每帧1/50秒）
		//擦边球
		setcolor(BLACK);
		circle(320, 400 - int(h), 20);
	}
	//关闭绘图窗口
	closegraph();
}