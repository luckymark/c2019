#include"gomoku.h"
#include"ai.h"
int main()
{
	int win1,win2;
	int changeside;
	int *c;
	char map[15][15][4];
	int a[15][15];             //0:空位置 1：黑棋（人） 2：白棋（电脑） 3:光标  
	int x,y;
	int *m;
	int *n;
	int i,j;
	win1=0;
	win2=0;
	c=&changeside;
	x=7;
	y=7;
	m=&x;
	n=&y;
	for(i=0;i<15;i++)
	{
		for(j=0;j<15;j++)
		{
			sprintf(map[i][j],"┼ ");
		}
	} 
	for(i=0;i<15;i++)
	{
		for(j=0;j<15;j++)
		{
			a[i][j]=0;     //0代表是空位置 十字 
		}
	} 
	sprintf(map[x][y],"⊕");
	a[x][y]=3;            //3代表该位置是光标 
	for(i=0;i<15;i++)
	{
		for(j=0;j<15;j++)
		{
			printf("%s",map[i][j]);
		}
		printf("\n");
	}
	while(win1==0&&win2==0)
	{
		changeside=0;
		move(m,n,map,a,c);
		win1=win(m,n,a,5,1);
		if(changeside==1&&win1==0)
		{
		    ai(m,n,map,a);
		    win2=win(m,n,a,5,2);
		}
		system("cls");
        newmap(map);
        if(win1!=0)
        	printf("Congratulations! You won the game!");
        if(win2!=0) 
        	printf("What a pity! You lost the game!");
	}
	return 0;
}
