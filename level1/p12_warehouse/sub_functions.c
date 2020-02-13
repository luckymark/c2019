#include "head.h"
void stocks(char* goods){
	system("cls");
	puts(goods);
	system("pause");
}
void instore(char* goods){
	system("cls");
	puts("\nthe type of the good:");//”–µ„÷ÿ∏¥ 
	strcat(goods,"\ntype:");
	char type[20];
	gets(type);
	strcat(goods,type);
	puts("\nthe nums of the good:"); 
	strcat(goods,"\nnums:");
	char nums[20];
	gets(nums);
	strcat(goods,nums);
	puts("\nthe information of the good:");
	strcat(goods,"\ninformation:");
	char inf[50];
	gets(inf);
	strcat(goods,inf);
	system("cls");
	
}
char* outofstore(char* goods,char* goodss){
	system("cls");
	puts("the type you want to delete:");
	char type[20];
	char aiming[200]="type:";
	gets(type);
	strcat(aiming,type);
	int i, j; j=0;
	char* point=goods;
	for(i=0;i<strlen(goods);i++){
		if(point==strstr(goods,aiming)){
			point++;i++;j++;
			while(*point!='t'&&*(point++)!='y'&&*(point+=2)!='p'){
				point++;i++;
			}
		}
		goodss[j]=*point;
		i++;point++;j++;
		
	}
	return goodss;
}
void menu(){
	system("cls");
	puts("input 1: show the list of the stocks\n");
	puts("input 2: to store\n");
	puts("input 3: to remove some stocks\n");
	puts("input q: to quit");
}
