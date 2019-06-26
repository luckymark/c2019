#include"gobang.h"
#include"subfunctions.h"
 
void initialize_board(){
	int i,j;
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			board[i][j].status=0;//0���� 1���� 2���� 3���� ������� �����°��� 
		}
	}
	board[0][0].status=3;
}
void printf_board(){
	int i,j;
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			switch(board[i][j].status)
			{
				case 0:printf("�� ") ;break;
				case 1:printf("��");break;//��ɫ ���� 
				case 2:printf("��");break;//��ɫ ���� 
				case 3:printf("��");break;//��ɫ 
			}
		}
		printf("\n");	
	}
	printf("\n");
}
void cursor(int *x,int *y){
	char c;
	while((c=getch())!=13){
		switch(c){
			case 72:move_1(x,y);
						break;
			case 80:move_2(x,y);
						break;	
			case 75:move_3(x,y);
						break;
			case 77:move_4(x,y);
						break;	 			
			default: break;
		}
		system("cls");
		printf_board();
	}
	board[*x][*y].status=1;
	judge(1);
	system("cls");
	printf_board();
}
void move_1(int *x,int *y){
	if(board[*x-1][*y].status==0){
		if(board[*x][*y].status==3){
			board[*x][*y].status=0;
			--*x;
			board[*x][*y].status=3;
		}
		else{ 
			--*x;
			board[*x][*y].status=3;
		}	
	}
	else{//�����Ϸ�Ϊ���ӻ���� 
		if(board[*x][*y].status==3){
			board[*x][*y].status=0;
			--*x;
		}
		else{
			--*x;
		} 
	}
}
void move_2(int *x,int *y){
	if(board[*x+1][*y].status==0){
		if(board[*x][*y].status==3){
			board[*x][*y].status=0;
			++*x;
			board[*x][*y].status=3;
		}
		else{
			++*x;
			board[*x][*y].status=3;
		}
	}
	else{//�����Ϸ�Ϊ���ӻ���� 
		if(board[*x][*y].status==3){
			board[*x][*y].status=0;
			++*x;
		}
		else{
			++*x;
		} 
	}
}
void move_3(int *x,int *y){
	if(board[*x][*y-1].status==0){
		if(board[*x][*y].status==3){
			board[*x][*y].status=0;
			--*y;
			board[*x][*y].status=3;
		}
		else{
			--*y;
			board[*x][*y].status=3;
		}
	}
	else{//�����Ϸ�Ϊ���ӻ���� 
		if(board[*x][*y].status==3){
			board[*x][*y].status=0;
			--*y;
		}
		else{
			--*y;
		} 
	}
}
void move_4(int *x,int *y){
	if(board[*x][*y+1].status==0){
		if(board[*x][*y].status==3){
			board[*x][*y].status=0;
			++*y;
			board[*x][*y].status=3;
		}
		else{
			++*y;
			board[*x][*y].status=3;
		}
	}
	else{//�����Ϸ�Ϊ���ӻ���� 
		if(board[*x][*y].status==3){
			board[*x][*y].status=0;
			++*y;
		}
		else{
			++*y;
		} 
	}
}

