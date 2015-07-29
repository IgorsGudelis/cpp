#ifndef DZ22_1_H
#define DZ22_1_H
#include <string>

static const int arrDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Date
{
	int _day;
	int _month;
	int _year;
public:
	Date();
	Date(int, int, int);
	Date(const Date &);
	void operator=(const Date &);
	friend int operator-(const Date &, const Date &);
	Date & operator+(int);
	Date & operator+=(int);
	void Print() const;
};

#endif