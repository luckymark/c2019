#include "head.h"
int main() {
	FILE *fp;
	char* p;
	fp=fopen("warehouse.txt","rt+");
	if(fp==NULL){
		puts("fail to open the fail");
	}
	else{
		p=warehouse(fp);
	}
	fclose(fp);
	fp=fopen("warehouse.txt","w");
	fwrite(p,strlen(p),1,fp);
	fclose(fp);
	return 0;
}
