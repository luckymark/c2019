#include"head.h"
struct LastPoint Blast,Wlast;

int main()
{
	char board[N][N][L];
	init(board);
	printboard(board);
	while(!winner(board))
	{
		PlayerPos(board);
		printboard(board);
		AIPos(board);
		printboard(board);
		gotomn(Wlast.m,Wlast.n);
		printf("¡ò");
	}
	gotomn(N,-1);
	if(winner(board)==BLACK)
		printf("Black wins!\n");
	if(winner(board)==WHITE)
		printf("White wins!\n");
	return 0;
}
