#include <iostream>
#include "dz23.h"



using namespace std;

void ArrD::operator--()
{
	try
	{
		int *tmpArr = new int[_size - 1];

		for (int i = 0; i < _size - 1; ++i)
		{
			tmpArr[i] = _parr[i];
		}

		delete[] _parr;
		_parr = tmpArr;
		--_size;
		--_top;
	}
	catch (exception &ba)
	{
		cout << "bad_alloc caught: " << ba.what() << endl;
		exit(0);
	}
}

void ArrD::operator++(int addEl)
{
	try
	{
		int *tmpArr = new int[_size + 1];

		for (int i = 0; i < _size; ++i)
		{
			tmpArr[i] = _parr[i];
		}
		tmpArr[++_top] = addEl;

		delete[] _parr;
		_parr = tmpArr;
		++_size;
	}
	catch (exception &ba)
	{
		cout << "bad_alloc caught: " << ba.what() << endl;
		exit(0);
	}
}

ArrD & operator-(const ArrD &arrIn1, const ArrD &arrIn2)
{
	if (arrIn1._size == arrIn2._size)
	{
		try
		{
			ArrD *tmpArr = new ArrD;
			tmpArr->_size = arrIn1._size;

			for (int i = 0; i < arrIn1._size; ++i)
			{
				tmpArr->_parr[i] = arrIn1[i] - arrIn2[i];
			}

			return *tmpArr;
		}
		catch (exception &ba)
		{
			cout << "bad_alloc caught: " << ba.what() << endl;
			exit(0);
		}
	}
	if (arrIn1._size < arrIn2._size)
	{
		try
		{
			ArrD *tmpArr = new ArrD;
			tmpArr->_size = arrIn2._size;

			for (int i = arrIn1._top + 1; i < arrIn2._size; ++i)
			{
				tmpArr->_parr[i] = arrIn2[i];
			}
			for (int i = 0; i < arrIn1._size; ++i)
			{
				tmpArr->_parr[i] = arrIn1[i] - arrIn2[i];
			}

			return *tmpArr;
		}
		catch (exception &ba)
		{
			cout << "bad_alloc caught: " << ba.what() << endl;
			exit(0);
		}
	}
	else
	{
		try
		{
			ArrD *tmpArr = new ArrD;
			tmpArr->_size = arrIn1._size;

			for (int i = arrIn2._top + 1; i < arrIn1._size; ++i)
			{
				tmpArr->_parr[i] = arrIn1[i];
			}
			for (int i = 0; i < arrIn2._size; ++i)
			{
				tmpArr->_parr[i] = arrIn1[i] - arrIn2[i];
			}

			return *tmpArr;
		}
		catch (exception &ba)
		{
			cout << "bad_alloc caught: " << ba.what() << endl;
			exit(0);
		}
	}
}

ArrD & operator+(const ArrD &arrIn1, const ArrD &arrIn2)
{
	if (arrIn1._size == arrIn2._size)
	{
		try
		{
			ArrD *tmpArr = new ArrD;
			tmpArr->_size = arrIn1._size;

			for (int i = 0; i < arrIn1._size; ++i)
			{
				tmpArr->_parr[i] = arrIn1[i] + arrIn2[i];
			}

			return *tmpArr;
		}
		catch (exception &ba)
		{
			cout << "bad_alloc caught: " << ba.what() << endl;
			exit(0);
		}
	}
	if (arrIn1._size < arrIn2._size)
	{
		try
		{
			ArrD *tmpArr = new ArrD;
			tmpArr->_size = arrIn2._size;

			for (int i = arrIn1._top + 1; i < arrIn2._size; ++i)
			{
				tmpArr->_parr[i] = arrIn2[i];
			}
			for (int i = 0; i < arrIn1._size; ++i)
			{
				tmpArr->_parr[i] = arrIn1[i] + arrIn2[i];
			}

			return *tmpArr;
		}
		catch (exception &ba)
		{
			cout << "bad_alloc caught: " << ba.what() << endl;
			exit(0);
		}
	}
	else
	{
		try
		{
			ArrD *tmpArr = new ArrD;
			tmpArr->_size = arrIn1._size;

			for (int i = arrIn2._top + 1; i < arrIn1._size; ++i)
			{
				tmpArr->_parr[i] = arrIn1[i];
			}
			for (int i = 0; i < arrIn2._size; ++i)
			{
				tmpArr->_parr[i] =arrIn1[i] + arrIn2[i];
			}

			return *tmpArr;
		}
		catch (exception &ba)
		{
			cout << "bad_alloc caught: " << ba.what() << endl;
			exit(0);
		}
	}
	
}

int ArrD::operator[](int num) const
{
	return _parr[num];
}

ArrD & ArrD::operator=(const ArrD & arrIn)
{
	try
	{
		int *tmpArr = new int[arrIn._size];

		delete[] _parr;
		_parr = tmpArr;
		_size = arrIn._size;
		_top = _size - 1;

		for (int i = 0; i < _size; ++i)
		{
			_parr[i] = arrIn[i];
		}
	}
	catch (exception &ba)
	{
		cout << "bad_alloc caught: " << ba.what() << endl;
		exit(0);
	}

	return *this;
}

void ArrD::Check(int size)
{
	string ExOut = "run out of range of array!";

	try
	{
		if (_size < size)
			throw ExOut;
	}
	catch (string &)
	{
		cout << ExOut << endl;
		cout << "Size of array is " << _size << endl;
	}
}

void ArrD::Print() const
{
	for (int i = 0; i < _size; ++i)
	{
		cout << _parr[i] << " ";
		if (i == 4)
		{
			cout << endl;
		}
	}
	cout << endl;
}

void ArrD::Set(int size)
{
	string ExOut = "run out of range of array!";

	try
	{
		if (_size < size)
			throw ExOut;
	}
	catch (string &)
	{
		cout << ExOut << endl;
		exit(0);
	}

	while (_top < size)
	{
		cout << "Input number: ";
		cin >> _parr[_top];
		++_top;
	}
	if (_top < _size)
	{
		for (int i = _top; i < _size; ++i)
		{
			_parr[i] = 0;
			++_top;
		}
	}
	--_top;
	cout << endl;
}

ArrD::ArrD(int size)
: _parr(new int[size]), _size(size), _top(0)
{}

ArrD::ArrD()
: _parr(new int[1]), _size(1), _top(0)
{}

ArrD::~ArrD()
{
	delete[] _parr;
}