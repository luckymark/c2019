/*
	Status.cpp
	棋盘状态检测与管理
*/
#pragma once
#include "pch.h";
#include "Gomoku.h";

char getPointStatus(int x, int y, char pointType);
/**
	<Public>检测棋盘当前状态.
	0:未分胜负;1:Player;2:Computer;3:Draw
*/
char getBoardStatus() {
	int jump = EMPTY,//深层循环跳出的标记
		fullPoint = 0;//如果棋盘全满返回3
	for (int i = 0; i < WIDTH; i++) {
		for (int c = 0; c < WIDTH; c++) {
			char pointType = getChessboard(i, c);
			if (pointType == EMPTY) {
				continue;
			}
			else {
				char st = getPointStatus(i, c, pointType);
				if (st !=EMPTY) {
					jump = st;
					break;
				}
				fullPoint++;
			}
		}
		if (jump!= EMPTY) {
			break;
		}
	}
	if (fullPoint == WIDTH * WIDTH) {
		jump = DRAW;
	}
	printf("Status: %s\n", jump == EMPTY ? "EMPTY" : jump == PLAYER ? "Player Win!" : jump == COMPUTER ? "Computer Win!" : "Draw");
	return jump;
}

/**
	获取每一点的状态
*/
char getPointStatus(int x, int y, char pointType) {
	if (x + 4 < WIDTH) {
		if (getChessboard(x + 1, y) == pointType &&
			getChessboard(x + 2, y) == pointType &&
			getChessboard(x + 3, y) == pointType &&
			getChessboard(x + 4, y) == pointType)
		{
			return pointType;
		}
		if (y + 4 < WIDTH) {
			if (getChessboard(x + 1, y + 1) == pointType &&
				getChessboard(x + 2, y + 2) == pointType &&
				getChessboard(x + 3, y + 3) == pointType &&
				getChessboard(x + 4, y + 4) == pointType)
			{
				return pointType;
			}
		}
		if (y - 4 >= 0) {
			if (getChessboard(x + 1, y - 1) == pointType &&
				getChessboard(x + 2, y - 2) == pointType &&
				getChessboard(x + 3, y - 3) == pointType &&
				getChessboard(x + 4, y - 4) == pointType)
			{
				return pointType;
			}
		}
	}
	if (y + 4 < WIDTH) {
		if (getChessboard(x, y + 1) == pointType &&
			getChessboard(x, y + 2) == pointType &&
			getChessboard(x, y + 3) == pointType &&
			getChessboard(x, y + 4) == pointType)
		{
			return pointType;
		}
	}
	return EMPTY;
}