#include "head.h"
char* warehouse(FILE* fp){
	menu();
	char n;
	n=getchar();getchar();
	char goods[MAX];
	char goodss[MAX];
	system("cls");
	int i=0;
	while(!feof(fp)){
		goods[i]=fgetc(fp);
		i++;
	}
	char* p;
	p=goods;
	while(n!='q'){
		switch(n){
			case 49:
				stocks(p);//存货列表 
				break;
			case 50:
				instore(p);//入库 
				break;
			case 51:
				p=outofstore(goods,goodss);
				break;
			default:
				n='q';//退出 
		}
		system("cls");
		menu();
		n=getchar();getchar();
	}
	return p;
}
