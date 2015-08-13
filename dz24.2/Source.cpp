//work with matrix (+, *, transpose, ...)

#include <iostream>
#include "dz24.2.h"


int Matrix::Get(int indxOut, int indxIn) const
{
	string exBadIndx = "Out of range of array!\n\
					   Input right index!";

	try
	{
		if (indxOut >= _sizeOut1 || indxOut < 0)
		{
			throw exBadIndx;
		}
		if (indxIn >= _sizeIn1 || indxIn < 0)
		{
			throw exBadIndx;
		}
	}
	catch (string &)
	{
		cout << exBadIndx << endl;
		exit(0);
	}

	return _pArr[indxOut][indxIn];

}

void Matrix::Set(int indxOut, int indxIn, int value)
{
	string exBadIndx = "Out of range of array!\n\
Input right index!";

	try
	{
		if (indxOut >= _sizeOut1 || indxOut < 0)
		{
			throw exBadIndx;
		}
		if (indxIn >= _sizeIn1 || indxIn < 0)
		{
			throw exBadIndx;
		}
	}
	catch (string &)
	{
		cout << exBadIndx << endl;
		exit(0);
	}

	_pArr[indxOut][indxIn] = value;

}

Matrix & Matrix::Transpose()
{
	try
	{
		Matrix *tmpMatr = new Matrix;

		tmpMatr->_pArr = new int*[_sizeIn1];
		tmpMatr->_sizeIn1 = _sizeOut1;
		tmpMatr->_sizeOut1 = _sizeIn1;
		tmpMatr->_topIn = _topOut;
		tmpMatr->_topOut = _topIn;

		for (int i = 0; i < _sizeIn1; ++i)
		{
			try
			{
				tmpMatr->_pArr[i] = new int[_sizeOut1];
			}
			catch (exception & ba)
			{
				cout << "bad_alloc caught: " << ba.what() << endl;
				exit(0);
			}
		}

		for (int i = 0; i < tmpMatr->_sizeOut1; ++i)
		{
			for (int j = 0; j < tmpMatr->_sizeIn1; ++j)
			{
				tmpMatr->_pArr[i][j] = _pArr[j][i];
			}
		}

		return *tmpMatr;

	}
	catch (exception &ba)
	{
		cout << "bad_alloc caught: " << ba.what() << endl;
		exit(0);
	}

}

/*
operator* is realised such as operator+
*/

