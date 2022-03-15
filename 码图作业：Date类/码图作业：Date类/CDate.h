#pragma once
#include<iostream>
using namespace std;
class Date {
public:
	Date(int y, int m, int d);
	int days(int year, int month);
	void NewDay();
	void display()
	{
		cout << year << "-" << month << "-" << day << endl;
	}
private:
	int year; //Äê
	int month; //ÔÂ
	int day;  // ÈÕ
};
Date::Date(int y, int m, int d)
{
	year = y;
	if (m >= 1 && m <= 12) month = m;
	else {
		cout << "Invalid month!"<<endl;
		month = 1;
	}
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
	{
		if (month == 1 || month == 3 || month == 5 || month == 7
			|| month == 8 || month == 10 || month == 12)
		{
			if (d > 0 && d <= 31) day = d;
			else
			{
				cout << "Invalid day!" << endl;
				day = 1;
			}
		}
		else if(month==4|| month == 6|| month == 9|| month == 11)
		{
			if (d > 0 && d <= 30) day = d;
			else
			{
				cout << "Invalid day!" << endl;
				day = 1;
			}
		}
		else
		{
			if (d > 0 && d <= 29) day = d;
			else
			{
				cout << "Invalid day!" << endl;
				day = 1;
			}
		}
	}
	else
	{
		if (month == 1 || month == 3 || month == 5 || month == 7
			|| month == 8 || month == 10 || month == 12)
		{
			if (d > 0 && d <= 31) day = d;
			else
			{
				cout << "Invalid day!" << endl;
				day = 1;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (d > 0 && d <= 30) day = d;
			else
			{
				cout << "Invalid day!" << endl;
				day = 1;
			}
		}
		else
		{
			if (d > 0 && d <= 28) day = d;
			else
			{
				cout << "Invalid day!" << endl;
				day = 1;
			}
		}
	}
}
int Date::days(int year, int month)
{
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
	{
		if (month == 1 || month == 3 || month == 5 || month == 7
			|| month == 8 || month == 10 || month == 12)
		{
			return 31;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			return 30;
		}
		else return 29;
	}
	else
	{
		if (month == 1 || month == 3 || month == 5 || month == 7
			|| month == 8 || month == 10 || month == 12)
		{
			return 31;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			return 30;
		}
		else return 28;
	}
}
void Date::NewDay()
{
	day += 1;
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
	{
		if (month == 1 || month == 3 || month == 5 || month == 7
			|| month == 8 || month == 10 || month == 12)
		{
			if (day > 31){day = 1; month += 1;}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if(day>30){day = 1; month += 1;}
		}
		else 
		{
			if(day>29){ day = 1; month += 1;}
		}
	}
	else
	{
		if (month == 1 || month == 3 || month == 5 || month == 7
			|| month == 8 || month == 10 || month == 12)
		{
			if (day > 31) { day = 1; month += 1; }
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day > 30) { day = 1; month += 1; }
		}
		else
		{
			if (day > 28) { day = 1; month += 1; }
		}
	}
	if (month > 12) { month = 1; year += 1; }
}