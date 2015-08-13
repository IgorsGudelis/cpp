//Game Black Jack

#include <iostream>
#include "dz25.2.h"

using namespace std;

Player::~Player()
{
	if (_pGameJack && _countCopy == 0)
	{
		delete[] _pGameJack;
	}
	else
	{
		--_countCopy;
	}
}

Player::Player(const Player &pPlayer)
{
	_pGameJack = pPlayer._pGameJack;
	++_countCopy;
}

Player::Player(GameJack *pGameJack)
{
	_pGameJack = pGameJack;
	_countCopy = 0;
}

void GameJack::SetStart()
{
	_sum = 0;
	_sumAce1 = 0;
	_sumAce2 = 0;
	_countCards = 0;
	_countAce = 0;
	_haveAce = 0;

	for (int i = 0; i < 11; ++i)
	{
		_setCards[i] = 0;
	}
}

void GameJack::PrintCards() const
{
	for (int i = 0; i < _countCards; ++i)
	{
		if (_setCards[i] < 11)
		{
			cout << _setCards[i] << " ";
		}
		else
		{
			switch (_setCards[i])
			{
			case 11:
			{
					   cout << "Valet ";
					   break;
			}
			case 12:
			{
					   cout << "Dame ";
					   break;
			}
			case 13:
			{
					   cout << "King ";
					   break;
			}
			case 14:
			{
					   cout << "Ace ";
					   break;
			}
			}
		}
	}
	cout << endl;
}

void GameJack::PrintSum() const
{
	if (_haveAce)
	{
		if (_sumAce2 > 21 || _sumAce1 == _sumAce2)
		{
			cout << _sumAce1 << endl;
		}
		else
		{
			cout << _sumAce1 << "/" << _sumAce2 << endl;
		}
	}
	else
	{
		cout << _sum << endl;
	}

}

void GameJack::NewCard()
{
	int newCard;

	newCard = rand() % 13 + 2;
	if (newCard == 14)
	{
		if (_haveAce > 4)
		{
			while (newCard != 14)
			{
				newCard = rand() % 13 + 2;
			}
		}
		else
		{
			++_haveAce;
		}
	}
	_setCards[_countCards++] = newCard;
}

void GameJack::SumCards()
{

	if (_haveAce)
	{// Ace=1 until SumAce1 < 21
		_sumAce1 = 0;

		for (int i = 0; i < _countCards; ++i)
		{
			if (_setCards[i] < 11)
			{
				_sumAce1 += _setCards[i];
			}
			else
			{
				if (_setCards[i] == 14)
				{
					_sumAce1 += 1;
				}
				else
				{
					_sumAce1 += 10;
				}
			}
		}

		_sumAce2 = 0;
		_countAce = 0;

		for (int i = 0; i < _countCards; ++i)
		{// Ace=11 until SumAce2 < 21 and Ace=1 if SumAce2 > 21
			if (_setCards[i] < 11)
			{
				if (_countAce)
				{
					if ((_sumAce2 + _setCards[i]) > 21)
					{
						if ((_sumAce2 - 1) + _setCards[i] < 21)
						{
							_sumAce2 = (_sumAce2 - 10) + _setCards[i];
							--_countAce;
						}
						else
						{
							_sumAce2 += _setCards[i];
						}
					}
					else
					{
						_sumAce2 += _setCards[i];
					}
				}
				else
				{

					_sumAce2 += _setCards[i];
				}
			}
			else
			{
				switch (_setCards[i])
				{
				case 14:
				{
						   ++_countAce;

						   if (_sumAce2 > 10)
						   {
							   _sumAce2 += 1;
						   }
						   else
						   {
							   _sumAce2 += 11;
						   }

						   break;
				}
				default:
				{
						   _sumAce2 += 10;
						   break;
				}
				}
			}
		}
	}
	else
	{// without Ace
		_sum = 0;

		for (int i = 0; i < _countCards; ++i)
		{
			if (_setCards[i] == 11 || _setCards[i] == 12 || _setCards[i] == 13)
			{
				_sum += 10;
			}
			else
			{
				_sum += _setCards[i];
			}
		}
	}
}

void GameJack::PlayJack()
{
	int newCard;

	for (int i = 0; i < 2; ++i)
	{
		newCard = rand() % 13 + 2;
		++_countCards;
		if (newCard == 14)
		{
			++_haveAce;
		}
		_setCards[i] = newCard;
	}
}

int GameJack::Getsum()
{
	if (_haveAce)
	{
		if (_sumAce2 > _sumAce1  && _sumAce2 >= 22)
		{
			return _sumAce1;
		}
		else
		{
			return _sumAce2;
		}
	}
	else
	{
		return _sum;
	}
}

GameJack::GameJack()
: _sum(0), _sumAce1(0), _sumAce2(0), _countCards(0), _countAce(0), _haveAce(0)
{
	for (int i = 0; i < 11; ++i)
	{
		_setCards[i] = 0;
	}
}