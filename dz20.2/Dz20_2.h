#ifndef DZ_H
#define DZ_H

class Student
{
private:
	struct Person
	{
		char fname[20];
		char lname[20];
		int age;
	};
	Person man;
	char specialise[50];
	int number;
public:
	Student();
	Student(const char *, const char *, int =0, const char * ="unknown", int =0);
	void Set_fname(const char*);
	void Set_lname(const char*);
	void Set_age(int =0);
	void Set_spec(const char* ="unknown");
	void Set_num(int =0);
	void Print_st() const;
	void Print_name() const;
	void Delete();
};
class Group
{
private:
	Student members[20];
	char specialise[50];
	int number;
	int num_mem;
public:
	Group();
	void Spec_gr(const char *, int);
	void Add_st(const Student &);
	void Print_gr() const;
};
#endif