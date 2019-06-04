#include "push_box.h"
int s;
int pace=0; 
void mapping(){    //打印新生成的迷宫 
	int i,j;
	char map[9][20];
	for(i=0;i<9;i++){
		for(j=0;j<20;j++){
			map[i][j]='0';
		}
	}
	int x=0,y=1,z=0;
	int *px=&x;
	int *py=&y; 
	printf("There is 2 levels.Please choose one.\nLevel:");
	scanf("%d",&s);
	Readmap(map);
	map[x][y]='*';
	map[5][4]='o';
	map[7][14]='o';
	map[1][19]='@';
	map[8][8]='@';
	while(map[1][19]!='o'||map[8][8]!='o'){
		int i,j;
		for(i=0;i<9;i++){
			for(j=0;j<20;j++){
				if(map[i][j]=='=')
				map[i][j]=' ';
				printf("%c",map[i][j]);
			}
			
				
			printf("\n");
		}
		cursor(map,px,py);
		system("cls");
	}
}
