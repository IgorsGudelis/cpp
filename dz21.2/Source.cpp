#include <iostream>
#include "dz21.2.h"

using namespace std;

void String::Input()
{
	cout << "Input string: ";
	cin >> _data;
	cout << endl;
}

void String::Print() const
{
	cout << _data << endl;
}

string & String::operator=(const string &data)
{
	_data = data;
	return _data;
}

String::String(const string &data)
: _data(data)
{}

String::String(int size)
: _data(size, ' ')
{}

String::String()
: _data(80, ' ')
{
}
