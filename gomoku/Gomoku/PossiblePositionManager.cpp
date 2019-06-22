#include "pch.h"
#include "PossiblePositionManager.h"
/*
	��λ�ý�������ѡ�������ߵ�λ��
	count:ʵ��λ������
*/
Pos *getPossiblePositions(int *count) {
	int length = 0;
	Pos* pos = (Pos*)malloc(sizeof(Pos) * WIDTH * WIDTH);
	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < WIDTH; y++) {
			if (getChessboard(x, y) == EMPTY) {
				int scores = getPositionScores(x, y);
				if (pos) {
					pos[length].x = x;
					pos[length].y = y;
					pos[length++].scores = scores;
				}
			}
		}
	}
	sortPositions(pos, length);
	*count = length;
	return pos;
}
/*
	������������
*/
void sortPositions(Pos *pos,int length) {
	for (int i = 0; i < length; i++)
	{
		for (int c =i; c >0; c--)
		{
			if (pos[c].scores > pos[c - 1].scores) {
				Pos temp = pos[c - 1];
				pos[c - 1] = pos[c];
				pos[c] = temp;
			}
			else {
				break;
			}
		}
	}
}