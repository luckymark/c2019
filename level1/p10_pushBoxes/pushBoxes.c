#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>

#define width 15
#define hidth 7

void initial()//配置curses运行参数
{
   initscr();
   cbreak();
   nonl();
   noecho();
   intrflush(stdscr ,FALSE);
   keypad(stdscr ,TRUE);
   refresh();
}

int main()
{
   int map[ width ][ hidth ];//读入的地图存在这里
   int vision[ width ][ hidth ];//要显示的地图存在这里
   //将文件读入缓存
   FILE *fp = NULL;
   fp = fopen("/home/q/c2019/level1/test2.txt", "r+");
   //将缓存读入二维数组
   for(int j = 0; j < hidth ; j++)
   {
      for(int i = 0; i < width ; i++)
      {
         map[ i ][ j ] = fgetc((FILE*)fp);
         vision[ i ][ j ] = map[ i ][ j ];
      }
      
   }
   
   int now[ 2 ] = { 1 ,1 };//设定现在位置
   int next[ 2 ] = { 1, 1 };//设定要走的下一步的位置
   int ch;
   initial();//初始化curses
   for(int j = 0; j < hidth ; j++)
      {
         for(int i = 0; i < width ; i++)
         {
            mvaddch( j , i ,vision[ i ][ j ]);
         }
      }
   //while1轮寻属实弟弟，但是其他的方法比较复杂，我先学会再来重写这一块
   while( 1 )
   {
      ch = getch();
      move( 1,1 );
      switch ( ch )//curses提供的第二个便利之处就是读键盘输入方便
      {
         case KEY_UP:
            --next[ 2 ];
            break;
         case KEY_DOWN:
            ++next[ 2 ];
            break;
         case KEY_LEFT:
            --next[ 1 ];
            break;
         case KEY_RIGHT:
            ++next[ 1 ];
            break;
         case 27:
            endwin();
            exit( 1 );
         default:
            break;
      }
      mvaddch( now[ 2 ] , now[ 1 ] ,' ');
      //通过测试next有没有墙来确定能不能移动
      if (map[ next[ 1 ] ][ next[ 2 ] ] != '#') 
      {
         now[ 1 ]= next[ 1 ];
         now[ 2 ]= next[ 2 ];
      }
      else
      {
         next[ 1 ] = now[ 1 ];
         next[ 2 ] = now[ 2 ];
      }
      //移动‘你’
      mvaddch( now[ 2 ] ,now[ 1 ] ,'Y');
      //判断是否到达了出口
      if (map[ next[ 1 ] ][ next[ 2 ] ] == 'O')
      {
         printw("Congraduations! Press ESC to exit game.");
      }
   }
   return 0 ;
}