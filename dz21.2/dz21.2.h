#ifndef DZ21_2_H
#define DZ21_2_H
#include <string>

using namespace std;

class String
{
	string _data;
public:
	String();
	String(int);
	String(const string &);
	string & operator=(const string &);
	void Input();
	void Print() const;
};

#endif