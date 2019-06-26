#include"gobang.h"
void judge(int b){
	int i,j,a;
	for(i=0;i+4<15;i++){
		for(j=0;j<15;j++){
			if(board[i][j].status==b&&board[i+1][j].status==b&&board[i+2][j].status==b&&board[i+3][j].status==b&&board[i+4][j].status==b){
				system("cls");
				printf_board();
				if(b==1){
					printf("You win the game!");
				}
				else printf("You lose the game!");
				exit(0);
				system("pause");
			}
		}
	}
	for(i=0;i<15;i++){
		for(j=0;j+4<15;j++){
			if(board[i][j].status==b&&board[i][j+1].status==b&&board[i][j+2].status==b&&board[i][j+3].status==b&&board[i][j+4].status==b){
				system("cls");
				printf_board();
				if(b==1){
					printf("You win the game!");
				}
				else printf("You lose the game!");
				exit(0);
				system("pause");
			}
		}
	}
	for(i=0;i+4<15;i++){
		for(j=0;j+4<15;j++){
			if(board[i][j].status==b&&board[i+1][j+1].status==b&&board[i+2][j+2].status==b&&board[i+3][j+3].status==b&&board[i+4][j+4].status==b){
				system("cls");
				printf_board();
				if(b==1){
					printf("You win the game!");
				}
				else printf("You lose the game!");
				exit(0);
				system("pause");
			}
		}
	}
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			if(board[i][j].status==b&&board[i+1][j-1].status==b&&board[i+2][j-2].status==b&&board[i+3][j-3].status==b&&board[i+4][j-4].status==b){
				system("cls");
				printf_board();
				if(b==1){
					printf("You win the game!");
				}
				else printf("You lose the game!");
				exit(0);
				system("pause");
			}
		}
	}
}
