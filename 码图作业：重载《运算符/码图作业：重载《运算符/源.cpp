#include<iostream>
#include<stdlib.h>
using namespace std;
class Date {
public:
	friend ostream & operator<<(ostream & out, Date & obj)
	{
		out << obj.year << "-" << obj.month << "-" << obj.day << endl;
		return out;
	}
	Date(int y = 1996, int m = 1, int d = 1) {
		day = d;
		month = m;
		year = y;
		if (m > 12 || m < 1)
		{
			month = 1;
		}
		if (d > days(y, m))
		{
			cout << "Invalid day!" << endl;
			day = 1;
		}
	};
	int days(int y, int m)
	{
		if ((y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0)))
		{
			if (m == 1 || m == 3 || m == 5 || m == 7
				|| m == 8 || m == 10 || m == 12)
			{
				return 31;
			}
			else if (m == 4 || m == 6 || m == 9 || m == 11)
			{
				return 30;
			}
			else return 29;
		}
		else
		{
			if (m == 1 || m == 3 || m == 5 || m == 7
				|| m == 8 || m == 10 || m == 12)
			{
				return 31;
			}
			else if (m == 4 || m == 6 || m == 9 || m == 11)
			{
				return 30;
			}
			else return 28;
		}
	}
	void display() {
		cout << year << "-" << month << "-" << day << endl;
	}
private:
	int year;
	int month;
	int day;
};

int main() 
{
		int y, m, d;
		cin >> y >> m >> d;
		Date dt(y, m, d);
		cout << dt;

		system("pause");
		return 0;
}
