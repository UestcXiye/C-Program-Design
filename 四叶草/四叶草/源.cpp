#include<graphics.h>
#include<math.h>
#include<conio.h>

# define PI 3.1415926535

int main()
{
	initgraph(640, 480);
	setcolor(GREEN);
	setorigin(320, 240);
	double e;
	int x1, x2, y1, y2;
	for (double a = 0; a < 2 * PI; a += 2 * PI / 720)
	{
		e = 100 * (1 + sin(4 * a));
		x1 = (int)(e*cos(a));
		y1 = (int)(e*sin(a));
		x2 = (int)(e*cos(a + PI / 5));
		y2 = (int)(e*sin(a + PI / 5));
		line(x1, y1, x2, y2);

		Sleep(20);
	}
	_getch();
	closegraph();
}