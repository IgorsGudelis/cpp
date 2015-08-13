//work with complex numbers

#ifndef DZ25_1_H
#define DZ25_1_H
#include <string>
#include <exception>
#include <cmath>

class NumCompl
{
	int _x;
	int _y;

public:

	NumCompl(int = 0, int = 0);
	NumCompl(const NumCompl &);

	void Print() const;
	NumCompl & operator=(const NumCompl &);

	friend NumCompl & operator+(const NumCompl &, const NumCompl &);
	friend NumCompl & operator-(const NumCompl &, const NumCompl &);
	friend NumCompl & operator*(const NumCompl &, const NumCompl &);
	friend NumCompl & operator/(const NumCompl &, const NumCompl &);
};
#endif