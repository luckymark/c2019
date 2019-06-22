#include "pch.h"
#include "Gomoku.h"

int bestX,bestY;
char winner;

//博弈树+ab剪枝
int minimax(int role, int alpha, int beta, int depth) {
	/*int score1 = evaluate(role);
	int score2 = evaluate(role == PLAYER ? COMPUTER : PLAYER);


	if (score1 >= 50000) {
		return INF - 1000 - (DEPTH - depth);
	}
	if (score2 >= 50000) {
		return -INF + 1000 + (DEPTH - depth);
	}*/


	if (depth == 0) {
		int scores = evaluateAll(role);
		return scores;
	}

	int count = 0,length = 0;
	Pos* pos = getPossiblePositions(&length);

	while (length>0) {
		//int scores1 = 0,scores2 = 0;
		Pos p = pos[count];

		setChessboard(p.x, p.y, role);
		//updateScores(p.x, p.y, &scores1, &scores2, 0);

		int val = -minimax(role == PLAYER ? COMPUTER : PLAYER, -beta, -alpha, depth - 1);
		if (depth == DEPTH) {
			printf("Minimax: scores:%d in pos(%d,%d)\n", val, p.x, p.y);
		}
		setChessboard(p.x, p.y, EMPTY);
		//updateScores(p.x, p.y, &scores1, &scores2,1);
		if (val >= beta) {
			free(pos);
			return beta;
		}
		if (val > alpha) {
			alpha = val;
			if (depth == DEPTH) {
				//updateScores(p.x, p.y, &scores1, &scores2, 2);
				bestX = p.x;
				bestY = p.y;
			}
		}

		count++;
		if (count >= MAXCOUNT) {
			break;
		}
	}
	free(pos);
	return alpha;

}
//获取下一步
void getStep(int x, int y, int* resultX, int* resultY) {
	int scores1 = 0, scores2 = 0;
	//updateScores(x, y, &scores1, &scores2, 0);
	/*int score1 = evaluate(COMPUTER);
	printf("getMove: scores:%d in pos(%d,%d)\n", score1, x, x);*/
	int scores = minimax(COMPUTER, -INF, INF, DEPTH);
	*resultX = bestX; *resultY = bestY;
}
//重置游戏状态
void reloadWinner() {
	winner = EMPTY;
}