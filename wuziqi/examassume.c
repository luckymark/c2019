#include"examasume.h"
#include"calculate.h"
int leftrightexamassume(int position1_x,int position1_y)//四个方向的估值
{
    int i,j;
	for (i = 0; i < 9; i++)
	{
		board1[i] = 9;
	}
    for(i=1; i<5; i++)
    {
        if((position1_y-i)>-1)
            board1[4-i]=board[position1_x][position1_y-i];
        if((position1_y+i)<length)
            board1[4+i]=board[position1_x][position1_y+i];
    }
    board1[4]=2;
	j = calculate(board1);
    return j;
}
int updownexamassume(int position1_x,int position1_y)
{
    int i,j;
	for (i = 0; i < 9; i++)
	{
		board1[i] = 9;
	}
    for(i=1; i<5; i++)
    {
        if((position1_x-i)>-1)
            board1[4-i]=board[position1_x-i][position1_y];
        if((position1_x+i)<width)
            board1[4+i]=board[position1_x+i][position1_y];
    }
    board1[4]=2;
	j = calculate(board1);
	return j;

}
int leftuprightdownexamassume(int position1_x,int position1_y)
{
    int i,j;
	for (i = 0; i < 9; i++)
	{
		board1[i] = 9;
	}
    for(i=1; i<5; i++)
    {
        if((position1_x-i)>-1&&(position1_y-i)>-1)
            board1[4-i]=board[position1_x-i][position1_y-i];
        if((position1_x+i)<width&&(position1_y+i)<length)
            board1[4+i]=board[position1_x+i][position1_y+i];
    }
    board1[4]=2;
	j = calculate(board1);
	return j;
}
int leftdownrightupexamassume(int position1_x,int position1_y)
{
    int i,j;
	for (i = 0; i < 9; i++)
	{
		board1[i] = 9;
	}
    for(i=1; i<5; i++)
    {
        if((position1_x+i)<width&&(position1_y-i)>-1)
            board1[4-i]=board[position1_x+i][position1_y-i];
        if((position1_x-i)>-1&&(position1_y+i)<length)
            board1[4+i]=board[position1_x-i][position1_y+i];
    }
    board1[4]=2;
	j = calculate(board1);
	return j;

}
int leftrightexamassumehuman(int position1_x,int position1_y)
{
    int i;
	for (i = 0; i < 9; i++)
	{
		board1[i] = 9;
	}
    for(i=1; i<5; i++)
    {
        if((position1_y-i)>-1)
            board1[4-i]=board[position1_x][position1_y-i];
        if((position1_y+i)<length)
            board1[4+i]=board[position1_x][position1_y+i];
    }
    board1[4]=4;
    return anticalculate(board1);
}
int updownexamassumehuman(int position1_x,int position1_y)
{
    int i;
	for (i = 0; i < 9; i++)
	{
		board1[i] = 9;
	}
    for(i=1; i<5; i++)
    {
        if((position1_x-i)>-1)
            board1[4-i]=board[position1_x-i][position1_y];
        if((position1_x+i)<width)
            board1[4+i]=board[position1_x+i][position1_y];
    }
    board1[4]=4;
    return anticalculate(board1);

}
int leftuprightdownexamassumehuman(int position1_x,int position1_y)
{
    int i;
	for (i = 0; i < 9; i++)
	{
		board1[i] = 9;
	}
    for(i=1; i<5; i++)
    {
        if((position1_x-i)>-1&&(position1_y-i)>-1)
            board1[4-i]=board[position1_x-i][position1_y-i];
        if((position1_x+i)<width&&(position1_y+i)<length)
            board1[4+i]=board[position1_x+i][position1_y+i];
    }
    board1[4]=4;
    return anticalculate(board1);
}
int leftdownrightupexamassumehuman(int position1_x,int position1_y)
{
    int i;
	for (i = 0; i < 9; i++)
	{
		board1[i] = 9;
	}
    for(i=1; i<5; i++)
    {
        if((position1_x+i)<width&&(position1_y-i)>-1)
            board1[4-i]=board[position1_x+i][position1_y-i];
        if((position1_x-i)>-1&&(position1_y+i)<length)
            board1[4+i]=board[position1_x-i][position1_y+i];
    }
    board1[4]=4;
    return anticalculate(board1);

}
