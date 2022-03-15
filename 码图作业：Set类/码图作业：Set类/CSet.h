#pragma once
#include <iostream>
using namespace std;
class Set {
private:
	int n;
	int * pS; //集合元素
public:
	Set() { n = 0; pS = NULL; }
	Set(Set &s) {
		n = s.n;
		if (n != 0)
		{
			pS = new  int[n + 1];
			for (int i = 1; i <= n; i++) //集合的下标从1开始，集合中不能有重复元素
				pS[i] = s.pS[i];
		}
	}
	~Set() {
		if (pS)
		{
			delete[]pS;
			pS = NULL;
			n = 0;
		}
	}
	void ShowElement()const { //输出集合的元素
		cout << "{";
		for (int i = 1; i < n; i++)
			cout << pS[i] << ",";
		if (IsEmpty())
			cout << "}" << endl;
		else cout << pS[n] << "}" << endl;
	}
	bool IsEmpty()const { return n ? false : true; } //判断集合是否为空
	int size() { return n; }
	bool IsElement(int e)const {
		for (int i = 1; i <= n; i++)
			if (pS[i] == e)
				return true;
		return  false;
	}
	bool operator <=(const Set &s)const;//this <= s判断当前集合是否包于集合s
	bool operator ==(const Set &s)const; //判断集合是否相等
	Set & operator +=(int e);    // 向集合中增减元素e
	Set & operator -=(int e);    //删除集合中的元素e

	Set operator |(const Set &s)const;  //集合并
	Set operator &(const Set &s)const;//集合交
	Set operator -(const Set &s)const; //集合差
};
Set & Set::operator+=(int e)
{
	Set s;
	int * a = NULL;
	int x = 1;
	for (int i = 1; i <= n; i++)
	{
		if (e == pS[i]) { x = 0; break; }
	}
	if (x == 0) 
	{ 
		s.n = n;
		s.pS = new int[n + 1]; 
	    for (int i = 1; i <= n; i++)
	    {
			s.pS[i] = pS[i];
	    }
	}
	else
	{
		a = new int[n + 2];
		for (int i = 1; i <= n; i++)
		{
			a[i] = pS[i];
		}
		a[n + 1] = e;
		delete[]pS;
		pS = new int[n + 2];
		for (int i = 1; i <= n + 1; i++)
		{
			pS[i] = a[i];
		}
		n++;
		s.n = n;
		s.pS = new int[s.n + 1];
		for (int i = 1; i <= n; i++)
		{
			s, pS[i] = pS[i];
		}
	}
	return s;
}
Set & Set::operator-=(int e)
{
	Set s;
	int * a = NULL;
	int x = 0;
	for (int i = 1; i <= n; i++)
	{
		if (pS[i] == e) { x = 1; break; }
	}
	if (x == 1)
	{
		a = new int[n + 1];
		for (int i = 1; i <= n; i++)
		{
			a[i] = pS[i];
		}
		delete[]pS;
		s.pS = new int[n];
		pS = new int[n];
		for (int i = 1, j = 1; j <= n - 1; i++)
		{
			if (a[i] != e)
			{
				pS[j] = a[i];
				s.pS[j] = a[i];
				j++;
			}
		}
		n--;
		s.n = n;
	}
	else
	{
		s.pS = new int[n + 1];
		for (int i = 1; i <= n; i++)
		{
			s.pS[i] = pS[i];
		}
		s.n = n;
	}
	return s;
}
bool Set::operator<=(const Set & s)const
{
	if (this->n <= 0) return 1;
	if (n > s.n) return 0;
	int i, j, k = 0;
	for (int i = 1; i <= n; i++)
	{
		for (j = 1; j <= s.n; j++)
		{
			if (pS[i] == s.pS[j])
			{
				k++; break;
			}
		}
	}
	if (k == n) return 1;
	return 0;
}
bool Set::operator==(const Set & s)const
{
	if (n != s.n) return 0;
	int i, j, k = 0;
	for (int i = 1; i <= n; i++)
	{
		for (j = 1; j <= s.n; j++)
		{
			if (pS[i] == s.pS[j])
			{
				k++; break;
			}
		}
	}
	if (k == n) return 1;
	else return 0;
}
Set Set::operator|(const Set & s)const
{
	Set set;
	int n1 = n,n2 = s.n;
	int j = 1,t=0,k=1;
	int * a = NULL;
	int * b = NULL;
	a = new int[n1 + 1];
	for (int i = 1; i <= n1; i++)
	{
		a[i] = pS[i];
	}
	if (n1 < n2)
	{
		b = new int[n1 + 1];
		for (int i = 1; i <= n1; i++)
		{
			for (int j = 1; j <= n2; j++)
			{
				if (pS[i] == s.pS[j]) { b[k] = pS[i]; k++; t++; break; }
			}
		}
	}
	else
	{
		b= new int[n2 + 1];
		for (int i = 1; i <= n2; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (s.pS[i] == pS[j]) { b[k] = s.pS[i]; k++; t++; break; }
			}
		}
	}
	set.pS = new int[n1 + n2 + 1 - t];
	set.n = n1 + n2 - t;
	for (int i = 1; i <= n1 + n2 - t; i++)
	{
		if (i <= n1) set.pS[i] = a[i];
		else
		{
			int x = 0;
			for (int z = 1; z <= n2; z++)
			{
				x = 0;
				for (k = 1; k <= t; k++)
				{
					if (b[k] == s.pS[z])
					{
						x = 1; break;
					}
				}
				if (x == 0) { set.pS[i] = s.pS[z]; }
			}
		}
	}
	return set;
}
Set Set::operator&(const Set & s)const
{
	Set set;
	int n1 = n, n2 = s.n;
	int j = 1, t = 0, k = 1;
	int * b = NULL;
	if (n1 < n2)
	{
		b = new int[n1 + 1];
		for (int i = 1; i <= n1; i++)
		{
			for (int j = 1; j <= n2; j++)
			{
				if (pS[i] == s.pS[j]) { b[k] == pS[i]; k++; t++; break; }
			}
		}
	}
	set.n = t;
	set.pS = new int[t + 1];
	for (int i = 1; i <= t; i++)
	{
		set.pS[i] = b[i];
	}
	return set;
}
Set Set::operator-(const Set & s)const
{
	Set set;
	int n1 = n, n2 = s.n;
	int j = 1, t = 0, k = 1;
	int * a = NULL, * b = NULL;
	if (n1 < n2)
	{
		b = new int[n1 + 1];
		for (int i = 1; i <= n1; i++)
		{
			for (int j = 1; j <= n2; j++)
			{
				if (pS[i] == s.pS[j]) { b[k] == pS[i]; k++; t++; break; }
			}
		}
	}
	else
	{
		b = new int[n1 + 1];
		for (int i = 1; i <= n1; i++)
		{
			for (int j = 1; j <= n2; j++)
			{
				if (s.pS[i] == pS[j]) { b[k] == s.pS[i]; k++; t++; break; }
			}
		}
	}
	a = new int[n1 + 1];
	for (int i = 1; i <= n1; i++)
	{
		a[i] = pS[i];
	}
	set.n = n1 - t;
	set.pS = new int[n1 - t + 1];
	int x = 0, i = 1;
	for (int k = 1; k <= n1; k++)
	{
		x = 0;
		for (int j = 1; j <= t; j++)
		{
			if (a[k] == b[j]) { x = 1; break; }
		}
		if (x == 0) { set.pS[i] = a[k]; i++; }
	}
	return set;
}

