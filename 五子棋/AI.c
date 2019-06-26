#include"gobang.h"
#include"AI.h"
int order1=1;//一般序号 
int order2=1;
int max=-10000;
int max_order=1;

struct position digital_max[226];
struct position digital_min[226]; 

void initialize_digital_min(){
	int i; 
	for(i=1;i<226;i++){
		digital_min[i].x=0;
		digital_min[i].y=0;
		digital_min[i].score=0;
	}
}
void initialize_digital_max(){
	int i; 
	for(i=1;i<226;i++){
		digital_max[i].x=0;
		digital_max[i].y=0;
		digital_max[i].score=0;
	}
}
void min_sense(){ //min层找黑棋分最大的,得到digital_min的值  
	initialize_digital_min();
	int i,j;
	order2=1;
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			if(board[i][j].status!=0){
				continue;
			}
			board[i][j].status=1;
			digital_min[order2].score=evaluation(1);
			board[i][j].status=2;
			if(evaluation(2)>digital_min[order2].score){//如果防守更有利就防守 
				digital_min[order2].score=evaluation(2);
			}
			digital_min[order2].x=i;
			digital_min[order2].y=j;
			board[i][j].status=0;
			++order2;
		}
	} 
} 
int sense(){//max层，返回digital_max 
	int i,j,a,min,min_order;
	initialize_digital_max();
	order1=1; 
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			if(board[i][j].status!=0){
				continue;
			}
			board[i][j].status=2;
			min=0;
			min_order=1;
			min_sense();
			for(a=1;a<order2;a++){
				if(digital_min[a].score>min){//找到黑子分最大（对机器来说最不利的） 
					min=digital_min[a].score;
					min_order=a;
				}
			}
			board[digital_min[min_order].x][digital_min[min_order].y].status=1;//对黑子最有利处模拟落黑子 
			digital_max[order1].score=evaluation(2);
			board[i][j].status=1;
			if(evaluation(1)>digital_max[order1].score){//如果防守更有利就防守 
				digital_max[order1].score=evaluation(1);
			}
			digital_max[order1].score=digital_max[order1].score-min;//白子分-黑子分 为棋面局势分
			digital_max[order1].x=i;
			digital_max[order1].y=j;
			board[digital_min[min_order].x][digital_min[min_order].y].status=0;
			board[i][j].status=0;
			++order1; 
		}
	}
}


int ai_move(){
	int i;
	max=-10000;
	max_order=1;
	for(i=1;i<order1;i++){
		if(digital_max[i].score>max){
			max=digital_max[i].score;
			max_order=i;
		}
	}
	board[digital_max[max_order].x][digital_max[max_order].y].status=2;
	judge(2);
}
