#include<iostream>
#include"CString.h"
#include<stdlib.h>
using namespace std;
int main()
{
	char s1[10];
	cin >> s1;
	String s(s1);
	s.str2num();

	system("pause");
	return 0;
}