Matrix & operator+(const Matrix &matrLeft, const Matrix &matrRight)
{

	// when matrLeft._sizeOut of external array >= matrRight._sizeOut of external array
	// and variants of compare matrLeft._sizeIn of internal array with matrRight._sizeIn of internal array
	// and sum matrices
	if (matrLeft._sizeOut1 >= matrRight._sizeOut1)
	{
		try
		{
			Matrix *tmpMatrix = new Matrix;

			tmpMatrix->_pArr = new int*[matrLeft._sizeOut1];
			tmpMatrix->_sizeIn1 = matrLeft._sizeIn1;
			tmpMatrix->_sizeOut1 = matrLeft._sizeOut1;
			tmpMatrix->_topIn = matrLeft._topIn;
			tmpMatrix->_topOut = matrLeft._topOut;

			if (matrLeft._sizeIn1 > matrRight._sizeIn1)
			{
				for (int i = 0; i < matrLeft._sizeOut1; ++i)
				{
					try
					{
						tmpMatrix->_pArr[i] = new int[matrLeft._sizeIn1];
					}
					catch (exception & ba)
					{
						cout << "bad_alloc caught: " << ba.what() << endl;
						exit(0);
					}
				}

				// sum matrices
				for (int i = 0; i < matrRight._sizeOut1; ++i)
				{
					for (int j = 0; j < matrRight._sizeIn1; ++j)
					{
						tmpMatrix->_pArr[i][j] = matrLeft(i, j) + matrRight(i, j);
					}

					for (int j = matrRight._topIn + 1; j < matrLeft._sizeIn1; ++j)
					{
						tmpMatrix->_pArr[i][j] = matrLeft(i, j);
					}
				}
				for (int i = matrRight._sizeOut1; i < matrLeft._sizeOut1; ++i)
				{
					for (int j = 0; j < matrLeft._sizeIn1; ++j)
					{
						tmpMatrix->_pArr[i][j] = matrLeft(i, j);
					}
				}

			}

			if (matrLeft._sizeIn1 == matrRight._sizeIn1)
			{
				for (int i = 0; i < matrLeft._sizeOut1; ++i)
				{
					try
					{
						tmpMatrix->_pArr[i] = new int[matrLeft._sizeIn1];
					}
					catch (exception & ba)
					{
						cout << "bad_alloc caught: " << ba.what() << endl;
						exit(0);
					}
				}

				// sum matrices
				for (int i = 0; i < matrRight._sizeOut1; ++i)
				{
					for (int j = 0; j < matrRight._sizeIn1; ++j)
					{
						tmpMatrix->_pArr[i][j] = matrLeft(i, j) + matrRight(i, j);
					}
				}
				for (int i = matrRight._sizeOut1; i < matrLeft._sizeOut1; ++i)
				{
					for (int j = 0; j < matrLeft._sizeIn1; ++j)
					{
						tmpMatrix->_pArr[i][j] = matrLeft(i, j);
					}
				}
			}

			if (matrLeft._sizeIn1 < matrRight._sizeIn1)
			{
				for (int i = 0; i < matrRight._sizeOut1; ++i)
				{
					try
					{
						tmpMatrix->_pArr[i] = new int[matrRight._sizeIn1];
						
						tmpMatrix->_sizeIn2 = matrRight._sizeIn1;
						tmpMatrix->_sizeOut2 = matrRight._sizeOut1;
					}
					catch (exception & ba)
					{
						cout << "bad_alloc caught: " << ba.what() << endl;
						exit(0);
					}
				}
				for (int i = matrRight._sizeOut1; i < matrLeft._sizeOut1; ++i)
				{
					try
					{
						tmpMatrix->_pArr[i] = new int[matrLeft._sizeIn1];
					}
					catch (exception & ba)
					{
						cout << "bad_alloc caught: " << ba.what() << endl;
						exit(0);
					}
				}

				// sum matrices
				for (int i = 0; i < matrRight._sizeOut1; ++i)
				{
					for (int j = 0; j < matrLeft._sizeIn1; ++j)
					{
						tmpMatrix->_pArr[i][j] = matrLeft(i, j) + matrRight(i, j);
					}

					for (int j = matrLeft._topIn + 1; j < matrRight._sizeIn1; ++j)
					{
						tmpMatrix->_pArr[i][j] = matrRight(i, j);
					}
				}
				for (int i = matrRight._sizeOut1; i < matrLeft._sizeOut1; ++i)
				{
					for (int j = 0; j < matrLeft._sizeIn1; ++j)
					{
						tmpMatrix->_pArr[i][j] = matrLeft(i, j);
					}
				}
			}

			return *tmpMatrix;

		}
		catch (exception & ba)
		{
			cout << "bad_alloc caught: " << ba.what() << endl;
			exit(0);
		}
	}

	// when matrLeft._sizeOut of external array < matrRight._sizeOut of external array
	// and variants of compare matrLeft._sizeIn of internal array with matrRight._sizeIn of internal array
	// and sum matrices
	if (matrLeft._sizeOut1 < matrRight._sizeOut1)
	{
		try
		{
			Matrix *tmpMatrix = new Matrix;

			tmpMatrix->_pArr = new int*[matrRight._sizeOut1];
			tmpMatrix->_sizeIn1 = matrRight._sizeIn1;
			tmpMatrix->_sizeOut1 = matrRight._sizeOut1;
			tmpMatrix->_topIn = matrRight._topIn;
			tmpMatrix->_topOut = matrRight._topOut;

			if (matrLeft._sizeIn1 < matrRight._sizeIn1)
			{
				for (int i = 0; i < matrRight._sizeOut1; ++i)
				{
					try
					{
						tmpMatrix->_pArr[i] = new int[matrRight._sizeIn1];
					}
					catch (exception & ba)
					{
						cout << "bad_alloc caught: " << ba.what() << endl;
						exit(0);
					}
				}

				// sum matrices
				for (int i = 0; i < matrLeft._sizeOut1; ++i)
				{
					for (int j = 0; j < matrLeft._sizeIn1; ++j)
					{
						tmpMatrix->_pArr[i][j] = matrLeft(i, j) + matrRight(i, j);
					}

					for (int j = matrLeft._topIn + 1; j < matrRight._sizeIn1; ++j)
					{
						tmpMatrix->_pArr[i][j] = matrRight(i, j);
					}
				}
				for (int i = matrLeft._sizeOut1; i < matrRight._sizeOut1; ++i)
				{
					for (int j = 0; j < matrRight._sizeIn1; ++j)
					{
						tmpMatrix->_pArr[i][j] = matrRight(i, j);
					}
				}
			}

			if (matrLeft._sizeIn1 == matrRight._sizeIn1)
			{
				for (int i = 0; i < matrRight._sizeOut1; ++i)
				{
					try
					{
						tmpMatrix->_pArr[i] = new int[matrRight._sizeIn1];
					}
					catch (exception & ba)
					{
						cout << "bad_alloc caught: " << ba.what() << endl;
						exit(0);
					}
				}

				// sum matrices
				for (int i = 0; i < matrLeft._sizeOut1; ++i)
				{
					for (int j = 0; j < matrRight._sizeIn1; ++j)
					{
						tmpMatrix->_pArr[i][j] = matrLeft(i, j) + matrRight(i, j);
					}
				}
				for (int i = matrLeft._sizeOut1; i < matrRight._sizeOut1; ++i)
				{
					for (int j = 0; j < matrRight._sizeIn1; ++j)
					{
						tmpMatrix->_pArr[i][j] = matrRight(i, j);
					}
				}
			}

			if (matrLeft._sizeIn1 > matrRight._sizeIn1)
			{
				for (int i = 0; i < matrLeft._sizeOut1; ++i)
				{
					try
					{
						tmpMatrix->_pArr[i] = new int[matrLeft._sizeIn1];

						tmpMatrix->_sizeIn2 = matrLeft._sizeIn1;
						tmpMatrix->_sizeOut2 = matrLeft._sizeOut1;
					}
					catch (exception & ba)
					{
						cout << "bad_alloc caught: " << ba.what() << endl;
						exit(0);
					}
				}
				for (int i = matrLeft._sizeOut1; i < matrRight._sizeOut1; ++i)
				{
					try
					{
						tmpMatrix->_pArr[i] = new int[matrRight._sizeIn1];
					}
					catch (exception & ba)
					{
						cout << "bad_alloc caught: " << ba.what() << endl;
						exit(0);
					}
				}

				// sum matrices
				for (int i = 0; i < matrLeft._sizeOut1; ++i)
				{
					for (int j = 0; j < matrRight._sizeIn1; ++j)
					{
						tmpMatrix->_pArr[i][j] = matrLeft(i, j) + matrRight(i, j);
					}

					for (int j = matrRight._topIn + 1; j < matrLeft._sizeIn1; ++j)
					{
						tmpMatrix->_pArr[i][j] = matrLeft(i, j);
					}
				}
				for (int i = matrLeft._sizeOut1; i < matrRight._sizeOut1; ++i)
				{
					for (int j = 0; j < matrRight._sizeIn1; ++j)
					{
						tmpMatrix->_pArr[i][j] = matrRight(i, j);
					}
				}
			}

			return *tmpMatrix;

		}
		catch (exception &ba)
		{
			cout << "bad_alloc caught: " << ba.what() << endl;
			exit(0);
		}
	}

}

