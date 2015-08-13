//work with time(+,-, compare) and conver from (am/pm) to Belarus format

#include <iostream>
#include "dz24.1.h"

void Time::Convert()
{
	if (_partDay == "pm")
	{
		_hour += 12;
		if (_hour == 24)
		{
			_hour = 0;
		}
	}

	cout << _hour << "." << _minutes << endl;
}

void Time::Compare(const Time &inTime)
{
	if (_partDay == "am" && inTime._partDay == "pm")
	{
		cout << "Time2 more than Time1" << endl;
	}
	if (_partDay == "pm" && inTime._partDay == "am")
	{
		cout << "Time1 more than Time2" << endl;
	}
	if (_partDay.compare(inTime._partDay) == 0)
	{
		if (_hour > inTime._hour)
		{
			cout << "Time1 more than Time2" << endl;
		}
		if (_hour < inTime._hour)
		{
			cout << "Time2 more than Time1" << endl;
		}
		if (_hour == inTime._hour)
		{
			if (_minutes > inTime._minutes)
			{
				cout << "Time1 more than Time2" << endl;
			}
			if (_minutes < inTime._minutes)
			{
				cout << "Time2 more than Time1" << endl;
			}
			if (_minutes == inTime._minutes)
			{
				cout << "Time1 = Time2" << endl;
			}
		}
	}
}

void Time::Minus(int hour, int minutes)
{
	string exHour = "Hour can't be more than 12!";
	string exMinutes = "Minutes can't be more than 59!";

	try
	{
		if (hour > 12)
		{
			throw exHour;
		}
	}
	catch (string &)
	{
		cout << exHour << endl;
		exit(0);
	}
	try
	{
		if (minutes > 59)
		{
			throw exMinutes;
		}
	}
	catch (string &)
	{
		cout << exMinutes << endl;
		exit(0);
	}

	_hour -= hour;
	_minutes -= minutes;

	if (_minutes < 0)
	{
		_minutes += 60;
		--_hour;
	}
	if (_partDay.compare("am") == 0)
	{
		if (_hour < 0)
		{
			_hour += 12;
			_partDay = "pm";
		}
	}
	else if (_partDay.compare("pm") == 0)
	{
		if (_hour < 0)
		{
			_hour += 12;
			_partDay = "am";
		}
	}
}

void Time::Plus(int hour, int minutes)
{
	string exHour = "Hour can't be more than 12!";
	string exMinutes = "Minutes can't be more than 59!";

	try
	{
		if (hour > 12)
		{
			throw exHour;
		}
	}
	catch (string &)
	{
		cout << exHour << endl;
		exit(0);
	}
	try
	{
		if (minutes > 59)
		{
			throw exMinutes;
		}
	}
	catch (string &)
	{
		cout << exMinutes << endl;
		exit(0);
	}

	_hour += hour;
	_minutes += minutes;

	if (_minutes >= 60)
	{
		_minutes %= 60;
		++_hour;
	}
	if (_hour == 12 && _minutes > 0 && _partDay.compare("am") == 0)
	{
		_hour = 0;
		_partDay = "pm";
	}
	else if (_hour == 12 && _minutes > 0 && _partDay.compare("pm") == 0)
	{
		_hour = 0;
		_partDay = "am";
	}
	if (_hour > 12 && _partDay.compare("am")==0)
	{
		_hour -= 12;
		_partDay = "pm";
	}
	else if (_hour > 12 && _partDay.compare("pm") == 0)
	{
		_hour -= 12;
		_partDay = "am";
	}
}

void Time::Print() const
{
	cout << _hour << "." << _minutes << " " << _partDay << endl;
}

Time & Time::operator=(const Time &obj)
{
	_hour = obj._hour;
	_minutes = obj._minutes;
	_partDay = obj._partDay;

	return *this;
}

Time::Time(const Time &obj)
:_hour(obj._hour), _minutes(obj._minutes), _partDay(obj._partDay)
{}

Time::Time(int hour, int minutes, string partDay)
: _hour(hour), _minutes(minutes), _partDay(partDay)
{
	string exHour = "Hour can't be more than 12!";
	string exMinutes = "Minutes can't be more than 59!";
	string exBadMinutes = "if Hour=12 than Minutes can be only 0!";

	try
	{
		if (hour == 12 && minutes != 0)
		{
			throw exBadMinutes;
		}
	}
	catch (string &)
	{
		cout << exBadMinutes << endl;
		exit(0);
	}
	try
	{
		if (hour > 12)
		{
			throw exHour;
		}
	}
	catch (string &)
	{
		cout << exHour << endl;
		exit(0);
	}
	try
	{
		if (minutes > 59)
		{
			throw exMinutes;
		}
	}
	catch (string &)
	{
		cout << exMinutes << endl;
		exit(0);
	}
}

Time::Time()
: _hour(0), _minutes(0), _partDay("")
{
}


