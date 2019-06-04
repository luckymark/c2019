#include"warehouse.h"
void output(){
	printf("List:\n");
	int i;
	for(i=0;i<MAX;i++){
		printf("%s:  %d\n",depository[i].type,depository[i].quantity); 
	}
}
void insert(){
	char c[TYPE];
	int i,x;
	printf("enter part type\n");
	scanf("%s",c);
	printf("enter add quantity\n");
	scanf("%d",&x);
	for(i=0;i<MAX;i++){
		if(0==strcmp(c,depository[i].type)){
			depository[i].quantity+=x;
			break;
		}
	}
}
void out(){
	int i,x;
	char c[TYPE];
	printf("enter part type\n");
	scanf("%s",c);
	printf("enter minus quantity\n");
	scanf("%d",&x);
	for(i=0;i<MAX;i++){
		if(0==strcmp(c,depository[i].type)){
			if(depository[i].quantity<x){
				printf("the good is in short supply.");
				break;
			}
			else{
				depository[i].quantity-=x;
				break;
			}
		}
	}
}
void Read(){
	FILE *fp;
	int i;
	fp=fopen("depository.txt","r+");
	if(fp==NULL)
		printf("error");
	else{
		for(i=0;i<MAX;i++){
			fscanf(fp,"%s %d",depository[i].type,&depository[i].quantity);
		}
		fclose(fp);
	}
}
void Write(){
	FILE *fp;
	int i;
	fp=fopen("depository.txt","w");
	for(i=0;i<MAX;i++){
		fprintf(fp,"%s %d\n",depository[i].type,depository[i].quantity);
	}
	fclose(fp);
}