int  Matrix::operator()(int numOut, int numIn) const
{
	return _pArr[numOut][numIn];
}

Matrix & Matrix::operator=(const Matrix &matrIn)
{
	try
	{
		Matrix *tmppArr = new Matrix;

		// memory allocation depending on size of internal arrays identical or not
		if (matrIn._sizeIn2 && matrIn._sizeOut2)
		{
			tmppArr->_pArr = new int*[matrIn._sizeOut1];
			for (int i = 0; i < matrIn._sizeOut2; ++i)
			{
				for (int j = 0; j < matrIn._sizeIn2; ++j)
				{
					tmppArr->_pArr[i] = new int[matrIn._sizeIn2];
				}
			}
			for (int i = matrIn._sizeOut2; i < matrIn._sizeOut1; ++i)
			{
				for (int j = 0; j < matrIn._sizeIn1; ++j)
				{
					tmppArr->_pArr[i] = new int[matrIn._sizeIn1];
				}
			}
		}
		else
		{
			tmppArr->_pArr = new int*[matrIn._sizeOut1];
			for (int i = 0; i < matrIn._sizeOut1; ++i)
			{
				tmppArr->_pArr[i] = new int[matrIn._sizeIn1];
			}
		}

		_pArr = tmppArr->_pArr;
		_sizeIn1 = matrIn._sizeIn1;
		_sizeOut1 = matrIn._sizeOut1;
		_sizeIn2 = matrIn._sizeIn2;
		_sizeOut2 = matrIn._sizeOut2;
		_topIn = matrIn._sizeIn1 - 1;
		_topOut = matrIn._sizeOut1 - 1;

		if (matrIn._sizeIn2 && matrIn._sizeOut2)
		{
			for (int i = 0; i < matrIn._sizeOut2; ++i)
			{
				for (int j = 0; j < matrIn._sizeIn2; ++j)
				{
					_pArr[i][j] = matrIn(i, j);
				}
			}
			for (int i = matrIn._sizeOut2; i < matrIn._sizeOut1; ++i)
			{
				for (int j = 0; j < matrIn._sizeIn1; ++j)
				{
					_pArr[i][j] = matrIn(i, j);
				}
			}
		}
		else
		{
			for (int i = 0; i < matrIn._sizeOut1; ++i)
			{
				for (int j = 0; j < matrIn._sizeIn1; ++j)
				{
					_pArr[i][j] = matrIn(i, j);
				}
			}
		}
	}
	catch (exception & ba)
	{
		cout << "bad_alloc caught: " << ba.what() << endl;
		exit(0);
	}

	return *this;
}

