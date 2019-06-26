//在网上找了光标定位和隐藏光标的方法
//想法如下：
//首先隐藏光标
//在光标位置处输出一个小圆点
//每移动一次，覆盖上一个光标位置处的小圆点
//在新的光标位置处输出一个小圆点
//当然，我们是看不见光标的

#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include "maze.h"

void locate(int x, int y);
void hide();

int start(char mymap[LINE][LINE]){
        COORD record;   //用于记录光标上一次出现的位置
        POINTER last;   //用于记录上一步的坐标

        //隐藏光标
        hide();

        //初始化光标位置为入口
        locate(1, 0);
        printf("●");    //显示玩家当前位置
        hide();
        record.X = 1; record.Y = 0;
        last.x = 1; last.y = 0;

        //当输入为w，s，a，d时分别是向上，下，左，右移动
        //输入q时放弃
        char ch;
        while((ch = getch()) != 'q'){
                //已经走到终点
                if(last.x == LINE-2 && last.y == LINE-1){
                        locate(LINE+6, 0);
                        return 1;
                }
                //根据输入来移动
                switch(ch){
                        case 'w':if(mymap[last.x-1][last.y] == 0 || last.x-1 < 0){break;}//碰到墙
                                 locate(record.X, record.Y);
                                 printf("  ");
                                 --record.X;
                                 --last.x;
                                 locate(record.X, record.Y);
                                 printf("●");    //显示玩家当前位置
                                 hide();
                                 break;
                        case 's':if(mymap[last.x+1][last.y] == 0 || last.x+1 >= LINE){break;}//碰到墙
                                 locate(record.X, record.Y);
                                 printf("  ");
                                 ++record.X;
                                 ++last.x;
                                 locate(record.X, record.Y);
                                 printf("●");    //显示玩家当前位置
                                 hide();
                                 break;
                        case 'a':if(mymap[last.x][last.y-1] == 0 || last.y-1 < 0){break;}//碰到墙
                                 locate(record.X, record.Y);
                                 printf("  ");
                                 record.Y = record.Y-2;
                                 --last.y;
                                 locate(record.X, record.Y);
                                 printf("●");    //显示玩家当前位置
                                 hide();
                                 break;
                        case 'd':if(mymap[last.x][last.y+1] == 0 || last.y+1 >= LINE){break;}//碰到墙
                                 locate(record.X, record.Y);
                                 printf("  ");
                                 record.Y = record.Y+2;
                                 ++last.y;
                                 locate(record.X, record.Y);
                                 printf("●");    //显示玩家当前位置
                                 hide();
                                 break;
                        default:break;
                }
        }
        //程序运行到这一步说明玩家放弃走迷宫了
        //输出0表示游戏失败
        locate(LINE+6, 0);
        return 0;
}


