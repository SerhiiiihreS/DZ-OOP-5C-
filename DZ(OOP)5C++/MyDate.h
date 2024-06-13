#pragma once
#include<iostream>
using namespace std;

class MyDate
{
private:
	int date;
	int month;
	int year;
public:
	MyDate() = default;
	MyDate(int dt);
	MyDate(int dt, int mt);
	MyDate(int dt, int mt, int yr);
	~MyDate();
	MyDate(const MyDate& b);

	void Setdate(int dt,int mt, int yr);
	void Setmonth(int mt);
	void Setyear(int yr);

	int Getdate()const;
	int Getmonth()const;
	int Getyear()const;

	void Print();

	MyDate& operator ++();
	MyDate& operator --();
	
	MyDate operator ++(int);
	MyDate operator --(int);

	MyDate operator +(int b);
	MyDate operator -(int b);

	/*MyDate& operator += ( MyDate& a, int b);*/




};

