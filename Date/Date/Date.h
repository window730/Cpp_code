#pragma once
#include <iostream>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);


public:
	Date(int year = 1, int mouth = 1, int day = 1);

	int Get_mouth_days();
	bool Date_check();
	void Print();

	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	Date& operator+=(int day);
	Date& operator-=(int day);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	Date operator+(int day);
	Date operator-(int day);
	int operator-(const Date& d);



private:
	int _year;
	int _mouth;
	int _day;
};

ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);
