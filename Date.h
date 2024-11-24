#pragma once
#include <iostream>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date() : Date{ 1,1, 1000 } {};
	Date(int day_S, int month_S, int year_S) : day{ day_S }, month{ month_S }, year{ year_S } {};

	const int get_day()
	{
		return day;
	}
	const int get_month()
	{
		return month;
	}
	const int get_year()
	{
		return year;
	}

	void set_day(const int day_S);
	void set_month(const int month_S);
	void set_year(const int year_S);

	Date& operator++();
	Date& operator--();

	friend bool operator!=(const Date& date1, const Date& date2)
	{
		if (date1.day != date2.day || date1.month != date2.month || date1.year != date2.year)
		{
			return true;
		}
		return false;
	}
	friend bool operator==(const Date& date1, const Date& date2)
	{
		if (date1.day == date2.day && date1.month == date2.month && date1.year == date2.year)
		{
			return true;
		}
		return false;
	}
	friend bool operator>(const Date& date1, const Date& date2)
	{
		if (date1.year > date2.year)
		{
			return true;
		}
		else if (date1.year == date2.year)
		{
			if (date1.month > date2.month)
			{
				return true;
			}
			else if (date1.month == date2.month)
			{
				if (date1.day > date2.day)
				{
					return true;
				}
			}
		}
		return false;
	}
	friend bool operator<(const Date& date1, const Date& date2)
	{
		if (date1.year < date2.year)
		{
			return true;
		}
		else if (date1.year == date2.year)
		{
			if (date1.month < date2.month)
			{
				return true;
			}
			else if (date1.month == date2.month)
			{
				if (date1.day < date2.day)
				{
					return true;
				}
			}
		}
		return false;
	}

	Date& operator=(const Date& date);

	friend const Date operator+=(Date& date, int days)
	{
		int buf = date.day + days, count = 0;  //1.1.1990 + 30 // buf = 31

		while (buf > 30) //buf = 1
		{
			buf -= 30; //31 -= 30 = 1
			count++; // count = 1
		}

		date.set_day(buf); // day = 1
		buf = date.month + count; // 1 + 1 = 2
		count = 0;

		while (buf > 12)
		{
			buf -= 1;
			count++;
		} 

		date.set_month(buf);
		date.set_year(date.year + count);

		return date;
	}
	friend const Date operator-=(Date& date, int days)
	{
		int buf = date.day - days, count = 0;//1.1.1991 - 360 buf = -359

		while (buf < 1) 
		{
			buf += 30; //buf = -359 + 330 = -29, -29 + 30 = 1
			count++; //count = 13
		}

		date.set_day(buf); // day = 1
		buf = date.month - count; // 1 - 13 = -12
		count = 0;

		while (buf < 1) 
		{
			buf += 12;
			count++;
		}

		date.set_month(buf); // month = 1
		date.set_year(date.year - count); // year + 0

		return date;
	}

	friend istream& operator>> (istream& my_cin, Date& date)
	{
		cout << "¬ведите день: ";
		cin >> date.day;
		cout << "¬ведите мес€ц: ";
		cin >> date.month;
		cout << "¬ведите год: ";
		cin >> date.year;

		return my_cin;
	}
	friend ostream& operator<< (ostream& my_cout, const Date& date)
	{
		printf("%d.%d.%d", date.day, date.month, date.year);

		return my_cout;
	}
};