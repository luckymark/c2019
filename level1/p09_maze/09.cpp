#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h> 
#define Height 25 //迷宫的高度
#define Width 25 //迷宫的宽度
#define Wall 1
#define Road 0
#define Start 2
#define End 3
#define Esc 5
#define Up 1
#define Down 2
#define Left 3
#define Right 4
int map[Height+2][Width+2];
void gotoxy(int x,int y) //玩家坐标
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}
void hidden()//隐藏光标
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut,&cci);
    cci.bVisible=0;//赋1为显示，赋0为隐藏
    SetConsoleCursorInfo(hOut,&cci);
}
void create(int x,int y) //随机生成迷宫
{
    int c[4][2]={0,1,1,0,0,-1,-1,0}; //四个方向
    int i,j,t;//将方向打乱
    for(i=0;i<4;i++)
    {
        j=rand()%4;
        t=c[i][0];c[i][0]=c[j][0];c[j][0]=t;
        t=c[i][1];c[i][1]=c[j][1];c[j][1]=t;
    }
    map[x][y]=Road;
    for(i=0;i<4;i++)
    if(map[x+2*c[i][0]][y+2*c[i][1]]==Wall)
    {
        map[x+c[i][0]][y+c[i][1]]=Road;
        create(x+2*c[i][0],y+2*c[i][1]);
    }
}
int get_key() //接收按键
{
    char c;
    while(c=getch())
    {
        if(c==27) return Esc; //Esc
        if(c!=-32)continue;
        c=getch();
        if(c==72) return Up; //上
        if(c==80) return Down; //下
        if(c==75) return Left; //左
        if(c==77) return Right; //右
    }
    return 0;
}
void paint(int x,int y) //画迷宫
{
    gotoxy(2*y-2,x-1);
    switch(map[x][y])
    {
        case Start:
        printf("入");break; //
        case End:
        printf("出");break; //
        case Wall:
        printf("▇");break; //
        case Road:
        printf(" ");break; //
    }
}
void game()
{
    int x=2,y=1; //玩家当前位置，刚开始在入口处
    int c; //用来接收按键
    while(1)
    {
        gotoxy(2*y-2,x-1);
        printf("●"); //画出玩家当前位置
        if(map[x][y]==End) //判断是否到达出口
        {
            gotoxy(30,24);
            printf("到达终点，按任意键结束");
            getch();
            break;
        }
        c=get_key();
        if(c==Esc)
        {
            gotoxy(0,24);
            break;
        }
        switch(c)
        {
            case Up: //向上走
                if(map[x-1][y]!=Wall)
                {
                    paint(x,y);
                    x--;
                }
            break;
            case Down: //向下走
            	if(map[x+1][y]!=Wall)
            {
                paint(x,y);
                x++;
            }
            break;
            case Left: //向左走
            	if(map[x][y-1]!=Wall)
            {
                paint(x,y);
                y--;
            }
            break;
            case Right: //向右走
            	if(map[x][y+1]!=Wall)
            		{
                		paint(x,y);
                		y++;
            		}
            break;
        }
    }
}
int main()
{
	system("title your name");
    int i,j;
    srand((unsigned)time(NULL)); //初始化随机种子
    hidden(); //隐藏光标
    for(i=0;i<=Height+1;i++)
    for(j=0;j<=Width+1;j++)
    if(i==0||i==Height+1||j==0||j==Width+1) //初始化迷宫
    map[i][j]=Road;
    else map[i][j]=Wall;
	create(2*(rand()%(Height/2)+1),2*(rand()%(Width/2)+1)); //从随机一个点开始生成迷宫
    for(i=0;i<=Height+1;i++) //边界处理 
    {
        map[i][0]=Wall;
        map[i][Width+1]=Wall;
    }
 	for(j=0;j<=Width+1;j++) //边界处理
    {
        map[0][j]=Wall;
        map[Height+1][j]=Wall;
    }
    map[2][1]=Start; //给定入口
    map[Height-1][Width]=End; //给定出口
    for(i=1;i<=Height;i++)
    for(j=1;j<=Width;j++) //画出迷宫
    paint(i,j);
    game(); //开始游戏
    getch();
    return 0;
}

