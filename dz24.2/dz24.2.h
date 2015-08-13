//work with matrix (+, *, transpose, ...)

#ifndef DZ24_2_H
#define DZ_24_2_H
#include <string>
#include <exception>
#include <cstdlib>
#include <ctime>

using namespace std;

class Matrix
{
	int **_pArr;
	int _sizeIn1;
	int _sizeIn2;
	int _sizeOut1;
	int _sizeOut2;
	int _topOut;
	int _topIn;

public:
	~Matrix();
	Matrix();
	Matrix(int, int);
	void Print() const;
	Matrix & operator=(const Matrix &);
	int operator()(int, int) const;
	friend Matrix & operator+(const Matrix &, const Matrix &);
	friend Matrix & operator*(const Matrix &, const Matrix &);
	Matrix & Transpose();
	void Set(int, int, int);
	int Get(int, int) const;
};

#endif