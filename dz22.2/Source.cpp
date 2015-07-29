#include <iostream>
#include "dz22.2.h"

using namespace std;

void String::Print() const
{
	cout << _str << endl;
}

string operator*(const string &str1, const string &str2)
{
	string tmpStr;

	auto found = str1.find_first_of(str2);
	while (found != string::npos)
	{
		tmpStr.push_back(str1[found]);
		found = str1.find_first_of(str2, found + 1);
	}

	return tmpStr;
}

void String::operator=(const string &str)
{
	_str = str;
}

String::String(const string & str)
: _str(str)
{}

String::String()
: _str("")
{}
