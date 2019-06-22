#include"userinput.h"
int input1()
{
    switch(ch)//¼üÅÌÊäÈë
    {
    case 'w':
        if(position_x>0)
            position_x--;
        break;
    case 's':
          if(position_x<width-1)
            position_x++;
        break;
    case 'a':
          if(position_y>0)
            position_y--;
        break;
    case 'd':
          if(position_y<length-1)
            position_y++;
        break;
    case ' ':
        if(board[position_x][position_y]==0)
        {
        first1=0;
        board[position_x][position_y]=4;
		userposition_x = position_x;
		userposition_y = position_y;
        }
        break;
    default:
        printf("error\n");
        break;
    }
    return 1;
}
