#include "MyDate.h"

int arr31[7] = { 1,3,5,7,8,10,12 };



MyDate::MyDate(int dt)
{
	date = dt;
}

MyDate::MyDate(int dt, int mt):MyDate(dt)
{
	month = mt;
}

MyDate::MyDate(int dt, int mt, int yr):MyDate(dt,mt) 
{
	year = yr;
}


MyDate::~MyDate()
{
	date = 0;
	month = 0;
	year = 0;
}

MyDate::MyDate(const MyDate& b)
{
	date = b.date;
	month = b.month;
	year = b.year;
}

void MyDate::Setdate(int dt,int mt, int yr)
{
	for (int i = 0; i < 7; i++) {
		if (dt > 0 && dt < 32 && mt == arr31[i]) {
			date = dt;
		}
		else if (dt > 0 && dt < 31 && mt != arr31[i] && mt != 2) {
			date = dt;
		}
		else if (dt = 29 && mt == 2 && yr % 100 == 0 && yr % 400 = 0 || yr % 4 == 0) {
			date = dt;
		}
		else if (dt == 28 && mt == 2 && yr % 100 > 0 && yr % 400 > 0 || yr % 4 > 0) {
			date = dt; 
		}
	}

}

void MyDate::Setmonth(int mt)
{
	if (mt > 0 && mt < 13) {
		month = mt; 
	}
}

void MyDate::Setyear(int yr)
{
	if (yr > 0) {
		year = yr; 
	}
}

int MyDate::Getdate() const
{
	return date;
}

int MyDate::Getmonth() const
{
	return month;
}

int MyDate::Getyear() const
{
	return year;
}

MyDate MyDate::operator++(int) 
{

	return MyDate();
}

MyDate MyDate::operator--(int)
{
	return MyDate();
}

MyDate MyDate::operator+(int b)
{

	return MyDate();
}

MyDate MyDate::operator-(int b)
{
	return MyDate();
}




