#ifndef DZ21_1_H
#define DZ21_1_H
#include <cstring>

class Person
{
	char* _name;
	int _age;
	char _sex;
	int _phone;
public:
	Person();
	Person(const char*, int, char, int);
	~Person();
	void SetName(const char*);
	void SetAge(int);
	void SetSex(char);
	void SetPhone(int);
	void PrintPerson() const;
};

#endif