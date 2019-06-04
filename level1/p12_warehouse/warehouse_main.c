#include"warehouse.h"
struct part depository[MAX];
int main(int argc, char *argv[]) {
	int code;
	for(;;){
		Read();
		printf("Enter opeation code \n1.output status\n2.insert\n3.out\n4.escape\n");
		scanf("%d",&code);
		switch(code){
			case 1:output();break;
			case 2:insert();break;
			case 3:out();break;
			case 4:return 0;
			default:printf("illeagal code");
		}
		Write();
	}
}
