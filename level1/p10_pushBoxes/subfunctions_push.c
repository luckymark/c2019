#include "push.h"
int judge(int* s_xst,int *s_yst,char (*pmap)[50]){//判断有几个箱子已经到了目标位置上 ，x1等都是预设的目标的坐标 
	int cnt=0;
	extern stars, line, row;
	int i=0;
	for(;i<stars;i++){
		if(pmap[s_xst[i]][s_yst[i]]=='o'){
			cnt++;
		}
	}
	return cnt;
}
int get_stars(char (*mapp)[50]){
	extern int line;
	extern int row;
	int i, j;
	int stars=0;
	for(i=0;i<row;i++){
		for(j=0;j<line;j++){
			if(mapp[i][j]=='*')stars++;
		}
	}
//	printf("\nstars:%d",stars);
	return stars;
} 
void get_lc(int* s_xst,int *s_yst,char (*mapp)[50]){
	extern  int stars, row, line;
	int i, j;
	int k=0;
	for(i=0;i<row;i++){
		for(j=0;j<line;j++){
			if(mapp[i][j]=='*'){
				s_xst[k]=i;
				s_yst[k]=j;
				k++;
//				printf("\nlocation:%d %d",i, j);
			}
		}
	}
}
void checkstar(int* s_xst,int *s_yst,char (*pmap)[50]){// 让*位置不是o就是* 
	int i=0;
	extern int stars;
	for(;i<stars;i++){
		if(pmap[s_xst[i]][s_yst[i]]==' '){
			pmap[s_xst[i]][s_yst[i]]='*';
		}
	}
}
void map(char (*pmap)[50]){//打印地图 
	int i, j;
	extern int line;
	extern int row;
	for( i=0;i<row;i++){
		for( j=0;j<line;j++){
			printf("%c",pmap[i][j]);
		}
		printf("\n");
	}
	printf("\npress q to quit the game");					   
	printf("\npress r to restart the game\n");
}
void move(int act, int* a, int *b, char (*pmap)[50]){
	if(act==1){
		if(pmap[*a-1][*b]==' '||pmap[*a-1][*b]=='*'){
			pmap[*a][*b]=' ';
			--*a;
			pmap[*a][*b]='s';
		}
		else if(pmap[*a-1][*b]=='o'&&(pmap[*a-2][*b]==' '||pmap[*a-2][*b]=='*')){
			push_box(1,a,b,pmap);
		}
	}
	if(act==2){
		if(pmap[*a+1][*b]==' '||pmap[*a+1][*b]=='*'){
			pmap[*a][*b]=' ';
			++*a; 
			pmap[*a][*b]='s';
		}
		else if(pmap[*a+1][*b]=='o'&&(pmap[*a+2][*b]==' '||pmap[*a+2][*b]=='*')){
			push_box(2,a,b,pmap);
		}
	}
	if(act==3){
		if(pmap[*a][*b-1]==' '||pmap[*a][*b-1]=='*'){
			pmap[*a][*b]=' ';
			--*b;
			pmap[*a][*b]='s';
		}
		else if(pmap[*a][*b-1]=='o'&&(pmap[*a][*b-2]==' '||pmap[*a][*b-2]=='*')){
			push_box(3,a,b,pmap);
		}
	}
	if(act==4){
		if(pmap[*a][*b+1]==' '||pmap[*a][*b+1]=='*'){
			pmap[*a][*b]=' ';
			++*b;
			pmap[*a][*b]='s';
		}
		else if(pmap[*a][*b+1]=='o'&&(pmap[*a][*b+2]==' '||pmap[*a][*b+2]=='*')){
			push_box(4,a,b,pmap);
		}
	}
}
void push_box(int act, int* a, int *b, char (*pmap)[50]){
	switch(act){
		case 1:
			pmap[*a][*b]=' ';
			--*a;
			pmap[*a][*b]='s';
			pmap[*a-1][*b]='o';
			break;
		case 2:
			pmap[*a][*b]=' ';
			++*a;
			pmap[*a][*b]='s';
			pmap[*a+1][*b]='o';
			break;
		case 3:
			pmap[*a][*b]=' ';
			--*b;
			pmap[*a][*b]='s';
			pmap[*a][*b-1]='o';
			break;
		default:
			pmap[*a][*b]=' ';
			++*b;
			pmap[*a][*b]='s';
			pmap[*a][*b+1]='o';
			break;
			
			
	}
}
