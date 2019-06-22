/*
	Status.cpp
	����״̬��������
*/
#pragma once
#include "pch.h";
#include "Gomoku.h";

char getPointStatus(int x, int y, char pointType);
/**
	<Public>������̵�ǰ״̬.
	0:δ��ʤ��;1:Player;2:Computer;3:Draw
*/
char getBoardStatus() {
	int jump = EMPTY,//���ѭ�������ı��
		fullPoint = 0;//�������ȫ������3
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
	��ȡÿһ���״̬
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