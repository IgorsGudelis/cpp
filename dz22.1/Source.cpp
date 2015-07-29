#include <iostream>
#include "dz22.2.h"

using namespace std;

void Date::Print() const
{
	cout << _day << " " << _month << " " << _year << endl;
}

Date & Date::operator+=(int incrDays)
{
	*this=*this + incrDays;
	return *this;
}

Date & Date::operator+(int incrDays)
{
	int incrMonth = 0;
	int allDays = _day + incrDays;

	if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12)
	{
		if (allDays <= 31)
		{
			_day += incrDays;;
		}
		if (allDays > 31)
		{
			allDays = incrDays - (31 - _day);
			if (allDays < 28 || allDays < 30 || allDays < 31)
			{
				_day = allDays;
			}
			++_month;
			if (_month > 12)
			{
				_month = 1;
				++_year;
			}
			if (allDays > 28 || allDays > 30 || allDays > 31)
			{
				incrMonth = _month;
				while (allDays > 28 || allDays > 30 || allDays > 31)
				{
					if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12)
					{
						allDays -= 31;
						++incrMonth;
					}
					if (_month == 2)
					{
						allDays -= 28;
						++incrMonth;
					}
					if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
					{
						allDays -= 30;
						++incrMonth;
					}
					_month = incrMonth;
				}
			}
			_day = allDays;
		}
	}

	if (_month == 2)
	{
		if (allDays <= 28)
		{
			_day += incrDays;;
		}
		if (allDays > 28)
		{
			allDays = incrDays - (28 - _day);
			if (allDays < 28 || allDays < 30 || allDays < 31)
			{
				_day = allDays;
			}
			++_month;
			if (allDays > 28 || allDays > 30 || allDays > 31)
			{
				incrMonth = _month;
				while (allDays > 28 || allDays > 30 || allDays > 31)
				{
					if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12)
					{
						allDays -= 31;
						++incrMonth;
					}
					if (_month == 2)
					{
						allDays -= 28;
						++incrMonth;
					}
					if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
					{
						allDays -= 30;
						++incrMonth;
					}
					_month = incrMonth;
				}
			}
			_day = allDays;
		}
	}

	if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
	{
		if (allDays <= 30)
		{
			_day += incrDays;;
		}
		if (allDays > 30)
		{
			allDays = incrDays - (30 - _day);
			if (allDays < 28 || allDays < 30 || allDays < 31)
			{
				_day = allDays;
			}
			++_month;
			if (allDays > 28 || allDays > 30 || allDays > 31)
			{
				incrMonth = _month;
				while (allDays > 28 || allDays > 30 || allDays > 31)
				{
					if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12)
					{
						allDays -= 31;
						++incrMonth;
					}
					if (_month == 2)
					{
						allDays -= 28;
						++incrMonth;
					}
					if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
					{
						allDays -= 30;
						++incrMonth;
					}
					_month = incrMonth;
				}
			}
			_day = allDays;
		}
	}
	return *this;
}

int operator-(const Date & dateMore, const Date & dateLess)
{

	int tmpYear = dateLess._year;
	int tmpDays = 0;
	int allDays = 0;
	int tmpDayinMonth = 0;
	int odds = 0;
	string ExDay = "If Years and Month of Dates are equal\n\
than Day of tha Date2 can't be more than Day of the Date1 !";
	string ExMonth = "if Years of Dates are equal\n\
than Month of Date2 can't be more than Month of Date1!";
	string ExYear = "Year of Date2 can't be more than Year of Date1!";
	string ExValBad = "Invalid values Of Date1 !";

	try
	{
		if (dateMore._day == 0 && dateMore._month == 0 && dateMore._year == 0)
		{
			throw ExValBad;
		}
	}
	catch (string &)
	{
		cout << ExValBad << endl;
		exit(0);
	}
	if (dateLess._day == 0 && dateLess._month == 0 && dateLess._year == 0)
	{
		odds = 0;
		return odds;
	}
	if (dateLess._year < dateMore._year)
	{
		// Calculate the number of days to less than 1 year more dates on the condition
		while (tmpYear < dateMore._year - 1)
		{
			tmpDays += 366;
			tmpYear++;
		}
		// Calculate the total number of days to a year = year Date of greater condition
		tmpDayinMonth = arrDays[dateLess._month - 1] - dateLess._day;
		tmpDays += tmpDayinMonth;
		for (int i = dateLess._month; i < 12; ++i)
		{
			tmpDays += arrDays[i];
		}

		// quantity days between dates
		if (dateLess._month == dateMore._month)
		{
			odds = tmpDays + dateMore._day;
		}
		else
		{
			for (int i = 0; i < dateMore._month - 1; ++i)
			{
				tmpDays += arrDays[i];
			}
			odds = tmpDays + dateMore._day;
		}
	}

	// Calculate the total number of days in the date on the condition of greater
	//and lesser difference with the date of the condition for equal Years
	if (dateLess._year == dateMore._year)
	{
		if (dateLess._month < dateMore._month)
		{
			// Total number of days in the date of the condition more
			for (int i = 0; i < dateMore._month - 1; ++i)
			{
				tmpDays += arrDays[i];
			}
			allDays = tmpDays + dateMore._day;
			// Number of days in the date of the condition at beginning of the year
			tmpDays = 0;
			for (int i = 0; i < dateLess._month - 1; ++i)
			{
				tmpDays += arrDays[i];
			}
			tmpDays += dateLess._day;
			odds = allDays - tmpDays;
		}
		try
		{
			if (dateLess._day > dateMore._day && dateLess._month == dateMore._month)
			{
				throw ExDay;
			}
		}
		catch (string & ex)
		{
			cout << ExDay << endl;
			exit(0);
		}
		if (dateLess._month == dateMore._month)
		{
			allDays = tmpDays + dateMore._day;
			odds = allDays - dateLess._day;
		}
		try
		{
			if (dateLess._month > dateMore._month)
			{
				throw ExMonth;
			}
		}
		catch (string & ex)
		{
			cout << ExMonth << endl;
			exit(0);
		}
	}
	try
	{
		if (dateLess._year > dateMore._year)
		{
			throw ExYear;
		}
	}
	catch (string &ex)
	{
		cout << ExYear << endl;
		exit(0);
	}
	return odds;
}

void Date::operator=(const Date &date)
{
	_day = date._day;
	_month = date._month;
	_year = date._year;
}

Date::Date(const Date & date)
:_day(date._day), _month(date._month), _year(date._year)
{
	string ExDay = "Day can't be 0 !";
	string ExMonth = "Month can't be 0 !";
	try
	{
		if (_day == 0)
		{
			throw ExDay;
		}
	}
	catch (string &)
	{
		cout << ExDay << endl;
		exit(0);
	}
	try
	{
		if (_month == 0)
		{
			throw ExMonth;
		}
	}
	catch (string &)
	{
		cout << ExMonth << endl;
		exit(0);
	}
}

// must check that day of month is correctly
Date::Date(int day, int month, int year)
: _day(day), _month(month), _year(year)
{
	string ExDay = "Day can't be 0 !";
	string ExMonth = "Month can't be 0 !";
	try
	{
		if (_day == 0)
		{
			throw ExDay;
		}
	}
	catch (string &)
	{
		cout << ExDay << endl;
		exit(0);
	}
	try
	{
		if (_month == 0)
		{
			throw ExMonth;
		}
	}
	catch (string &)
	{
		cout << ExMonth << endl;
		exit(0);
	}
}

Date::Date()
: _day(0), _month(0), _year(0)
{}