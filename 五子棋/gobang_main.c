#include"gobang.h"
struct Board board[15][15];
int main() {
	int m=0,n=0;
	int *x=&m;
	int *y=&n; 
	initialize_board();
	printf_board();
	int a;
	while(1){
		cursor(x,y);//�ƶ����+���� 
		sense();//��� 
		ai_move();//�������� 
		
		system("cls");
		printf_board();
	}
	system("pause");
	return 0;
}
