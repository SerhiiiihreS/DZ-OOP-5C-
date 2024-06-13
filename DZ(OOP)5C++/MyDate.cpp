#include "MyDate.h"

int arr31[7] = { 1,3,5,7,8,10,12 };
int arr30[4] = { 4,6,9,11 };



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
			i = 7;
		}
	}
	for (int j = 0; j < 4; j++) {
		if (dt > 0 && dt < 31 && mt == arr30[j]) {
			date = dt;
			j = 4;
		}
	}

	if(dt>0 && dt<30 && mt == 2 && yr % 100 == 0 && yr % 400 = 0 ||yr%100>0 && yr % 4 == 0)  {
			date = dt;
	}
	else if (dt>0 && dt<29 && mt == 2 && yr % 100 > 0 && yr % 400 > 0 ||yr%100>0 && yr % 4 > 0) {
			date = dt; 
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

void MyDate::Print()
{
}

MyDate& MyDate::operator++()
{
	for (int i = 0; i < 7; i++) {
		if (this->date = 31 && this->month == arr31[i]) {
			this->date -= 30;
			i = 7;
			if (this->month == 12) {
				this->month -= 11;
				this->year += 1;
			}
			else if (this->month != 12) {
				this->month += 1;
			}
		}
	}
	for (int j = 0; j < 4; j++) {
		if (this->date = 30 && this->month == arr30[j]) {
			this->date -= 29;
			this->month += 1;
			j = 4;
		}
	}
	if (this->date == 29 && this->month == 2 && this->year % 100 == 0 && this->year % 400 = 0 || this->year % 100 > 0 && this->year % 4 == 0) {
		this->date -= 28;
		this->month += 1;
	}
	else if (this->date == 28 && this->month == 2 && this->year % 100 > 0 && this->year % 400 > 0 || this->year % 100 > 0 && this->year % 4 > 0) {
		this->date -= 27;
		this->month += 1;
	}
	else {
		this->date += 1;
	}
	return *this;
	
}

MyDate& MyDate::operator--()
{
	for (int i = 0; i < 7; i++) {
		if (this->date = 1 && this->month == arr31[i]) {
			this->date += 29;
			i = 7;
			if (this->month == 1) {
				this->month += 11;
				this->year -= 1;
			}
			else if (this->month != 12) {
				this->month -= 1;
			}
		}
	}
	for (int j = 0; j < 4; j++) {
		if (this->date = 30 && this->month == arr30[j]) {
			this->date += 30;
			this->month -= 1;
			j = 4;
		}
	}
	if (this->date == 1 && this->month == 3 && this->year % 100 == 0 && this->year % 400 = 0 || this->year % 100 > 0 && this->year % 4 == 0) {
		this->date += 28;
		this->month -= 1;
	}
	else if (this->date == 1 && this->month == 3 && this->year % 100 > 0 && this->year % 400 > 0 || this->year % 100 > 0 && this->year % 4 > 0) {
		this->date += 27;
		this->month -= 1;
	}
	else {
		this->date -= 1;
	}
	return *this;
	
}

MyDate MyDate::operator++(int)
{
	MyDate temp(this->date, this->month, this->year);
	for (int i = 0; i < 7; i++) {
		if (date = 31 && month == arr31[i]) {
			date -= 30;
			i = 7;
			if (month == 12) {
				month -= 11;
				year += 1;
			}
			else if (month != 12) {
				month += 1;
			}
		}
	}
	for (int j = 0; j < 4; j++) {
		if (date = 30 && month == arr30[j]) {
			date -= 29;
			month += 1;
			j = 4;
		}
	}
	if (date == 29 && month == 2 && year % 100 == 0 && year % 400 = 0 || year % 100 > 0 && year % 4 == 0) {
		date -= 28;
		month += 1;
	}
	else if (date == 28 && month == 2 && year % 100 > 0 && year % 400 > 0 || year % 100 > 0 && year % 4 > 0) {
		date -= 27;
		month += 1;
	}
	else {
		date += 1;
	}
	return temp;
}

MyDate MyDate::operator--(int)
{
	MyDate temp(this->date, this->month, this->year); 
	for (int i = 0; i < 7; i++) {
		if (date = 1 && month == arr31[i]) {
			date += 29;
			i = 7;
			if (month == 1) {
				month += 11;
				year -= 1;
			}
			else if (month != 12) {
				month -= 1;
			}
		}
	}
	for (int j = 0; j < 4; j++) {
		if (date = 30 && month == arr30[j]) {
			date += 30;
			month -= 1;
			j = 4;
		}
	}
	if (date == 1 && month == 3 && year % 100 == 0 && year % 400 = 0 || year % 100 > 0 && year % 4 == 0) {
		date += 28;
		month -= 1;
	}
	else if (date == 1 && month == 3 && year % 100 > 0 && year % 400 > 0 || year % 100 > 0 && year % 4 > 0) {
		date += 27;
		month -= 1;
	}
	else {
		date -= 1;
	}
	return temp;
}

MyDate MyDate::operator+(int b)
{

	return MyDate();
}

MyDate MyDate::operator-(int b)
{
	return MyDate();
}




