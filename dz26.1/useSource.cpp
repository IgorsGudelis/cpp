#include <iostream>
#include "dz26.1.h"

int main()
{

	srand(time(NULL));

	Bandit Comp;
	int sumPlayer;
	char play = 'y';

	string exBadAnswer = "Answer must be: y or n !!! Try again!";
	string exBadNumberSum = "Quantity coins must be from 1 until 50 !!! Try again!";
	string exBadSymbolSum = "Sum coins must be number !!! Try again!";

	Comp.GetSumCompFile();

	while (play == 'y')
	{

		cout << "Welcome to Casino - \"Last Chance\"!!!" << endl;
		cout << endl;
		Comp.PrintSum();
		cout << "Input coins(Max 50): ";
		cin >> sumPlayer;

		while (!cin || sumPlayer < 0 || sumPlayer > 50 || sumPlayer == 0)
		{
			if (!cin)
			{
				try
				{
					cin.clear();
					fflush(stdin);
					throw exBadSymbolSum;

				}
				catch (string &)
				{
					cout << exBadSymbolSum << endl;
					cout << "Input coins(Max 50): ";
					cin >> sumPlayer;
				}
			}
			else if (sumPlayer < 0 || sumPlayer > 50 || sumPlayer == 0)
			{
				try
				{
					throw exBadNumberSum;
				}
				catch (string &)
				{
					cout << exBadNumberSum << endl;
					cout << "Input coins(Max 50): ";
					cin >> sumPlayer;
					cout << endl;
				}
			}
		}


		if (Comp.GetSumPlayer() != 0)
		{//if rested coins < 10
			Comp.SetSumPlayer(sumPlayer + 5);
		}
		else
		{
			Comp.SetSumPlayer(sumPlayer);
		}

		while (Comp.GetSumPlayer() >= 10 && play == 'y')
		{
			Comp.StartGame();
			Comp.CompareRes();
			Comp.PrintSum();
			
			if (Comp.GetSumPlayer() >= 10)
			{

				cout << endl;
				cout << "continue play?\npress (y/n): ";
				cin >> play;
				cout << endl;

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
							Comp.SetSumCompFile();
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
						cout << "continue play?\npress: (y/n)";
						cin >> play;
						cout << endl;
					}
				}
			}
		}

		// end of the game
		cout << endl;
		cout << "continue play?\npress (y/n): ";
		cin >> play;
		cout << endl;

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
					Comp.SetSumCompFile();
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
				cout << "continue play?\npress: (y/n)";
				cin >> play;
				cout << endl;
			}
		}

		cout << endl;
		cout << endl;
	}

	return 0;
}