

#include "stdafx.h"
#include "iostream"
using namespace std;
class CBaizhipeng
{
private:
	int year;
	int month;
	int day;
	int check();

public:
	CBaizhipeng();
	CBaizhipeng(int y, int m, int d);
	int setDate(int y, int m, int d);
	void displayBaizhipeng();
	void addOneDay();
	int getYear();
	int getMonth();
	int getDay();
};
CBaizhipeng::CBaizhipeng()
{
	year = 2019;
	month = 1;
	day = 1;
}
CBaizhipeng::CBaizhipeng(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	if (check() == 1 || check() == -1)
	{
		month = 1;
		day = 1;
		cout << "设置了错误日期，月日已置1" << endl;
	}

}
int CBaizhipeng::setDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	if (check() == 1 || check() == -1)
	{
		month = 1;
		day = 1;
		cout << "设置了错误日期，月日已置1" << endl;
		return -1;
	}
	return 0;

}
void CBaizhipeng::displayBaizhipeng()
{
	cout << year << "年" << month << "月" << day << "日" << endl;
}
int CBaizhipeng::check()
{
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (month > 12 || month < 1)
		return -1;
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day || day < 1)
			return 1;
	}
	else
	{
		if (flatYearDays[month - 1] < day || day < 1)
			return 1;
	}
	return 0;
}
int CBaizhipeng::getYear()
{
	return year;
}
int CBaizhipeng::getMonth()
{
	return month;
}
int CBaizhipeng::getDay()
{
	return day;
}
void CBaizhipeng::addOneDay()
{
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	day++;

	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day)
		{
			day = 1;
			month++;
		}
	}
	else
	{
		if (flatYearDays[month - 1] < day)
		{
			day = 1;
			month++;
		}
	}
	if (month > 12)
	{
		month = 1;
		year++;
	}

}
int main()
{
	CBaizhipeng od;

	int i;
	int count = 1;
	od.setDate(1999, 6, 13);
	od.displayBaizhipeng();
	while (!((od.getYear() == 2019) && (od.getMonth() == 4) && (od.getDay()) == 11))
	{
		od.addOneDay();
		count++;
	}
	cout << count << endl;
	return 0;
}