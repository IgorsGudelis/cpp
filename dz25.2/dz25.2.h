//Game Black Jack

#ifndef DZ25_2_H
#define DZ25_2_H
#include <string>
#include <exception>
#include <cstdlib>
#include <ctime>


class GameJack
{
	int _sum;
	int _sumAce1;
	int _sumAce2;
	// count quantity cards in  array from 0 !!!!
	int _countCards;
	int _countAce;
	int _haveAce;
	// Valet = 11, Dame = 12, King = 13, Ace = 14
	// max available quantity cards the sum of which < 21 equal 11
	int _setCards[11];


public:

	GameJack(const GameJack &) = delete;
	GameJack();

	int Getsum();
	void PlayJack();
	void SumCards();
	void NewCard();

	void PrintSum() const;
	void PrintCards() const;
	void SetStart();
};

class Player
{
	GameJack *_pGameJack;
	int _countCopy;

public:

	Player(GameJack * = nullptr);
	Player(const Player &);
	~Player();
	GameJack* & operator->(){ return _pGameJack; };
};
#endif