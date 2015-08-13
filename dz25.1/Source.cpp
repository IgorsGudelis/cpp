//work with complex numbers

#include <iostream>
#include "dz25.1.h"

using namespace std;

NumCompl & operator/(const NumCompl &numLeft, const NumCompl &numRight)
{
	NumCompl * tmpNum = new NumCompl;
	string exBadNumbers = "Sum of the numbers of the complex number on which divide can not be equal to zero!";

	try
	{
		if (numRight._x + numRight._y == 0)
		{
			throw exBadNumbers;
		}
	}
	catch (string &)
	{
		cout << exBadNumbers << endl;
		exit(0);
	}

	tmpNum->_x = ((numLeft._x * numRight._x) + (numLeft._y * numRight._y)) / static_cast<int>((sqrt(static_cast<double>(numLeft._x)) + sqrt(static_cast<double>(numLeft._x))));
	tmpNum->_y = ((numLeft._y * numRight._x) - (numLeft._x * numRight._y)) / static_cast<int>((sqrt(static_cast<double>(numLeft._x)) + sqrt(static_cast<double>(numLeft._x))));

	return *tmpNum;
}

NumCompl & operator*(const NumCompl &numLeft, const NumCompl &numRight)
{
	NumCompl * tmpNum = new NumCompl;

	tmpNum->_x = (numLeft._x * numRight._x) + (-1 * (numLeft._y * numRight._y));
	tmpNum->_y = (numLeft._x * numRight._y) + (numLeft._y * numRight._x);

	return *tmpNum;
}

NumCompl & operator-(const NumCompl &numLeft, const NumCompl &numRight)
{

	NumCompl * tmpNum = new NumCompl;

	tmpNum->_x = numLeft._x - numRight._x;
	tmpNum->_y = numLeft._y - numRight._y;

	return *tmpNum;

}

NumCompl & operator+(const NumCompl &numLeft, const NumCompl &numRight)
{

	NumCompl * tmpNum = new NumCompl;

	tmpNum->_x = numLeft._x + numRight._x;
	tmpNum->_y = numLeft._y + numRight._y;

	return *tmpNum;

}

NumCompl & NumCompl::operator=(const NumCompl &numIn)
{

	_x = numIn._x;
	_y = numIn._y;

	return *this;

}

void NumCompl::Print() const
{

	if (_y < 0)
	{
		cout << "Complex number is: " << _x << " - " << _y << "i" << endl;
	}
	else
	{
		cout << "Complex number is: " << _x << " + " << _y <<"i"<< endl;
	}

}

NumCompl::NumCompl(const NumCompl &numIn)
: _x(numIn._x), _y(numIn._y)
{}

NumCompl::NumCompl(int x, int y)
: _x(x), _y(y)
{}

