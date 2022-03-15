#include"acllib.h"
#include"stdafx.h"
const int winWidth = 640, winHeight = 480;
int tomWidth = 100, tomHeight = 100;
ACL_Image img;
const char*tom = "»¬»ü.bmp";
void timerEvent(int id);
int Setup()
{
	initWindow("my first window", DEFAULT, DEFAULT, winWidth, winHeight);
	loadImage(tom, &img);
	registerTimerEvent(timerEvent);
	startTimer(0, 50);
	beginPaint();
	//putImage(&img, 0, 0);
	putImageScale(&img, 10, 10, tomWidth, tomHeight);
	endPaint();
	return 0;
}