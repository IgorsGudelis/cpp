#include <iostream>
#include "dz26.1.h"

void Bandit::SetSumCompFile()
{
	char  buffSum[4];

	FILE *pfile;
	pfile = fopen("test.txt", "w");

	if (pfile)
	{
		itoa(_sumComp, buffSum, 10);
		fwrite(buffSum, sizeof(char), 4, pfile);
	}

	fclose;
}

int Bandit::GetSumCompFile()
{
	char  buffSum[4];

	FILE *pfile;
	pfile = fopen("test.txt", "r");

	if (pfile)
	{
		fread(buffSum, sizeof(char), 4, pfile);
	}

	fclose;

	return _sumComp = atoi(buffSum);
}

void Bandit::PrintSum()
{
	cout << "Your Sum is: " << _sumPlayer << endl;
}

void Bandit::CompareRes()
{
	if (_resDrum[0] == _resDrum[1] && _resDrum[1] == _resDrum[2])
	{

		switch (static_cast<int>(_resDrum[0]))
		{
		case 64:// @
		{
					cout << "Win 15!" << endl;
					_sumPlayer += 15;
					_sumComp -= 15;
					break;
		}
		case 53:// 5
		{
					cout << "Win 25!" << endl;
					_sumPlayer += 25;
					_sumComp -= 25;
					break;
		}
		case 42:// *
		{
					cout << "Win 35!" << endl;
					_sumPlayer += 35;
					_sumComp -= 35;
					break;
		}
		case 55:// 7
		{
					cout << "Win 45!" << endl;
					_sumPlayer += 45;
					_sumComp -= 45;
					break;
		}
		case 36:// $
		{
				   cout << "Win 60!" << endl;
				   _sumPlayer += 60;
				   _sumComp -= 60;
				   break;
		}
		}

	}
	else if (_resDrum[0] == _resDrum[1] && _resDrum[1] != _resDrum[2])
	{

		switch (static_cast<int>(_resDrum[0]))
		{
		case 64:// @
		{
					cout << "Win 5!" << endl;
					_sumPlayer += 5;
					_sumComp -= 5;
					break;
		}
		case 53:// 5
		{
					cout << "Win 10!" << endl;
					_sumPlayer += 10;
					_sumComp -= 10;
					break;
		}
		case 42:// *
		{
					cout << "Win 15!" << endl;
					_sumPlayer += 15;
					_sumComp -= 15;
					break;
		}
		case 55:// 7
		{
					cout << "Win 20!" << endl;
					_sumPlayer += 20;
					_sumComp -= 20;
					break;
		}
		case 36:// $
		{
					cout << "Win 25!" << endl;
					_sumPlayer += 25;
					_sumComp -= 25;
					break;
		}
		}

	}
	else
	{
		cout << endl;
		cout << "You lost!" << endl;

		_sumPlayer -= 10;
		_sumComp += 10;
	}

	cout << _resDrum[0] << " " << _resDrum[1] << " " << _resDrum[2] << endl;
}

void Bandit::StartGame()
{
	int count = 3;

	
	if (_sumComp < 60)
	{// casino never loses
		do
		{
			count = 3;
			_resDrum = "";
			while (count)
			{
				_resDrum += TurnDrum();
				--count;
			}
		} while (_resDrum[0] == _resDrum[1]);

	}
	else
	{
		_resDrum = "";

		while (count)
		{
			_resDrum += TurnDrum();
			--count;
		}
	}
}

char Bandit::TurnDrum()
{
	int lengthDrum = 4;
	int lengthTurn;

	int countTurm = rand() % 10 + 2;
	int lengthTurnTmp = rand() % 5;

	while (countTurm)
	{
		lengthTurn = lengthTurnTmp;

		while (lengthTurn != lengthDrum)
		{
			char tmpSymbol = _Drum[lengthDrum];

			for (int i = lengthDrum - 1; i >= 0; --i)
			{
				_Drum[i + 1] = _Drum[i];
			}
			_Drum[0] = tmpSymbol;

			++lengthTurn;
		}
		--countTurm;
	}

	return _Drum[lengthDrum];
}

Bandit::Bandit()
: _Drum("@5*7$"), _resDrum(""), _sumComp(0), _sumPlayer(0)
{}