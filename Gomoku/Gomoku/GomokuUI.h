#pragma once //这个只是每个cpp调用的时候编译一遍，除了结构的成员函数，其他的函数还是写在cpp文件里吧
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<string>
#include<Windows.h>

#define BOARD_SIZE 11

#define SPACE_VALUE 0
#define PLAYER_VALUE 1
#define AI_VALUE 2
#define POINTER_VALUE 3
#define WRONG_VALUE 4
#define PLAYER_TEMP_VALUE 5 //5 and 6 are for choice-tree
#define AI_TEMP_VALUE 6

#define SPACE_PIECE pieceIcon[0]
#define PLAYER_PIECE pieceIcon[1] //player is 1
#define AI_PIECE pieceIcon[2] //AI is 2
#define POINTER_PIECE pieceIcon[3]
#define WRONG_PIECE pieceIcon[4]
#define AI_TEMP_PIECE pieceIcon[5] //player is 1
#define PLAYER_TENP_PIECE pieceIcon[6] //AI is 2

//#define PRINT_WHENEVER_PUT_PIECE

#define PRINT_COLOMN_AND_ROW_NUMBER

using namespace std;

extern const string pieceIcon[]; //use when output
extern int board[BOARD_SIZE][BOARD_SIZE];// 0:space, 1:white(player), 2:black(AI), 3:pointer
extern int pieceN;

void initializeProgram();
void initializeBoard();
void printBoard();

struct pointStruct {
	int column;
	int row;
	pointStruct(){};
	pointStruct(int c, int r) :column(c), row(r) {};
	pointStruct operator + (const pointStruct & b) const
	{
		return pointStruct(column + b.column, row + b.row);
	}
	pointStruct operator - (const pointStruct & b) const
	{
		return pointStruct(column - b.column, row - b.row);
	}
	pointStruct operator - () const
	{
		return pointStruct(-column, -row);
	}
	//int * pointStruct are after struct clarification
	bool valid() const
	{
		return (column >= 0 && row >= 0 && column < BOARD_SIZE && row < BOARD_SIZE);
	}
	bool canPutHere() const
	{
		return (valid() && (getValue() == SPACE_VALUE || getValue() == POINTER_VALUE));
	}
	int getValue() const
	{
		return (valid() ? board[column][row] : WRONG_VALUE);
	}
	const string & getChar() const
	{
		return (valid() ? pieceIcon[getValue()] : WRONG_PIECE);
	}
	bool putPiece(int pieceId) const//PUT VALUE!! 3 is pointer, 1 or 2 is player, 0 is space
	{
		if (!canPutHere())
		{
			if (pieceId == AI_VALUE || pieceId == PLAYER_VALUE)
			{
				printBoard();
				cout << "ERROR: put an not-temporary piece on an occupied point (" << column << "," << row << "): " << getChar() << "\n";
			}
			return false;
		}
		board[column][row] = pieceId;
#ifdef PRINT_WHENEVER_PUT_PIECE
		printBoard();
		//system("pause");
#endif
		return true;
	}
	void removePiece() const
	{
		if (getValue() == PLAYER_VALUE || getValue() == AI_VALUE)
		{
			return;
		}
		board[column][row] = SPACE_VALUE;
	}
	bool operator == (const pointStruct & b) const//if it's the same point
	{
		return (column == b.column && row == b.row);
	}
};
pointStruct operator * (const int multiple, const pointStruct & b);

const pointStruct dire[8] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
//a3 s6 d4 w1
//const pointStruct dire[4]{(-1,1),(-1,0),(-1,1),(0,-1)};

pointStruct someonePutPiece(int player, pointStruct point);
pointStruct playerPutPiece(int player, pointStruct point);
int gameOver(pointStruct);
int runGame();
int welcome();