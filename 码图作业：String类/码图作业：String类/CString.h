#pragma once
#include <iostream>
#include<string.h>
using namespace std;
class String 
{
private:
	char *mystr;    //×Ö·û´®
	int len;    //×Ö·û´®³¤¶È
public:
	String() {
		len = 0;
		mystr = NULL;
	}
	String(const char* p) {
		len = strlen(p);
		mystr = new char[len + 1];
		strcpy(mystr, p);
	}
	String(String &s) {
		len = s.len;
		if (len != 0)
		{
			mystr = new char[len + 1];
			strcpy(mystr, s.mystr);
		}
	}
	~String() {
		if (mystr != NULL)
		{
			delete[]mystr;
			mystr = NULL;
			len = 0;
		}
	}

	char *GetStr() { return mystr; }
	void ShowStr() { cout << mystr; }

	bool IsSubstring(const char *str);
	bool IsSubstring(const String &str);
	int str2num();
	void toUppercase();
};
bool String::IsSubstring(const char *str)
{
	char *strstr(const char * mystr, const char * str);
	if (strstr)
		return true;
	else
		return false;
}
bool String::IsSubstring(const String &str)
{
	char *strstr(const char * mystr, const  char *str);
	if (strstr)
		return true;
	else
		return false;
}
int String::str2num()
{
	int l = strlen(mystr);
	for (int i = 0; i < l; i++)
	{
		if (mystr[i] >= '0'&&mystr[i] <= '9') return mystr[i] - 48;
	}
}
void String::toUppercase()
{
	int l = strlen(mystr);
	for (int i = 0; i < l; i++)
	{
		if (mystr[i] >= 'a'&&mystr[i] <= 'z') mystr[i] -= 32;
	}
}

