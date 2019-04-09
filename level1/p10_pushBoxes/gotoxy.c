#include"pushbox.h"
#include<stdio.h>
#include<conio.h>
#include<windows.h>
void gotoxy(int x,int y) //移动光标到控制台第x行，第y列 
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}
