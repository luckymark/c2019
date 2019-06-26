#include"gobang.h"
#include"AI.h"
int order1=1;//һ����� 
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
void min_sense(){ //min���Һ��������,�õ�digital_min��ֵ  
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
			if(evaluation(2)>digital_min[order2].score){//������ظ������ͷ��� 
				digital_min[order2].score=evaluation(2);
			}
			digital_min[order2].x=i;
			digital_min[order2].y=j;
			board[i][j].status=0;
			++order2;
		}
	} 
} 
int sense(){//max�㣬����digital_max 
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
				if(digital_min[a].score>min){//�ҵ����ӷ���󣨶Ի�����˵����ģ� 
					min=digital_min[a].score;
					min_order=a;
				}
			}
			board[digital_min[min_order].x][digital_min[min_order].y].status=1;//�Ժ�����������ģ������� 
			digital_max[order1].score=evaluation(2);
			board[i][j].status=1;
			if(evaluation(1)>digital_max[order1].score){//������ظ������ͷ��� 
				digital_max[order1].score=evaluation(1);
			}
			digital_max[order1].score=digital_max[order1].score-min;//���ӷ�-���ӷ� Ϊ������Ʒ�
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
