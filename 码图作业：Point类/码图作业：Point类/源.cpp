#include<iostream>
#include"Point.h"
#include<stdlib.h>
using namespace std;
int main() {
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	Point A(a, b), B(c, d);
	cout << A.Distance(B) << endl;

	system("pause");
	return 0;
}
