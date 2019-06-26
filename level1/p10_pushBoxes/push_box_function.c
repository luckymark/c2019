#include"push_box.h"
void move_1(char map[][20],int *px,int *py){
	if(map[*px-1][*py]!='#'){
		if(map[*px-1][*py]=='o'){
			if(map[*px-2][*py]!='#'&&map[*px-2][*py]!='o'){
				map[*px][*py]=' ';
				--*px;
				map[*px][*py]='*';
				map[*px-1][*py]='o';
				++pace;
			}
		}
		else{
			map[*px][*py]=' ';
			--*px;
			map[*px][*py]='*';
			++pace;
		}
	}
}
void move_2(char map[][20],int *px,int *py){
	if(map[*px+1][*py]!='#'){
		if(map[*px+1][*py]=='o'){
			if(map[*px+2][*py]!='#'&&map[*px+2][*py]!='o'){
				map[*px][*py]=' ';
				++*px;
				map[*px][*py]='*';
				map[*px+1][*py]='o';
				++pace;
			}
		}
		else{
			map[*px][*py]=' ';
			++*px;
			map[*px][*py]='*';
			++pace;
		}
	}
}
void move_3(char map[][20],int *px,int *py){
	if(map[*px][*py-1]!='#'){
		if(map[*px][*py-1]=='o'){
			if(map[*px][*py-2]!='#'&&map[*px][*py-2]!='o'){
				map[*px][*py]=' ';
				--*py;
				map[*px][*py]='*';
				map[*px][*py-1]='o';
				++pace;
			}
		}
		else{
			map[*px][*py]=' ';
			--*py;
			map[*px][*py]='*';
			++pace;
		}
	}
}
void move_4(char map[][20],int *px,int *py){
	if(map[*px][*py+1]!='#'){
		if(map[*px][*py+1]=='o'){
			if(map[*px][*py+2]!='#'&&map[*px][*py+2]!='o'){
				map[*px][*py]=' ';
				++*py;
				map[*px][*py]='*';
				map[*px][*py+1]='o';
				++pace;
			}
		}
		else{
			map[*px][*py]=' ';
			++*py;
			map[*px][*py]='*';
			++pace;
		}
	}
}
void cursor(char map[][20],int *px,int *py){        //光标 键盘方向键 
	char c=getch();
	switch(c){
		case 72:move_1(map,px,py);
					break;
		case 80:move_2(map,px,py);
					break;	
		case 75:move_3(map,px,py);
					break;
		case 77:move_4(map,px,py);
					break;	 			
		default: break;
	}
}
void Readmap(char map[][20]){    //读入地图 
	FILE *fp;
	int i,j;
	switch(s)
	{
		case 1:fp=fopen("map1.txt","r");break;
		case 2:fp=fopen("map2.txt","r");break;
		default:break;
	}
	if(fp==NULL)
		printf("error\n");
	else
	{
		for(i=0;i<9;i++)
		{
			fscanf(fp,"%s",map[i]); 
		}
		fclose(fp);
	}
} 
void writepace(){
	FILE *fp;
	switch(s)
	{
		case 1:fp=fopen("level1_score.txt","w");break;
		case 2:fp=fopen("level2_score.txt","w");break;
		default:break;
	}
	fprintf(fp,"%d",pace);
	fclose(fp);
}

 
 
