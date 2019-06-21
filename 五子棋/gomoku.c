#include<stdio.h>
#include"gomoku.h"
void drawmap()
{
	int i,j;
	map[0][0]=' ';
	for(i=1;i<=15;i++)
	{
		if(i<10)
		{
			map[0][i]=map[i][0]='0'+i;
		}
		else
		{
			map[0][i]=map[i][0]='A'+i-10;
		}
	}
	for(i=1;i<=15;i++)
	{
		for(j=1;j<=15;j++)
		{
			map[i][j]='+';
		}
	}
	return;
}

void showmap()
{
	int i,j;
	for(i=0;i<=15;i++)
	{
		for(j=0;j<=15;j++)
		{
			printf("%c ",map[i][j]);
		}
		printf("\n");
	}
	return;
}

int judge(int x,int y)
{
	int m,n,l,r;
	m=dfs(x,y,0,-1)+dfs(x,y,0,1)+1;
	n=dfs(x,y,-1,0)+dfs(x,y,1,0)+1;
	l=dfs(x,y,-1,-1)+dfs(x,y,1,1)+1;
	r=dfs(x,y,-1,1)+dfs(x,y,1,-1)+1;
	if(m>=5||n>=5||l>=5||r>=5)return 1;
	else return 0;
}


int dfs(int x,int y,int dx,int dy)
{
	int count=0,i;
	while(x+dx>=1&&x+dx<=15&&y+dy>=1&&y+dy<=15)
	{
		if(map[x+dx][y+dy]==map[x][y])
		{
			count++;
			x=x+dx;y=y+dy;
		}
		else
		{
			if(dx>0||dy>0)
			{
				for(i=7;i<=11;i++)
				{
					if(x+dx>=1&&x+dx<=15&&y+dy>=1&&y+dy<=15)
					{
						chess[i]=map[x+dx][y+dy];
					}
					x=x+dx;y=y+dy;
				}
			}
			if(dx<0||dy<0)
			{
				for(i=5;i>=1;i--)
				{
					if(x+dx>=1&&x+dx<=15&&y+dy>=1&&y+dy<=15)
					{
						chess[i]=map[x+dx][y+dy];
					}
					x=x+dx;y=y+dy;
				}
			}
			break;
		}
	}
	return count;
}

int score(int m,int n,int l,int r)
{
	//十五种分数；
	int level[20]={0,100000,10000,5000,1000,500,400,100,90,50,10,9,5,2,1,0};
	
	if(m==11||n==11||l==11||r==11)
        return level[1];
	if(m==10||n==10||l==10||r==10)
		return level[2];
	if((m==9&&n==9)||(m==9&&l==9)||(m==9&&r==9)||(n==9&&l==9)||(n==9&&r==9)||(l==9&&r==9))
		return level[2];
	if((m==9&&n==7)||(m==9&&l==7)||(m==9&&r==7)||(n==9&&l==7)||(n==9&&r==7)||(l==9&&r==7)||
	   (m==7&&n==9)||(m==7&&l==9)||(m==7&&r==9)||(n==7&&l==9)||(n==7&&r==9)||(l==7&&r==9))
	    return level[2];
	if((m==7&&n==7)||(m==7&&l==7)||(m==7&&r==7)||(n==7&&l==7)||(n==7&&r==7)||(l==7&&r==7))
		return level[3];
	if((m==5&&n==7)||(m==5&&l==7)||(m==5&&r==7)||(n==5&&l==7)||(n==5&&r==7)||(l==5&&r==7)||
	   (m==7&&n==5)||(m==7&&l==5)||(m==7&&r==5)||(n==7&&l==5)||(n==7&&r==5)||(l==7&&r==5))
	    return level[4];
	if(m==9||n==9||l==9||r==9)
        return level[5];
	if(m==8||n==8||l==8||r==8)
        return level[6];
	if(m==7||n==7||l==7||r==7)
        return level[7];
	if(m==6||n==6||l==6||r==6)
        return level[8];
	if((m==4&&n==4)||(m==4&&l==4)||(m==4&&r==4)||(n==4&&l==4)||(n==4&&r==4)||(l==4&&r==4))
		return level[9];
	if(m==4||n==4||l==4||r==4)
        return level[10];
	if(m==3||n==3||l==3||r==3)
        return level[11];
	if(m==5||n==5||l==5||r==5)
        return level[12];
	if(m==2||n==2||l==2||r==2)
        return level[13];
	return level[14];
}


