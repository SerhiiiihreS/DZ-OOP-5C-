#include "MyDate.h"




MyDate::MyDate(int dt, int mt, int yr) 
{
	date = dt;
	month = mt;
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
	if ( mt ==1 && dt>0 && dt<32 && yr>0|| mt == 3 && dt>0 && dt < 32 && yr>0 || mt == 5 && dt>0 && dt < 32 && yr>0 || mt == 7 && dt>0 && dt < 32 && yr>0 || mt == 8 && dt>0 && dt < 32 && yr>0 || mt == 10 && dt>0 && dt < 32 && yr>0 || mt == 12 && dt>0 && dt < 32 && yr>0) {
			date = dt;
			cout << "Date-> " << date << endl ; 
		}
	else if (dt > 0 && dt < 31 && mt == 4 && yr>0 || dt > 0 && dt < 31 && mt==6 && yr>0 || dt > 0 && dt < 31 && mt==9 && yr>0 || dt > 0 && dt < 31 && mt==11 && yr>0) {
			date = dt;
			cout << "Date-> " << date << endl ;
		}
	else if (dt>0 && dt<29 && mt == 2 && yr % 100 > 0 && yr % 400 > 0 && yr > 0 || dt > 0 && dt < 29 && mt == 2 && yr%100>0 && yr % 4 > 0 && yr > 0)  {
			date = dt; 
			cout << "Date-> " << date << endl ;
	}
	else if (dt > 0 && dt < 30 && mt == 2 && yr % 100 == 0 && yr % 400 == 0 && yr>0 || dt > 0 && dt < 30 && mt == 2 && yr % 100>0 && yr % 4 == 0 && yr > 0) {
		date = dt; 
		cout << "Date-> " << date << endl; 
	}
	else {
		cout << "The date entered is incorrect. Please re-enter."<<endl; 
	}


	if (mt > 0 && mt < 13 && yr>0)  {
		month = mt;
		cout << "Month-> " << month<<endl; 
	}
	else {
		cout << "The month entered is incorrect. Please re-enter." << endl; 
	}



	if (yr > 0)  {
		year = yr; 
		cout << "Year-> " << year << endl ;
	}
	else {
		cout << "The year entered is incorrect. Please re-enter." << endl; 
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
	cout << "Date ->" << date << endl << "Month ->" << month << endl << "Year ->" << year << endl;
}

MyDate& MyDate::operator++()
{
	if (this->month == 1 && this->date > 0 && this->date < 32 && this->year>0 || this->month == 3 && this->date > 0 && this->date < 32 && this->year>0 || this->month == 5 && this->date > 0 && this->date < 32 && this->year>0 || this->month == 7 && this->date > 0 && this->date < 32 && this->year>0 || this->month == 8 && this->date > 0 && this->date < 32 && this->year>0 || this->month == 10 && this->date > 0 && this->date < 32 && this->year>0 || this->month == 12 && this->date > 0 && this->date < 32 && this->year>0) {
		if (this->date == 31 && this->month!=12) {
			this->date -= 30;
			this->month += 1;
		}
		else if (this->date == 31 && this->month == 12) {
			this->date -= 30;
			this->month -= 11;
			this->year += 1;

		}
		else {
			this->date += 1;
		}
	}
	else if (this->date > 0 && this->date < 31 && this->month == 4 && this->year>0 || this->date > 0 && this->date < 31 && this->month == 6 && this->year>0 || this->date > 0 && this->date < 31 && this->month == 9 && this->year>0 || this->date > 0 && this->date < 31 && this->month == 11 && this->year>0) {
		if (this->date == 30 ) {
			this->date -= 29;
			this->month += 1;
		}
	}
	else if (this->date > 0 && this->date < 29 && this->month == 2 && this->year % 100 > 0 && this->year % 400 > 0 && this->year > 0 || this->date > 0 && this->date < 29 && this->month == 2 && this->year % 100>0 && this->year % 4 > 0 && this->year > 0) {
	}
	else if (this->date > 0 && this->date < 30 && this->month == 2 && this->year % 100 == 0 && this->year % 400 == 0 && this->year>0 || this->date > 0 && this->date < 30 && this->month == 2 && this->year % 100>0 && this->year % 4 == 0 && this->year > 0) {
	}
	return *this;
	
}

MyDate& MyDate::operator--()
{
	for (int i = 0; i < 7; i++) {
		if (this->date = 1 && this->month == 1) {
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
		if (this->date = 30 && this->month == 3) {
			this->date += 30;
			this->month -= 1;
			j = 4;
		}
	}
	if (this->date == 1 && this->month == 3 && this->year % 100 > 0 && this->year % 400 > 0 || this->year % 100 > 0 && this->year % 4 > 0) {
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
		if (date = 31 && month == 1) {
			date == 1;
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
		if (date = 30 && month == 3) {
			date -= 29;
			month += 1;
			j = 4;
		}
	}
	 if (date == 28 && month == 2 && year % 100 > 0 && year % 400 > 0 || year % 100 > 0 && year % 4 > 0) {
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
		if (date = 1 && month == 1) {
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
		if (date = 30 && month == 3) {
			date += 30;
			month -= 1;
			j = 4;
		}
	}
	if (date == 1 && month == 3 && year % 100 > 0 && year % 400 > 0 || year % 100 > 0 && year % 4 > 0) {
		date += 27;
		month -= 1;
	}
	else {
		date -= 1;
	}
	return temp;
}

//MyDate MyDate::operator+(int b)
//{
//}
//
//MyDate MyDate::operator-(int b)
//{
//}
//



