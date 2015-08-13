//work with time(+,-, compare) and conver from (am/pm) to Belarus format

#ifndef DZ24_1_H
#define DZ24_1_H
#include<string>

using namespace std;

class Time
{
	int _hour;
	int _minutes;
	string _partDay;
public:
	Time();
	Time(int, int, string);
	Time(const Time &);
	Time & operator=(const Time &);
	void Print() const;
	void Plus(int, int);
	void Minus(int, int);
	void Compare(const Time &);
	void Convert();
};

#endif