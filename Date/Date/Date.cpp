#include "Date.h"

//���캯��
Date::Date(int year, int mouth, int day)
{
	_year = year;
	_mouth = mouth;
	_day = day;
	if (!Date_check())
		cout << "���ڲ��Ϸ�" << endl;
}

//ÿ���µ�����
int Date::Get_mouth_days()
{
	if (_mouth == 2 && ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0)))
		return 29;

	static int days[] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31 };
	return days[_mouth];
}

//������ںϷ���
bool Date::Date_check()
{
	if (_year == 0 || _mouth < 1 || _mouth > 12 || _day < 1 || _day > Get_mouth_days())
	{
		cout << "���ڷǷ� ��������" << endl;
		return false;
	}

	return true;
}

//��ӡ����(��/��/��)
void Date::Print()
{
	cout << _year << "��" << _mouth << "��" << _day << "��" << endl;
}

//С�ں�
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

//С�ڵ��ں�
bool Date::operator<=(const Date& d)
{
	return (*this < d || *this == d);
}

//���ں�
bool Date::operator>(const Date& d)
{
	return !(*this <= d);
}
 
//���ڵ��ں�
bool Date::operator>=(const Date& d)
{
	return (*this > d || *this == d);
}

//���ں�
bool Date::operator==(const Date& d)
{
	return (_year == d._year && _mouth == d._mouth && _day == d._day);
}

//�����ں�
bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

//�ӵ�
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

//����
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

//ǰ��++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

//����++
Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;
	return tmp;
}

//ǰ��--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

//����--
Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;
	return tmp;
}

//���� + ����
Date Date::operator+(int day)
{
	Date tmp = *this;
	tmp += day;
	return tmp;
}

//���� - ����
Date Date::operator-(int day)
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}

//���� - ����
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

//������
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "-" << d._mouth << "-" << d._day << endl;
	return out;
}

//�����
istream& operator>>(istream& in, Date& d)
{
	do 
	{
		in >> d._year >> d._mouth >> d._day;
	} while (!d.Date_check());

	return in;
}
