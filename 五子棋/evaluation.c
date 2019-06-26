#include"gobang.h"
#include"evaluation.h"
int count_empty_number(int n[],int chesscolour){ //计算连子数空格数 并传一排的分 棋盘0  黑子1 白子2 光标3 
	int empty=0;
	int number=0;
	int scoretmp=0;
	if(n[0]==0){
		empty++;
	}
	else if(n[0]==chesscolour){
		number++;
	}
	int i=1;
	while(i<15){
		if(n[i]==chesscolour){
			number++;
		}
		else if(n[i]==0){
			if(number==0){//00
				empty=1;
			}
			else{
				scoretmp+=score_table(number,empty+1);//10(1)
				empty=1;
				number=0;
			}
		}
		else if(n[i]!=3){//12
			scoretmp+=score_table(number,empty);
			empty=0;
			number=0;	
		}
		i++;
	}
	scoretmp +=score_table(number,empty);//防止n[14]为1 
	return scoretmp;
}
int score_table(int number,int empty){//根据连子数判断活m死m 
	if(number==5){
		return WIN5;
	}
	else if(number==4){
		if(empty==2){
			return ALIVE4;
		}
		else if(empty==1){
			return DIE4;
		}
	}
	else if(number==3){
		if(empty==2){
			return ALIVE3;
		}
		else if(empty==1){
			return DIE3;
		}
	}
	else if(number==2){
		if(empty==2){
			return ALIVE2;
		}
		else if(empty==1){
			return DIE2;
		}
	}
	else if(number==1&&empty==2){
		return ALIVE1;
	}
	return 0;
}
int evaluation(int chesscolour){//扫描整个棋盘总赋分 ，传整个棋盘某个子的分 
	int Score=0;
	int i,j,a,b;
	int n[15];
	memset(n,0,sizeof(n));
	for(i=0;i<15;i++){//扫描横排 
		for(j=0;j<15;j++){
			n[j]=board[i][j].status;
		}
		Score+=count_empty_number(n,chesscolour); 
		memset(n,0,sizeof(n));//n重新初始化为0 
	}
	for(j=0;j<15;j++){//扫描竖排 
		for(i=0;i<15;i++){
			n[i]=board[i][j].status; 
		}
		Score+=count_empty_number(n,chesscolour);
		memset(n,0,sizeof(n));
	}
	for(j=0;j<15;j++){//扫描棋盘斜上半部分（\） 
		for(a=0,b=j;a<15&&b<15;a++,b++){
			n[a]=board[a][b].status;
		}
		Score+=count_empty_number(n,chesscolour);
		memset(n,0,sizeof(n));
	}
	for(i=1;i<15;i++){//斜下半部分 
		for(a=i,b=0;a<15&&b<15;a++,b++){
			n[b]=board[a][b].status;
		}
		Score+=count_empty_number(n,chesscolour);
		memset(n,0,sizeof(n));
	} 
	for(j=0;j<15;j++){//反斜上半部分（/） 
		for(a=0,b=j;b>=0&&a<15;a++,b--){
			n[a]=board[a][b].status;
		}
		Score+=count_empty_number(n,chesscolour);
		memset(n,0,sizeof(n));
	}
	for(i=1;i<15;i++){//反斜下半部分 
		for(a=i,b=14;a<15&&b>=0;a++,b--){
			n[a-i]=board[a][b].status;
		} 
		Score+=count_empty_number(n,chesscolour);
		memset(n,0,sizeof(n));
	}
	return Score;
} 
