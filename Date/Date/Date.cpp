#include "Date.h"

//构造函数
Date::Date(int year, int mouth, int day)
{
	_year = year;
	_mouth = mouth;
	_day = day;
	if (!Date_check())
		cout << "日期不合法" << endl;
}

//每个月的天数
int Date::Get_mouth_days()
{
	if (_mouth == 2 && ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0)))
		return 29;

	static int days[] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31 };
	return days[_mouth];
}

//检查日期合法性
bool Date::Date_check()
{
	if (_year == 0 || _mouth < 1 || _mouth > 12 || _day < 1 || _day > Get_mouth_days())
	{
		cout << "日期非法 重新输入" << endl;
		return false;
	}

	return true;
}

//打印日期(年/月/日)
void Date::Print()
{
	cout << _year << "年" << _mouth << "月" << _day << "日" << endl;
}

//小于号
bool Date::operator<(const Date& d)
{
	if (_year < d._year)
		return true;
	else if (_year == d._year && _mouth != d._mouth)
		return _mouth < d._mouth;
	else if (_year == d._year && _mouth == d._mouth)
		return _day < d._day;

	return false;
}

//小于等于号
bool Date::operator<=(const Date& d)
{
	return (*this < d || *this == d);
}

//大于号
bool Date::operator>(const Date& d)
{
	return !(*this <= d);
}
 
//大于等于号
bool Date::operator>=(const Date& d)
{
	return (*this > d || *this == d);
}

//等于号
bool Date::operator==(const Date& d)
{
	return (_year == d._year && _mouth == d._mouth && _day == d._day);
}

//不等于号
bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

//加等
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		*this -= -day;
		return *this;
	}

	_day += day;
	while (_day > Get_mouth_days())
	{
		_day -= Get_mouth_days();
		++_mouth;
		if (_mouth == 13)
		{
			++_year;
			_mouth = 1;
		}
	}

	return *this;
}

//减等
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		*this += -day;
		return *this;
	}

	_day -= day;
	while (_day < 1)
	{
		--_mouth;
		if (_mouth == 0)
		{
			--_year;
			_mouth = 12;
		}
		_day += Get_mouth_days();
	}
	
	return *this;
}

//前置++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

//后置++
Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;
	return tmp;
}

//前置--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

//后置--
Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;
	return tmp;
}

//日期 + 天数
Date Date::operator+(int day)
{
	Date tmp = *this;
	tmp += day;
	return tmp;
}

//日期 - 天数
Date Date::operator-(int day)
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}

//日期 - 日期
int Date::operator-(const Date& d)
{
	Date min = *this;
	Date max = d;
	int sign = 1;
	int result = 0;
	if (min > max)
	{
		max = min;
		min = d;
		sign = -1;
	}
	while (min != max)
	{
		++min;
		++result;
	}

	return result * sign;
}

//流插入
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "-" << d._mouth << "-" << d._day << endl;
	return out;
}

//流输出
istream& operator>>(istream& in, Date& d)
{
	do 
	{
		in >> d._year >> d._mouth >> d._day;
	} while (!d.Date_check());

	return in;
}
