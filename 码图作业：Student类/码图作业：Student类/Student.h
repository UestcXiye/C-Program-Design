#pragma once
#include<iostream>
#include<string.h>
using namespace std;
class Student
{
private:
	char Name[10];//Ñ§ºÅ
	char Num[12];//ĞÕÃû
	int grade1, grade2, grade3;
public:
	Student(char name[],char num[],int grade1,int grade2,int grade3);
	void display();
	double average1(const Student &s1, const Student &s2);
	double average2(const Student &s1, const Student &s2);
	double average3(const Student &s1, const Student &s2);
};
Student::Student(char name[], char num[], int g1, int g2, int g3)
{
	strcpy_s(Name, name); strcpy_s(Num, num); grade1 = g1; grade2 = g2; grade3 = g3;
}
void Student::display()
{
	cout << Name << " " << Num << " " << grade1 << " " << grade2 << " " << grade3 << endl;
}
double Student::average1(const Student &s1, const Student &s2)
{
	return (s1.grade1 + s2.grade1 + grade1)/3.0;
}
double Student::average2(const Student &s1, const Student &s2)
{
	return (s1.grade2 + s2.grade2 + grade2)/3.0;
}
double Student::average3(const Student &s1, const Student &s2)
{
	return (s1.grade3 + s2.grade3 + grade3)/3.0;
}


int main() 
{
	Student *stu1, *stu2, *stu3;
	char name1[10], name2[10], name3[10];
	char num1[12], num2[12], num3[12];
	int grade1[3], grade2[3], grade3[3];
	cin >> name1 >> num1 >> grade1[0] >> grade1[1] >> grade1[2];
	cin >> name2 >> num2 >> grade2[0] >> grade2[1] >> grade2[2];
	cin >> name3 >> num3 >> grade3[0] >> grade3[1] >> grade3[2];
	stu1 = new Student(name1, num1, grade1[0], grade1[1], grade1[2]);
	stu2 = new Student(name2, num2, grade2[0], grade2[1], grade2[2]);
	stu3 = new Student(name3, num3, grade3[0], grade3[1], grade3[2]);

	stu1->display();
	stu2->display();
	stu3->display();

	cout << "The average grade of course1:" << stu2->average1(*stu1, *stu3) << endl;
	cout << "The average grade of course2:" << stu2->average2(*stu1, *stu3) << endl;
	cout << "The average grade of course3:" << stu2->average3(*stu1, *stu3) << endl;

	/*
	elete stu1;
	delete stu2;
	delete stu3;
	*/

	system("pause");
	return 0;
}