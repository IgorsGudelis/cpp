//Game Black Jack

#include <iostream>
#include "dz25.2.h"


using namespace std;

int main()
{
	srand(time(NULL));

	GameJack *pBlackJack = new GameJack;
	Player player(pBlackJack);
	string ansPcWin[3] = { "And why I'm not surprised?", "I'm the best of the best!", "See you later loser..." };
	string ansPcLos[3] = { "My congratulations!", "Fools are lucky!", "I think I saw you in the black list!" };
	int SumMen[4];
	char play = 'y';
	int countPlayer;
	int numPlayer = 0;
	char ansMan;
	int notEntry = 0;
	int more = 0;
	int lostPc = 0;

	string exBadAnswer = "Answer must be: y or n !!! Try again!";
	string exBadNumberPlayer = "Quantity players must be from 1 until 4 !!! Try again!";
	string exBadSymbolPlayer = "Qyantity must be number !!! Try again!";

	while (play == 'y')
	{
		numPlayer = 0;

		cout << "Welcome to Casino - \"Last Chance\"!!!" << endl;
		cout << endl;
		cout << "Input quantity players(Max 4): ";
		cin >> countPlayer;

		while (!cin || countPlayer < 0 || countPlayer > 4 || countPlayer == 0)
		{
			if (!cin)
			{
				try
				{
					cin.clear();
					fflush(stdin);
					throw exBadSymbolPlayer;

				}
				catch (string &)
				{
					cout << exBadSymbolPlayer << endl;
					cout << "Input quantity players(Max 4): ";
					cin >> countPlayer;
				}
			}
			else if (countPlayer < 0 || countPlayer > 4 || countPlayer == 0)
			{
				try
				{
					throw exBadNumberPlayer;
				}
				catch (string &)
				{
					cout << exBadNumberPlayer << endl;
					cout << "Input quantity of players(Max 4): ";
					cin >> countPlayer;
				}
			}
		}

		while (countPlayer > 0)
		{
			notEntry = 0;
			player->SetStart();
			cout << endl;
			cout << "*****************************************************" << endl;
			cout << endl;
			cout << "Now Player#" << numPlayer + 1 << " is playing..." << endl;
			cout << endl;
			cout << "Let's start the game!" << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			player->PlayJack();
			player->SumCards();
			cout << "Your sum is: ";
			player->PrintSum();
			cout << endl;
			cout << "Your cards are: ";
			player->PrintCards();
			cout << endl;

			if (player->Getsum() > 21)
			{
				int choise;

				choise = rand() % 3;
				cout << "\t\tPlayer#" << numPlayer + 1 << " win!" << endl;
				cout << "\t       " << ansPcLos[choise] << endl;

				SumMen[numPlayer] = 0;
			}
			else
			{
				cout << "More?" << endl;
				cout << "Input answer(y/n): ";
				cin >> ansMan;
				cout << endl;

				if (ansMan == 'y' || ansMan == 'Y')
				{
					notEntry = 1;
					more = 1;
				}
				else if (ansMan == 'n' || ansMan == 'N')
				{
					notEntry = 1;
					SumMen[numPlayer] = player->Getsum();
				}
				else
				{
					while (!notEntry)
					{
						try
						{
							throw exBadAnswer;
						}
						catch (string &)
						{
							cout << exBadAnswer << endl;
							cout << "More?\npress (y/n): ";
							cin >> ansMan;
							cout << endl;
						}
						if (ansMan == 'y' || ansMan == 'Y')
						{
							notEntry = 1;
							more = 1;
						}
						else if (ansMan == 'n' || ansMan == 'N')
						{
							notEntry = 1;
							SumMen[numPlayer] = player->Getsum();
						}
					}
				}
			}

			while (more)
			{
				notEntry = 0;
				more = 0;
				player->NewCard();
				player->SumCards();
				cout << endl;
				cout << "Your sum is: ";
				player->PrintSum();
				cout << endl;
				cout << "Your cards are: ";
				player->PrintCards();
				cout << endl;

				if (player->Getsum() > 21)
				{
					int choise;

					choise = rand() % 3;
					cout << "\t\tPlayer#" << numPlayer + 1 << " lose!" << endl;
					cout << "\t       " << ansPcWin[choise] << endl;

					SumMen[numPlayer] = 0;
				}
				else
				{
					cout << "More?" << endl;
					cout << "Input answer(y/n): ";
					cin >> ansMan;

					if (ansMan == 'y' || ansMan == 'Y')
					{
						notEntry = 1;
						more = 1;
					}
					else if (ansMan == 'n' || ansMan == 'N')
					{
						notEntry = 1;
						SumMen[numPlayer] = player->Getsum();
					}
					else
					{
						while (!notEntry)
						{
							try
							{
								throw exBadAnswer;
							}
							catch (string &)
							{
								cout << exBadAnswer << endl;
								cout << "More?\npress (y/n): ";
								cin >> ansMan;
								cout << endl;
							}
							if (ansMan == 'y' || ansMan == 'Y')
							{
								notEntry = 1;
								more = 1;
							}
							else if (ansMan == 'n' || ansMan == 'N')
							{
								notEntry = 1;
								SumMen[numPlayer] = player->Getsum();
							}
						}
					}
				}

			}
			--countPlayer;
			++numPlayer;
		}

		--numPlayer;

		cout << "*****************************************************" << endl;
		cout << endl;

		while (countPlayer <= numPlayer)
		{
			lostPc = 0;

			if (SumMen[numPlayer] != 0)
			{
				cout << "Now Comp is playing with Player#" << numPlayer + 1 << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				cout << "My turn" << endl;
				player->SetStart();
				player->PlayJack();
				player->SumCards();
				cout << endl;
				cout << "MY cards are: ";
				player->PrintCards();
				cout << endl;
				cout << "My sum is: ";
				player->PrintSum();


				if (player->Getsum() < 17)
				{
					player->NewCard();
					player->SumCards();
					cout << endl;
					cout << "MY cards are: ";
					player->PrintCards();
					cout << endl;
					cout << "My sum is: ";
					player->PrintSum();

					if (player->Getsum() > 21)
					{
						lostPc = 1;
					}
				}
			}

			if (!lostPc)
			{
				if (SumMen[numPlayer] != 0)
				{
					if (player->Getsum() > SumMen[numPlayer])
					{
						int choise;

						choise = rand() % 3;
						cout << "Sum player#" << numPlayer + 1 << " is : ";
						cout << SumMen[numPlayer] << endl;
						cout << endl;
						cout << "\t\tPlayer#" << numPlayer + 1 << " lose!" << endl;
						cout << "\t       " << ansPcWin[choise] << endl;
						cout << endl;
						cout << "*****************************************************" << endl;
						cout << endl;
					}
					if (player->Getsum() == SumMen[numPlayer])
					{
						cout << "Sum player#" << numPlayer + 1 << " is : ";
						cout << SumMen[numPlayer] << endl;
						cout << endl;
						cout << "\t\tDrawn game!" << endl;
						cout << endl;
						cout << "*****************************************************" << endl;
						cout << endl;
					}
					if (player->Getsum() < SumMen[numPlayer])
					{
						int choise;

						cout << "Sum player#" << numPlayer + 1 << " is : ";
						cout << SumMen[numPlayer] << endl;
						choise = rand() % 3;
						cout << endl;
						cout << "\t\tPlayer#" << numPlayer + 1 << " win!" << endl;
						cout << "\t       " << ansPcLos[choise] << endl;
						cout << endl;
						cout << "*****************************************************" << endl;
						cout << endl;
					}
				}
			}
			else
			{
				if (SumMen[numPlayer] != 0)
				{
					int choise;

					cout << "Sum player#" << numPlayer + 1 << " is : ";
					cout << SumMen[numPlayer] << endl;
					choise = rand() % 3;
					cout << endl;
					cout << "\t\tPlayer#" << numPlayer + 1 << " win!" << endl;
					cout << "\t       " << ansPcLos[choise] << endl;
					cout << endl;
					cout << "*****************************************************" << endl;
					cout << endl;
				}
			}

			--numPlayer;
		}

		// end of the game
		cout << "continue play?\npress (y/n): " << endl;
		cin >> play;

		while (play != 'y')
		{
			try
			{
				if (play == 'Y')
				{
					play = 'y';
				}
				else if (play == 'n' || play == 'N')
				{
					exit(0);
				}
				else
				{
					throw exBadAnswer;
				}
			}
			catch (string &)
			{
				cout << exBadAnswer << endl;
				cout << "continue play?\npress: (y/n)" << endl;
				cin >> play;
			}
		}
		cout << endl;
		cout << endl;
	}

	return 0;
}