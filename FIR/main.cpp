#include"head.h"
int main()
{
	char board[N][N][L];
	init(board);
	printboard(board);
	while(!winner(board))
	{
		PlayerPos(board);
		AIPos(board);
		printboard(board);
	}
	if(winner(board)==BLACK)
		printf("Black wins!\n");
	if(winner(board)==WHITE)
		printf("White wins!\n");
	return 0;
}
