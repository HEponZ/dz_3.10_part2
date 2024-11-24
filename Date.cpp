#include "Date.h"
void Date::set_day(const int day_S)
{
	if (day > 30 && day < 0)
	{
		cout << "Îøèáêà\n";
		return;
	}
	day = day_S;
}
void Date::set_month(const int month_S)
{
	if (month > 12 && month < 0)
	{
		cout << "Îøèáêà\n";
		return;
	}
	month = month_S;
}
void Date::set_year(const int year_S)
{
	if (year < 0)
	{
		cout << "Îøèáêà\n";
		return;
	}
	year = year_S;
}

Date& Date::operator++()
{
	if (day == 30)
	{
		if (month == 12)
		{
			day = 1;
			month = 1;
			year++;
			return*this;
		}
		day = 1;
		month++;
		return *this;
	}
	day++;

	return *this;
}
Date& Date::operator--()
{
	if (day == 1)
	{
		if (month == 1)
		{
			day = 30;
			month = 12;
			year--;
			return *this;
		}
		day = 30;
		month--;
		return *this;
	}
	day--;
	return *this;
}

Date& Date::operator=(const Date& date)
{
	if (this == &date)
	{
		return *this;
	}

	day = date.day;
	month = date.month;
	year = date.year;

	return *this;
}