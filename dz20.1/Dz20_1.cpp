#include <iostream>
#include "Dz20_1.h"

using namespace std;

int Counter::CurrentValue()
{
	return number;
}
void Counter::PlusOne()
{
	number++;
	if (number == 100)
	{
		SetMin();
	}
}
void Counter::SetMax()
{
	number = 100;
	if (number == 100)
	{
		SetMin();
	}
}
void Counter::SetMin()
{
	number = 0;
}
Counter::Counter(int num)
{
	if (num<0 || num>100)
	{
		exit(0);
	}
	number = num;
}