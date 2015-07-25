#include <iostream>
#include "dz21.1.h"

using namespace std;

Person::Person()
:  _age(0), _sex('?'), _phone(0)
{
	char * str = "?";
	_name = new char[strlen(str)+1];
	if (_name)
	{
		strcpy(_name, str);
	}
}

Person::Person(const char* name, int age, char sex, int phone)
{
	_name = new char[strlen(name)+1];
	if (_name)
	{
		strcpy(_name, name);
	}
	_age = age;
	_sex = sex;
	_phone = phone;
}

Person::~Person()
{
	if (_name)
	{
		delete[] _name;
	}
}

void Person::SetName(const char* name)
{
	delete[] _name;
	_name = new char[strlen(name)+1];
	if (_name)
	{
		strcpy(_name, name);
	}
}

void Person::SetAge(int age)
{
	_age = age;
}

void Person::SetSex(char sex)
{
	_sex = sex;
}

void Person::SetPhone(int phone)
{
	_phone = phone;
}

void Person::PrintPerson() const
{
	cout << _name<< " ";
	cout << _age << " ";
	cout << _sex << " ";
	cout << _phone << endl;
}
