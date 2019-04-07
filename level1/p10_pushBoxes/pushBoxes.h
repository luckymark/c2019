#include <iostream>
#include <cmath>
#include <ctime>
#include <Windows.h>
#include <fstream>
#include <cstdio>
#include "point.h"
using namespace std;



int makeMap()
//Actually it is to input maze from map.txt... 
//and Please guarantee the correctness of the map
{
	ifstream fin;
	fin.open("map.txt");
	for (int input_c = 0; input_c < mapSize; input_c++)
	{
		char inputLine[inputSize];
		fin.getline(inputLine, inputSize);
		int inputLength = min(mapSize, (int)strlen(inputLine));
		int input_r;
		for (input_r = 0; input_r < inputLength; input_r++)
		{
			for (int i = 0; i < strlen(elementChar); i++)
			{
				if (inputLine[input_r] == elementChar[i])
				{
					point(input_c,input_r).intValue() = i;
					if (i % destValue == youValue)
					{
						you = point(input_c, input_r);
					}
					else if (i >= destValue)
					{
						unfinished++;
					}
					break;
				}
			}
		}
		while (input_r < mapSize)
		{
			mapData[input_c][input_r] = nothingValue;
			input_r++;
		}
	}
	return 0;
}

void display()
{
	system("cls");
	for (int i = 0; i < mapSize; i++)
	{
		for (int j = 0; j < mapSize; j++)
		{
			cout << point(i,j).charValue();
		}
		cout  << "|" << endl;
	}
	for (int i = 0; i < mapSize; i++)
		cout << "-";
	cout << endl << "Unfinished box: " << unfinished << endl;
}

bool move()
{
	char inputchar;
	cout << "Please move using \"asdw\":";
	cin >> inputchar;
	switch (tolower(inputchar))
	{
	case 'w': dire = dire_up; break;
	case 's': dire = dire_down; break;
	case 'a': dire = dire_left; break;
	case 'd': dire = dire_right; break;
	default:
		cout << "Wrong input." << endl;
		system("pause");
		return false;
	}
	moveStep();
	return (!unfinished);
}

bool moveStep()
{
	bool canMove = false;
	point nextPoint = you + dire, next2Point = nextPoint + dire;
	//Situations that can move:
	//1. Cur == empty
	//2. cur == box && next == empty
	if (nextPoint.isValid() && nextPoint.intValue() % destValue != wallValue)
	{
		if (nextPoint.intValue() % destValue != boxValue ||
			next2Point.isValid() &&
			next2Point.intValue() % destValue == nothingValue)
		{
			canMove = true;
		}
	}
	if (canMove)
	{
		if (nextPoint.intValue() % destValue == boxValue)
		{
			if (nextPoint.intValue() >= destValue)
			{
				unfinished++;
			}
			if (next2Point.intValue() >= destValue)
			{
				unfinished--;
			}
			nextPoint.intValue() -= boxValue;
			next2Point.intValue() += boxValue;
		}
		you.intValue() -= youValue;
		nextPoint.intValue() += youValue;

		you = nextPoint;
		return true;
	}
	else return false;
}

int playGame()
{
	bool win = false;
	do
	{
		display();
		win = move();
	} while (!win);

	display();
	cout << "You win!" << endl
		<< "You use " << double(clock()) / CLOCKS_PER_SEC << " seconds!";
	return 0;
}
