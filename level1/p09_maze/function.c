#include"maze.h"
void move_1(char map[][20],int *px,int *py){
	if(map[*px-1][*py]!='#'){
		map[*px][*py]=' ';
		--*px;
		map[*px][*py]='o';
	}
}
void move_2(char map[][20],int *px,int *py){
	if(map[*px+1][*py]!='#'){
		map[*px][*py]=' ';
		++*px;
		map[*px][*py]='o';
	}
}
void move_3(char map[][20],int *px,int *py){
	if(map[*px][*py-1]!='#'){
		map[*px][*py]=' ';
		--*py;
		map[*px][*py]='o';	
	}
}
void move_4(char map[][20],int *px,int *py){
	if(map[*px][*py+1]!='#'){
		map[*px][*py]=' ';
		++*py;
		map[*px][*py]='o';
	}
}

