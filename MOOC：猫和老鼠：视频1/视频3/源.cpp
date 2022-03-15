#include"acllib.h"
#include<time.h>
#include<stdio.h>
typedef struct rect
{
	int x, y;
	int w, h;
}rect;
const int winWidth = 640, winHeight = 480;
//int tomWidth = 100, tomHeight = 100;
//int jerryWidth = 50, jerryHeight = 50;
ACL_Image tomImg, jerryImg;
const char *tom = "ЛЌЛќ.bmp";
const char *jerry = "аІПо.bmp";

void timerEvent(int id);
void keyEvent(int key, int e);
int collision(rect r1, rect r2);
int moveid = 0, movetimerInterval = 40;
int createid = 1, createtimerInterval = 1000;
//int x=10, y=10, dist = 3;
void paint();
const int maxNum = 20;
int score = 0;
struct sprite
{
	//char *name;
	int width, height;
	int x, y;
	int distx, disty;

};

struct sprite tomSprite, *jerrySprite[maxNum] = { NULL };
int jerryNum = 0;
ACL_Sound snd;
int Setup()
{
	srand((unsigned)time(NULL));
	initWindow("my  first window", DEFAULT, DEFAULT, winWidth, winHeight);
	loadImage(tom, &tomImg);
	loadImage(jerry, &jerryImg);
	loadSound("tada.wav", &snd);
	tomSprite.width = 100;
	tomSprite.height = 100;
	tomSprite.distx = tomSprite.disty = 3;
	tomSprite.x = rand() % (winWidth - tomSprite.width);
	tomSprite.y = rand() % (winHeight - tomSprite.height);
	jerrySprite[jerryNum] = (struct sprite*)malloc(sizeof(struct sprite));
	jerrySprite[jerryNum]->width = 50;
	jerrySprite[jerryNum]->height = 50;
	jerrySprite[jerryNum]->distx = jerrySprite[jerryNum]->disty = 2;
	jerrySprite[jerryNum]->x = rand() % (winWidth - jerrySprite[jerryNum]->width);
	jerrySprite[jerryNum]->y = rand() % (winHeight - jerrySprite[jerryNum]->height);

	registerTimerEvent(timerEvent);
	startTimer(moveid, movetimerInterval);
	startTimer(createid, createtimerInterval);
	registerKeyboardEvent(keyEvent);
	paint();
	return 0;
}
void timerEvent(int id)
{
	int i;
	if (id == 0)
	{
		for (i = 0; i < jerryNum; ++i)
		{
			if (jerrySprite[i])
			{
				jerrySprite[i]->x += jerrySprite[i]->distx;
				jerrySprite[i]->y += jerrySprite[i]->disty;
				if (jerrySprite[i]->x >= winWidth - jerrySprite[i]->width || jerrySprite[i]->x <= 0)jerrySprite[i]->distx *= -1;
				if (jerrySprite[i]->y >= winHeight - jerrySprite[i]->height || jerrySprite[i]->y <= 0)jerrySprite[i]->disty *= -1;
			}
		}

	}
	if (id == 1)
	{
		if (jerryNum < maxNum) jerryNum++;

		if (jerryNum < maxNum && jerrySprite[jerryNum] == NULL)
		{
			jerrySprite[jerryNum] = (struct sprite*)malloc(sizeof(struct sprite));
			jerrySprite[jerryNum]->width = 50;
			jerrySprite[jerryNum]->height = 50;
			jerrySprite[jerryNum]->distx = jerrySprite[jerryNum]->disty = 2;
			jerrySprite[jerryNum]->x = rand() % (winWidth - jerrySprite[jerryNum]->width);
			jerrySprite[jerryNum]->y = rand() % (winHeight - jerrySprite[jerryNum]->height);
		}
	}
	paint();
}
void keyEvent(int key, int e)
{
	if (e != KEY_DOWN)return;
	switch (key)
	{
	case VK_UP:
		tomSprite.y -= tomSprite.disty;
		if (tomSprite.y <= 0)tomSprite.y = 0;
		break;
	case VK_DOWN:
		tomSprite.y += tomSprite.disty;
		if (tomSprite.y >= winHeight - tomSprite.height)tomSprite.y = winHeight - tomSprite.height;
		break;
	case VK_LEFT:
		tomSprite.x -= tomSprite.distx;
		if (tomSprite.x <= 0)tomSprite.x = 0;
		break;
	case VK_RIGHT:
		tomSprite.x += tomSprite.distx;
		if (tomSprite.x >= winWidth - tomSprite.width)tomSprite.x = winWidth - tomSprite.width;
		break;
	default:
		break;
	}
	rect r1, r2;
	r1.x = tomSprite.x;
	r1.y = tomSprite.y;
	r1.w = tomSprite.width;
	r1.h = tomSprite.height;
	for (int i = 0; i < jerryNum; ++i)
	{
		if (jerrySprite[i])
		{
			r2.x = jerrySprite[i]->x;
			r2.y = jerrySprite[i]->y;
			r2.w = jerrySprite[i]->width;
			r2.h = jerrySprite[i]->height;
			int c = collision(r1, r2);
			if (c)
			{
				playSound(snd, 0);
				score++;
				delete(jerrySprite[i]);
				jerrySprite[i] = NULL;
			}
		}
	}
	paint();
}
void paint()
{
	char txt[50];
	beginPaint();
	//putImage(&img, 0, 0);
	clearDevice();
	putImageScale(&tomImg, tomSprite.x, tomSprite.y, tomSprite.width, tomSprite.height);
	for (int i = 0; i < jerryNum - 1; ++i)
	{
		if (jerrySprite[i])
			putImageScale(&jerryImg, jerrySprite[i]->x, jerrySprite[i]->y, jerrySprite[i]->width, jerrySprite[i]->height);
	}
	char str[50];
	sprintf_s(str, "score:%d", score);
	setTextSize(30);
	paintText(10, 10, str);

	endPaint();
}
int collision(rect r1, rect r2) {
	int c = 1;
	if (r1.x < r2.x && r1.x + r1.w >r2.x) {
		if (r1.y > r2.y && r1.y < r2.y + r2.h)return c;
		if (r1.y <r2.y && r1.y + r1.h >r2.y)return c;
	}
	else {
		if (r1.x > r2.x && r2.x + r2.w > r1.x)
		{
			if (r1.y > r2.y && r1.y < r2.y + r2.h)return c;
			if (r1.y <r2.y && r1.y + r1.h >r2.y)return c;
		}
	}
	c = 0;
	return c;
}
