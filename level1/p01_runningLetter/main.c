#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX_LENGTH 70


int main(int argc, char *argv[]) {
	int sp = 0,line = 0,ls = 0;
	while(1){
		int i,c;
		for(c = 0;c<line;c++){
			printf("\n");
		}
		for(i = 0;i<sp;i++){
			printf(" ");
		}
		
		printf("abcdefghi");
		
		Sleep(50);
		system("cls");
		ls==0?sp++:sp--;
		if(sp>MAX_LENGTH || sp == -1){
			line++;
			ls = ls ==0?1:0;
		}
	}
	return 0;
}

