#include "push.h"
void get_map(int n, char(*mapp)[50]){
	extern int line;
	extern int row;
	FILE *fp;
	switch (n){
		
		case 1:
			fp=fopen("easy.txt","r");
			break;
		case 2:

			fp=fopen("normal.txt","r");
			break;
		case 3:
			fp=fopen("hard.txt","r");
			break;
		default:
			fp=fopen("hell.txt","r");
	}
	
	if(fp==NULL)printf("fail to load the map");
	else{
		int a;int i, j;
		for(i=0;i<50;i++){
			for(j=0;j<50;j++){
				a=fgetc(fp);
				if(a=='\n')break;
				else mapp[i][j]=a;
				line++;
				if(a==EOF)break;
				
			}
//			printf("\nline:%d\n",line);
			row++;
			if(a==EOF)break;
		}
//		printf("line:%d",line);
		line=line/row;
//		printf("\n\nrow:%d   line:%d\n\n",row,line);
	
	}
	fclose(fp);
	fp=NULL;
}
