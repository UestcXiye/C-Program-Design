#pragma once
#include<iostream>
#include<math.h>
using namespace std;
class Point
{
private:
	double A, B;
public:
	Point(double a, double b);
	double Distance(const Point &p);
};
Point::Point(double a, double b)
{
	A = a; B = b;
}
double Point::Distance(const Point &p)
{
	A -= p.A; B -= p.B;
	return sqrt(A*A + B * B);
}
