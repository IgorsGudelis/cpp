#ifndef DZ23_H
#define DZ23_H
#include <string>
#include <exception>

class ArrD
{
	int *_parr;
	int _size;
	int _top;
public:
	~ArrD();
	ArrD();
	ArrD(int);
	void Set(int);
	void Print() const;
	void Check(int);
	ArrD & operator=(const ArrD &);
	int  operator[](int) const;
	friend ArrD & operator+(const ArrD &, const ArrD &);
	friend ArrD & operator-(const ArrD &, const ArrD &);
	void operator++(int);
	void operator--();
};

#endif