#include <iostream>
#include "Dz20_2.h"

using namespace std;

void Group::Spec_gr(const char * spec, int num)
{
	strcpy(specialise, spec);
	number = num;
}
void Group::Add_st(const Student &st)
{
	if (num_mem==0)
	{	
		members[0] = st;
		num_mem = 1;
	}
	else
	{
		members[num_mem++] = st;
	}
}
void Group::Print_gr() const
{
	cout << "Number of group: " << number << endl;
	cout << "Name of specialise: " << specialise << endl;
	cout << "\tStudents: " << endl;
	for (int i = 0; i < num_mem; ++i)
	{
		members[i].Print_name();
	}
}
Group::Group()
{
	strcpy(specialise, "unknown");
	number = 0;
	num_mem = 0;
}
void Student::Delete()
{
	Set_fname("Unknown");
	Set_lname("Unknown");
	Set_age(0);
	Set_spec("Unknown");
	Set_num(0);
}
void Student::Print_name() const
{
	cout << "Student: " << man.fname << " " << man.lname << endl;
	cout << "Age: " << man.age << endl;
	cout << endl;
}
void Student::Print_st() const
{
	cout << "Student: " << man.fname << " " << man.lname << endl;
	cout << "Age: " << man.age << endl;
	cout << "Specialise: " << specialise << endl;
	cout << "Number of group: " << number << endl;
	cout << endl;
}
void Student::Set_num(int num)
{
	number = num;
}
void Student::Set_spec(const char* spec)
{
	strcpy(specialise, spec);
}
void Student::Set_age(int ag)
{
	man.age = ag;
}
void Student::Set_lname(const char* ln)
{
	strcpy(man.lname, ln);
}
void Student::Set_fname(const char* fn)
{
	strcpy(man.fname, fn);
}
Student::Student(const char * fn, const char *ln, int ag, const char* spec, int num)
{
	strcpy(man.fname, fn);
	strcpy(man.lname, ln);
	man.age = ag;
	strcpy(specialise, spec);
	number = num;
}
Student::Student()
{
	Set_fname("Unknown");
	Set_lname("Unknown");
	Set_age(0);
	Set_spec("Unknown");
	Set_num(0);
}

