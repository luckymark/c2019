#include "maze.h"
void map(char (*pmap)[50]){
	int i, j;
	for( i=0;i<=9;i++){
		for( j=0;j<=9;j++){
			printf("%c",pmap[i][j]);
		}
		printf("\n");
	}					   
	
}
void move(int act, int* a, int *b, char (*pmap)[50]){
	if(act==1){
		if(pmap[*a-1][*b]==' '){
			pmap[*a][*b]=' ';
			--*a;
			pmap[*a][*b]='o';
		}
	}
	if(act==2){
		if(pmap[*a+1][*b]==' '){
			pmap[*a][*b]=' ';
			++*a;
			pmap[*a][*b]='o';
		}
	}
	if(act==3){
		if(pmap[*a][*b-1]==' '){
			pmap[*a][*b]=' ';
			--*b;
			pmap[*a][*b]='o';
		}
	}
	if(act==4){
		if(pmap[*a][*b+1]==' '){
			pmap[*a][*b]=' ';
			++*b;
			pmap[*a][*b]='o';
		}
	}
}
