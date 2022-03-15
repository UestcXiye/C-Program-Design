#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
class Point
{
private:
	double X, Y;
public:
	Point(double x, double y)
	{
		X = x; Y = y;
	}
	friend double Distance(Point a, Point b)
	{
		double dx, dy;
		dx = a.X - b.X;
		dy = a.Y - b.Y;
		return sqrt(dx*dx + dy * dy);
	}
};
int main()
{
	Point p1(3.0, 5.0);
	Point p2(4.0, 6.0);
	double d = Distance(p1, p2);
	cout << "The distance is " << d << endl;

	system("pause");
	return 0;
}


