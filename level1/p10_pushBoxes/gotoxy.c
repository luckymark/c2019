#include"pushbox.h"
#include<stdio.h>
#include<conio.h>
#include<windows.h>
void gotoxy(int x,int y) //�ƶ���굽����̨��x�У���y�� 
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}
