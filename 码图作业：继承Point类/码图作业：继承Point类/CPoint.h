#pragma once
#include <iostream>
using namespace std;
class Point {
public:
	Point(float xx, float yy) {
		x = xx;
		y = yy;
	}
private:
	float x;
	float y;
};
class Rectangle :public Point {
public:
	Rectangle(float xx, float yy, float w, float h);
	float Area();
private:
	float width;
	float high;
};
Rectangle::Rectangle(float xx, float yy, float w, float h):Point(xx,yy)
{
	width = w; high = h;
}
float Rectangle::Area()
{
	float s;
	s = width * high;
	return s;
}
class Circle :public Point {
public:
	Circle(float xx, float yy, float r);
	float Area();
private:
	float radius;
};
Circle::Circle(float xx, float yy, float r) :Point(xx, yy)
{
	radius = r;
}
float Circle::Area()
{
	float s;
	s = 3.14*radius*radius;
	return s;
}

