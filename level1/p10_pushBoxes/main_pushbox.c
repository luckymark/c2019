#include"pushbox.h"
#include<stdio.h>
#include<conio.h>
#include<windows.h>
int main(int argc, char *argv[]) 
{
	while(1)
	{
		int judge;
		printmap();
		game();
		gotoxy(0,M+9);
		printf("��0��ʼ��һ����Ϸ������������˳�\n");
		judge=getch();
		if(judge!='0') break;
		system("cls");
	}
	return 0;
}