void Matrix::Print() const
{
	// print Matrix depending on size of internal arrays identical or not
	if (_sizeIn2 && _sizeOut2)
	{
		for (int i = 0; i < _sizeOut2; ++i)
		{
			for (int j = 0; j < _sizeIn2; ++j)
			{
				cout.width(2);
				cout << _pArr[i][j] << " ";
			}

			cout << endl;

		}
		for (int i = _sizeOut2; i < _sizeOut1; ++i)
		{
			for (int j = 0; j < _sizeIn1; ++j)
			{
				cout.width(2);
				cout << _pArr[i][j] << " ";
			}

			cout << endl;
		}

		cout << endl;
	}
	else
	{
		for (int i = 0; i < _sizeOut1; ++i)
		{
			for (int j = 0; j < _sizeIn1; ++j)
			{
				cout.width(2);
				cout << _pArr[i][j] << " ";
			}
			cout << endl;
		}

		cout << endl;
	}
}

Matrix::Matrix(int sizeOut, int sizeIn)
: _sizeIn1(sizeIn), _sizeIn2(0), _sizeOut1(sizeOut), _sizeOut2(0), _topOut(sizeOut - 1), _topIn(sizeIn - 1)
{
	srand(time(NULL));
	string exBadSize = "Matrix doesn't exist! Size can't be 0!";

	try
	{
		if (_sizeIn1==0 || _sizeOut1 == 0)
		{
			throw exBadSize;
		}
	}
	catch (string &)
	{
		cout << exBadSize << endl;
		exit(0);
	}

	try
	{
		_pArr = new int*[sizeOut];
	}
	catch (exception &ba)
	{
		cout << "bad_alloc caught: " << ba.what() << endl;
		exit(0);
	}
	try
	{
		for (int i = 0; i < sizeOut; ++i)
		{
			_pArr[i] = new int[sizeIn];
			for (int j = 0; j < sizeIn; ++j)
			{
				_pArr[i][j] = rand() % 10;
			}
		}
	}
	catch (exception &ba)
	{
		cout << "bad_alloc caught: " << ba.what() << endl;
		exit(0);
	}
}

Matrix::Matrix()
: _pArr(nullptr), _sizeIn1(0), _sizeIn2(0), _sizeOut1(0), _sizeOut2(0), _topOut(0), _topIn(0)
{
}

Matrix::~Matrix()
{
	if (_pArr)
	{
		if (_sizeIn2 && _sizeOut2)
		{
			for (int i = 0; i < _sizeOut2; ++i)
			{
				delete[] _pArr[i];
			}
			for (int i = _sizeOut2; i < _sizeOut1; ++i)
			{
				delete[] _pArr[i];
			}
			delete[] _pArr;
		}
		else
		{
			for (int i = 0; i < _sizeOut1; ++i)
			{
				delete[] _pArr[i];
			}
			delete[] _pArr;
		}
	}
}