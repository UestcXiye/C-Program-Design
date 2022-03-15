#include"acllib.h"
const int winWidth = 640, winHeight = 480;
int tomWidth = 100,tomHeight = 100;
ACL_Image img;
const char*tom = "»¬»ü.bmp";
void timerEvent(int id);
int id = 0, timerInterval = 40;
int x = 10, y = 10, dist = 3;
void paint();
int Setup()
{
	initWindow("my first window", DEFAULT, DEFAULT, winWidth, winHeight);
	loadImage(tom, &img);
	registerTimerEvent(timerEvent);
	startTimer(id, timerInterval);
	paint();
	return 0;
}
void timerEvent(int id)
{
	if (id == 0)
	{
		x += dist;
		if (x > winWidth-tomWidth||x<=0)dist *= -1;
		paint();
	}

}
void paint()
{
	beginPaint();
	//putImage(&img, 0, 0);
	clearDevice();
	putImageScale(&img, x, y, tomWidth, tomHeight);
	endPaint();
}