int score_x_y(int x,int y)
{
	int i,count_m,count_n,count_l,count_r,m,n,l,r;
	int finalscore;

	for(i=1;i<=11;i++)chess[i]='!';
	count_m=dfs(x,y,0,-1)+dfs(x,y,0,1)+1;
	chess[6]=map[x][y];
	m=chesstype(count_m);
	
	for(i=1;i<=11;i++)chess[i]='!';
	count_n=dfs(x,y,-1,0)+dfs(x,y,1,0)+1;
	chess[6]=map[x][y];
	n=chesstype(count_n);
	
	for(i=1;i<=11;i++)chess[i]='!';
	count_l=dfs(x,y,-1,-1)+dfs(x,y,1,1)+1;
	chess[6]=map[x][y];
	l=chesstype(count_l);
	
	for(i=1;i<=11;i++)chess[i]='!';
	count_r=dfs(x,y,-1,1)+dfs(x,y,1,-1)+1;
	chess[6]=map[x][y];
	r=chesstype(count_r);
	
	finalscore=score(m,n,l,r);
	
	return finalscore;
}


int chesstype(int count)
{
	//十一种类型：WIN5,LIVE4,DIE4,LOWDIE4,LIVE3,LOWLIVE3,DIE3,LIVE2,LOWLIVE2,DIE2，NOTHEREAT
	char NOTHINGFLAG='+';
	char mycolor=chess[6],hiscolor='0'+'&'-chess[6];
	char colorleft=chess[5],colorright=chess[7];
	int left=5,right=7;
	
	int WIN5=11,LIVE4=10,DIE4=9,LOWDIE4=8,LIVE3=7;
	int LOWLIVE3=6,DIE3=5,LIVE2=4,LOWLIVE2=3,DIE2=2,NOTHREAT=1;
	
	if (count>=5)
	{
		return WIN5;
	}
    if (count==4)
    {
        if(colorleft == NOTHINGFLAG && colorright == NOTHINGFLAG)//两边断开位置均空
            return LIVE4;
        else if (colorleft == hiscolor && colorright == hiscolor)//两边断开位置均非空
            return NOTHREAT;
        else if (colorleft == NOTHINGFLAG || colorright == NOTHINGFLAG)//两边断开位置只有一个空
            return DIE4;
    }
    if(count == 3)
	{
        char colorleft1 = chess[left - 1];
        char colorright1 = chess[right + 1];
        if (colorleft == NOTHINGFLAG && colorright == NOTHINGFLAG)//两边断开位置均空
        {
            if (colorleft1 == hiscolor && colorright1 == hiscolor)
                return DIE3;
            else if (colorleft1 == mycolor || colorright1 == mycolor)
                return LOWDIE4;
            else if (colorleft1 == NOTHINGFLAG || colorright1 == NOTHINGFLAG)
                return LIVE3;
        }
        else if (colorleft == hiscolor && colorright == hiscolor)//两边断开位置均非空
        {
            return NOTHREAT;
        }
        else if (colorleft == NOTHINGFLAG || colorright == NOTHINGFLAG)//两边断开位置只有一个空
        {
            if (colorleft == hiscolor)
			{
                if (colorright1 == hiscolor)
                    return NOTHREAT;
                if (colorright1 == NOTHINGFLAG)
                    return DIE3;
                if (colorright1 == mycolor)
                    return LOWDIE4;
            }
            if (colorright == hiscolor)
		    {
                if (colorleft1 == hiscolor)
                    return NOTHREAT;
                if (colorleft1 == NOTHINGFLAG)
                    return DIE3;
                if (colorleft1 == mycolor)
                    return LOWDIE4;
            }
        }
    }

    if (count == 2)
	{
        int colorleft1 = chess[left - 1];
        int colorright1 = chess[right + 1];
        int colorleft2 = chess[left - 2];
        int colorright2 = chess[right + 2];
        if (colorleft == NOTHINGFLAG && colorright == NOTHINGFLAG)//两边断开位置均空
        {
            if ((colorright1 == NOTHINGFLAG && colorright2 == mycolor) ||
                (colorleft1 == NOTHINGFLAG && colorleft2 == mycolor))
                return DIE3;
            else if (colorleft1 == NOTHINGFLAG && colorright1 == NOTHINGFLAG)
                return LIVE2;

            if ((colorright1 == mycolor && colorright2 == hiscolor) ||
                (colorleft1 == mycolor && colorleft2 == hiscolor))
                return DIE3;

            if ((colorright1 == mycolor && colorright2 == mycolor) ||
                (colorleft1 == mycolor && colorleft2 == mycolor))
                return LOWDIE4;

            if ((colorright1 == mycolor && colorright2 == NOTHINGFLAG) ||
                (colorleft1 == mycolor && colorleft2 == NOTHINGFLAG))
                return LOWLIVE3;
        }
        else if (colorleft == hiscolor && colorright == hiscolor)//两边断开位置均非空
        {
            return NOTHREAT;
        }
        else if (colorleft == NOTHINGFLAG || colorright == NOTHINGFLAG)//两边断开位置只有一个空
        {
            if (colorleft == hiscolor)
			{
                if (colorright1 == hiscolor || colorright2 == hiscolor) {
                    return NOTHREAT;
                }
                else if (colorright1 == NOTHINGFLAG && colorright2 == NOTHINGFLAG) {
                    return DIE2;
                }
                else if (colorright1 == mycolor && colorright2 == mycolor) {
                    return LOWDIE4;
                }
                else if (colorright1 == mycolor || colorright2 == mycolor) {
                    return DIE3;
                }
            }
            if (colorright == hiscolor)
			{
                if (colorleft1 == hiscolor || colorleft2 == hiscolor) {
                    return NOTHREAT;
                }
                else if (colorleft1 == NOTHINGFLAG && colorleft2 == NOTHINGFLAG) {
                    return DIE2;
                }
                else if (colorleft1 == mycolor && colorleft2 == mycolor) {
                    return LOWDIE4;
                }
                else if (colorleft1 == mycolor || colorleft2 == mycolor) {
                    return DIE3;
                }
            }
        }
    }

    if (count == 1)
	{
        int colorleft1 = chess[left - 1];
        int colorright1 = chess[right + 1];
        int colorleft2 = chess[left - 2];
        int colorright2 = chess[right + 2];
        int colorleft3 = chess[left - 3];
        int colorright3 = chess[right + 3];
        
        if (colorleft == NOTHINGFLAG && colorleft1 == mycolor &&
            colorleft2 == mycolor && colorleft3 == mycolor)
            return LOWDIE4;
        if (colorright == NOTHINGFLAG && colorright1 == mycolor &&
            colorright2 == mycolor && colorright3 == mycolor)
            return LOWDIE4;

        if (colorleft == NOTHINGFLAG && colorleft1 == mycolor &&
            colorleft2 == mycolor && colorleft3 == NOTHINGFLAG && colorright == NOTHINGFLAG)
            return LOWLIVE3;
        if (colorright == NOTHINGFLAG && colorright1 == mycolor &&
            colorright2 == mycolor && colorright3 == NOTHINGFLAG && colorleft == NOTHINGFLAG)
            return LOWLIVE3;

        if (colorleft == NOTHINGFLAG && colorleft1 == mycolor &&
            colorleft2 == mycolor && colorleft3 == hiscolor && colorright == NOTHINGFLAG)
            return DIE3;
        if (colorright == NOTHINGFLAG && colorright1 == mycolor &&
            colorright2 == mycolor && colorright3 == hiscolor && colorleft == NOTHINGFLAG)
            return DIE3;

        if (colorleft == NOTHINGFLAG && colorleft1 == NOTHINGFLAG &&
            colorleft2 == mycolor && colorleft3 == mycolor)
            return DIE3;
        if (colorright == NOTHINGFLAG && colorright1 == NOTHINGFLAG &&
            colorright2 == mycolor && colorright3 == mycolor)
            return DIE3;

        if (colorleft == NOTHINGFLAG && colorleft1 == mycolor &&
            colorleft2 == NOTHINGFLAG && colorleft3 == mycolor)
            return DIE3;
        if (colorright == NOTHINGFLAG && colorright1 == mycolor &&
            colorright2 == NOTHINGFLAG && colorright3 == mycolor)
            return DIE3;

        if (colorleft == NOTHINGFLAG && colorleft1 == mycolor &&
            colorleft2 == NOTHINGFLAG && colorleft3 == NOTHINGFLAG && colorright == NOTHINGFLAG)
            return LOWLIVE2;
        if (colorright == NOTHINGFLAG && colorright1 == mycolor &&
            colorright2 == NOTHINGFLAG && colorright3 == NOTHINGFLAG && colorleft == NOTHINGFLAG)
            return LOWLIVE2;

        if (colorleft == NOTHINGFLAG && colorleft1 == NOTHINGFLAG &&
            colorleft2 == mycolor && colorleft3 == NOTHINGFLAG && colorright == NOTHINGFLAG)
            return LOWLIVE2;
        if (colorright == NOTHINGFLAG && colorright1 == NOTHINGFLAG &&
            colorright2 == mycolor && colorright3 == NOTHINGFLAG && colorleft == NOTHINGFLAG)
            return LOWLIVE2;

    }
    return NOTHREAT;//不满足上述局面均返回NOTHREAT
}



void computer(int *x,int *y)
{
	int i,j,scoremax1=0,scoremax2=0,nowscore=0,maxx1,maxy1,maxx2,maxy2;
	for(i=1;i<=15;i++)
	for(j=1;j<=15;j++)
	{
		if(map[i][j]=='+')
		{
			map[i][j]='0';
			nowscore=score_x_y(i,j);
			if(nowscore>scoremax1)
			{
				scoremax1=nowscore;
				maxx1=i;
				maxy1=j;
			}
			map[i][j]='&';
			nowscore=score_x_y(i,j);
			if(nowscore>scoremax2)
			{
				scoremax2=nowscore;
				maxx2=i;
				maxy2=j;
			}
			map[i][j]='+';
		}
	}
	*x=scoremax1>=scoremax2?maxx1:maxx2;*y=scoremax1>=scoremax2?maxy1:maxy2;
	return;
}





















