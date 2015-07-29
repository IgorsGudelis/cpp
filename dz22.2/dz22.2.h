#ifndef DZ22_2_2_H
#define DZ22_2_2_2
#include <string>

using  namespace std;

class String
{
	string _str;
public:
	String();
	String(const string &);
	void operator=(const string &);
	friend string  operator*(const string &, const string &);
	void Print() const;
};

#endif