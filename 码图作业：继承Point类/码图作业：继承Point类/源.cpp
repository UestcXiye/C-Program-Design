#include<iostream>
#include"CPoint.h"
#include<stdlib.h>
using namespace std;
int main()
{
	Rectangle rect(1, 2, 3, 4);
	cout<<rect.Area()<<endl;     //12
	Circle c(5, 6, 7);
	cout<<c.Area()<<endl;      //153.86

	system("pause");
	return 0;
}