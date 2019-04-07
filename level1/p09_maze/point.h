#include <iostream>
#include <cmath>
#include <ctime>
#include <Windows.h>
#include <fstream>
#include <cstdio>
#include <stack>

using namespace std;

const int mSize = 10;
char mazeData[mSize][mSize] = {};
const char wall = '*', youChar = 'O', exiChar = 'X';

struct point {
	int column;
	int row;
}you, exi;

point dire;

bool moveStep();
void makeRightPath(point&, point&);
void makeWrongPath(point&, point&);

point dire_up = { -1, 0 },
	dire_down = { 1, 0 },
	dire_left = { 0, -1 },
	dire_right = { 0, 1 };

point operator + (const point &a, const point &b)
{
	return point{ a.column + b.column, a.row + b.row };
}

bool operator == (const point &a, const point &b)
{
	return (a.column == b.column && a.row == b.row);
}

bool isValid(const point p)
{
	return
		p.column >= 0 &&
		p.column < mSize &&
		p.row >= 0 &&
		p.row < mSize;
}

char & value(point n)
{
	//n should be valid
	return mazeData[n.column][n.row];
}


int makeMaze() //Actually it is to input maze from maze.txt...
{
	ifstream fin;
	//freopen("maze.txt", "r", stdin);
	fin.open("maze.txt");
	for (int input_c = 0; input_c < mSize; input_c++)
	{
		for (int input_r = 0; input_r < mSize; input_r++)
		{
			char temp = fin.get();
			//char temp = getchar();
			if (temp == youChar)
			{
				you.column = input_c;
				you.row = input_r;
			}
			else if (temp == exiChar)
			{
				exi.column = input_c;
				exi.row = input_r;
			}
			mazeData[input_c][input_r] = temp;
		}
		//getchar();
		fin.get();
	}
	return 0;
}



//void makeRightPath(point& cur, point& end)
//{
//
//}
//
//stack<point> paths;
//
//void makeWrongPath(point&, point&);
//
//int makeMaze()
//{
//	srand(unsigned int (time(NULL)));
//	memset(mazeData, '*', mSize * mSize);
//	
//	//the maze always puts the player on the first line and the exit on the lower side
//	you.column = 1;
//	you.row = rand() % mSize;
//	value(you) = youChar;
//
//	exi.column = mSize - 1;
//	exi.row = rand() % mSize;
//	value(exi) = exiChar;
//
//	makeRightPath(you, exi);
//	
//	makeWrongPath(you);
//
//	return 0;
//}

void display()
{
	system("cls");
	for (int i = 0; i < mSize; i++)
	{
		for (int j = 0; j < mSize; j++)
		{
			cout << mazeData[i][j];
		}
		cout << endl;
	}
}

bool move()
{
	char inputchar;
	cout << "Please move using \"asdw\":";
	cin >> inputchar;
	switch (tolower(inputchar))
	{
	//case 'w': input = 0; break;
	//case 's': input = 1; break;
	//case 'a': input = 2; break;
	//case 'd': input = 3; break;
	case 'w': dire = { -1, 0 }; break;
	case 's': dire = { 1, 0 }; break;
	case 'a': dire = { 0, -1 }; break;
	case 'd': dire = { 0, 1 }; break;
	default:
		cout << "Wrong input." << endl;
		system("pause");
		return false;
	}
	moveStep();
	return (you == exi);
}

bool moveStep()
{
	if (isValid(you + dire) && value(you + dire) != wall)
	{
		value(you + dire) = youChar;
		value(you) = ' ';
		you = you + dire;
		
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