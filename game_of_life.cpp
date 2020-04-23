#include "game_of_life.h"


bool game_of_life::slucajna_vrijednost()
{
	int n;
	n = 1 + rand() % 10;

	if (n == 1) 
		return true;
	else 
		return false;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	int susjedi=0;
	for (int x = -1; x < 2; x++)
	{
		for (int y = -1; y < 2; y++)
		{
			if (x == 0 && y == 0 || i + x == -1 || i + x == 20 || j + y == -1 || j + y == 40);
			else {
				if (_generacija[i + x][j + y])
					susjedi++;
			}
		}
	}
	if (_generacija[i][j]) {
		if (susjedi < 2 || susjedi >3)
			return false;
		else
			return true;
	}
	else if (susjedi == 3)
		return true;

	return false;
}

game_of_life::game_of_life()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j]=slucajna_vrijednost();
		}
	}
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_sljedeca_generacija[i][j] = celija_zauzeta(i, j);
		}
	}
	
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

void game_of_life::iscrtaj()
{
	double postotak=0;
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (_generacija[i][j]) {
				cout << "*";
				postotak++;
			}
			else 
				cout << "-";
		}
		cout << endl;
	}
	cout << "zivi:" << postotak / (REDAKA * STUPACA) * 100 << "%" << endl;
}
