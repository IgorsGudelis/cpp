#ifndef DZ26_1_H
#define DZ26_1_H
#include <string>
#include <exception>
#include <ctime>

using namespace std;

class Bandit
{
	string _Drum;
	string _resDrum;
	int _sumComp;
	int _sumPlayer;

public:

	Bandit();
	Bandit(const Bandit &) = delete;

	char TurnDrum();
	void StartGame();
	void CompareRes();
	void PrintSum();
	int GetSumPlayer(){ return _sumPlayer; };
	void SetSumPlayer(int sumPlayer){ _sumPlayer = sumPlayer; };
	int GetSumCompFile();
	void SetSumCompFile();
};

#endif