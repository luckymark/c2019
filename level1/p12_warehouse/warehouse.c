#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct goods
{
	char name[16],size[4];
	long long int amount;
	
}GOODS;

void menu(GOODS * Goods,int * n);
void write(GOODS * Goods,int n);
void display(GOODS * Goods,int n);
void input(GOODS** Goods,int * n);
void output(GOODS** Goods,int * n);
long long int is_num(void);

int main(void){
	FILE *fp;
	int max,i;
	
	fp=fopen("warehouse.txt","r");
	fscanf(fp,"%d",&max);
	
	GOODS list[100];
	for(i=0;i<max;i++){
		fscanf(fp,"%s",list[i].name);
		system("pause");
		fscanf(fp,"%lld",&list[i].amount);
		system("pause");
		fscanf(fp,"%s",(list[i].size));
	}
	for(;i<100;i++){
		list[i].amount=0;
	}
	fclose(fp);

	menu(list,&max);
	
	return 0;
}
void menu(GOODS * Goods,int * n){
	char judge;

	do{
		system("cls");
		printf("Welcome to warehouse!\n");
		printf("What do you want to do\n");
		printf("2.display\t3.input\n");
		printf("4.output\t 5.quit\n");
		judge=getch();
		switch(judge){
			case '2':
				display(Goods,*n);
				system("pause");
				break;
			case '3':
				input(&Goods,n);
				break;
			case '4':
				output(&Goods,n);
				break;
			case '5':
				return;
			default:
				printf("Please enter a right number\n");
				system("pause");
		}
		write(Goods,*n);
	}while(judge!='5');
}
void display(GOODS * Goods,int n){
	system("cls");
	for(int i=0;i<n;i++){
		if(0==Goods[i].amount)continue;
		printf("%d.%15s:%d\tSize:%s\n",i+1,Goods[i].name,Goods[i].amount,Goods[i].size);
	
	}
}
void write(GOODS * Goods,int n){
	FILE * fp;
	
	fp=fopen("warehouse.txt","w");
	fprintf(fp,"%d\n",n);
	for(int i=0;i<n;i++){
		if(0==Goods[i].amount)continue;
		fprintf(fp,"%s\n",Goods[i].name);
		fprintf(fp,"%lld\n",Goods[i].amount);
		fprintf(fp,"%s\n",Goods[i].size);
	}
	fclose(fp);
}
void input(GOODS** Goods,int * n){
	int judge;
	
	do{
		display(*Goods,*n);
		printf("Which do you want to input?(enter the number)\n");
		printf("0 to quit\n");
		if(1==scanf("%d",&judge)){
			fflush(stdin);
			if(0==judge)return;
			if(0==(*Goods)[judge-1].amount){
				printf("Do you want to add a kind of new goods?(y to continue)\n");
				if(getch()=='y'){
					printf("Please enter the name:(in 15 words)\n");
					scanf("%s",(*Goods)[judge-1].name);
					printf("Please enter the amount\n");
					(*Goods)[judge-1].amount=is_num();
					printf("Please enter the size(s/m/l)\n");
					fflush(stdin);
					scanf("%s",(*Goods)[judge-1].size);	
				}
				*n=*n+1;	
			}
			else{
				printf("How many %s do you want?\n",(*Goods)[judge-1].name);
				(*Goods)[judge-1].amount=(*Goods)[judge-1].amount+is_num();
			}
		}
		write(*Goods,*n);
	}while(0!=judge);
	

}
void output(GOODS** Goods,int * n){
	int judge;
	long long int delta;
	do{
		display(*Goods,*n);
		printf("Which do you want to output?(enter the number)\n");
		printf("0 to quit\n");
		if(1==scanf("%d",&judge)){
			fflush(stdin);
			if(0==judge)return;
			if(0==(*Goods)[judge-1].amount){
				
				printf("error\n");
				system("pause");	
			}
			else{
				printf("How many %s do you want to out put?\n",(*Goods)[judge+1].name);
				delta=is_num();
				if(delta<(*Goods)[judge-1].amount){
					(*Goods)[judge-1].amount=(*Goods)[judge-1].amount-is_num();
				}
				else{
					(*Goods)[judge-1].amount=0;
				}
			}
		}
		write(*Goods,*n);
	}while(0!=judge);
	

}
long long int is_num(void){
	long long int n;
	int right;

	right=scanf("%lld",&n);
	while(0==right){
		printf("Error,please enter again.\n");
		fflush(stdin);
		right=scanf("%lld",&n);
	}
	
	if(n>=0)return n;
	else return 0;
	
}