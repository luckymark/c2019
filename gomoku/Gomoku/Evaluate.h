#pragma once
#include "Gomoku.h";
#include "pch.h"

#define ROW 0
#define COL 1
#define DIAG1 2
#define DIAG2 3
//匹配模式长度
#define PATERNLENGTH 16

void getPositionStr(int type, int x, int y, char* str1, char* str2);

char* (paternTable[]) = {
	"11111",
	"011110",
	"011100",
	"001110",
	"011010",
	"010110",
	"11110",
	"01111",
	"11011",
	"10111",
	"11101",
	"001100",
	"001010",
	"010100",
	"000100",
	"001000"
};

//模式相应的分数
int paternScores[] = {
	50000,
	4320,
	720,
	720,
	720,
	720,
	720,
	720,
	720,
	720,
	720,
	120,
	120,
	120,
	20,
	20
};
