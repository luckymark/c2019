#include "pch.h"
#include "PossiblePositionManager.h"
/*
	对位置进行排序，选择分数最高的位置
	count:实际位置数量
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
	降序排列坐标
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