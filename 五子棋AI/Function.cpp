#include"gomoku.h"
void newmap(char map[15][15][4])
{
	int i,j;
	for(i=0;i<15;i++)
	{
		for(j=0;j<15;j++)
		{
			printf("%s",map[i][j]);
		}
		printf("\n");
	}
}
void move(int *m,int *n,char map[15][15][4],int a[][15],int *c)
{
	int ch;
	if((ch=getch())!=0x1B)
	{
		switch(ch)
		{
			case 0xE0:
				switch(ch=getch())
				{
					case 72: {
						if(*m>0)
						    *m=*m-1; change_1(m,n,map,a);
						break;
					}
					case 80: {
						if(*m<14)
						    *m=*m+1; change_2(m,n,map,a);
						break;
					}
					case 75: {
						if(*n>0)
						    *n=*n-1; change_3(m,n,map,a);
						break;
					}
					case 77: {
						if(*n<15)
						    *n=*n+1; change_4(m,n,map,a);
						break;
					}
					default:
						break;
				}
			    break;
            case 32: confirm(m,n,map,a,c); break;
            	
				break;
			default:
				break;
		}
	}
}
void change_1(int *m,int *n,char map[15][15][4],int a[][15])
{
	if(a[*m][*n]==1||a[*m][*n]==2)
	{
		if(a[*m+1][*n]==1||a[*m+1][*n]==2)
		{
			;
		}
		else if(a[*m+1][*n]==3)
		{
			sprintf(map[*m+1][*n],"┼ ");
			a[*m+1][*n]=0;
		}
	}
	else if(a[*m][*n]==0)
	{
		sprintf(map[*m][*n],"⊕");
		a[*m][*n]=3;
		if(a[*m+1][*n]==1||a[*m+1][*n]==2)
		{
			;
		}
		else if(a[*m+1][*n]==3)
		{
			sprintf(map[*m+1][*n],"┼ ");
			a[*m+1][*n]=0;
		}
	}
}
void change_2(int *m,int *n,char map[15][15][4],int a[][15])
{
	if(a[*m][*n]==1||a[*m][*n]==2)
	{
		if(a[*m-1][*n]==1||a[*m-1][*n]==2)
		{
			;
		}
		else if(a[*m-1][*n]==3)
		{
			sprintf(map[*m-1][*n],"┼ ");
			a[*m-1][*n]=0;
		}
	}
	else if(a[*m][*n]==0)
	{
		sprintf(map[*m][*n],"⊕");
		a[*m][*n]=3;
		if(a[*m-1][*n]==1||a[*m-1][*n]==2)
		{
			;
		}
		else if(a[*m-1][*n]==3)
		{
			sprintf(map[*m-1][*n],"┼ ");
			a[*m-1][*n]=0;
		}
	}
}
void change_3(int *m,int *n,char map[15][15][4],int a[][15])
{
	if(a[*m][*n]==1||a[*m][*n]==2)
	{
		if(a[*m][*n+1]==1||a[*m][*n+1]==2)
		{
			;
		}
		else if(a[*m][*n+1]==3)
		{
			sprintf(map[*m][*n+1],"┼ ");
			a[*m][*n+1]=0;
		}
	}
	else if(a[*m][*n]==0)
	{
		sprintf(map[*m][*n],"⊕");
		a[*m][*n]=3;
		if(a[*m][*n+1]==1||a[*m][*n+1]==2)
		{
			;
		}
		else if(a[*m][*n+1]==3)
		{
			sprintf(map[*m][*n+1],"┼ ");
			a[*m][*n+1]=0;
		}
	}
}
void change_4(int *m,int *n,char map[15][15][4],int a[][15])
{
	if(a[*m][*n]==1||a[*m][*n]==2)
	{
		if(a[*m][*n-1]==1||a[*m][*n-1]==2)
		{
			;
		}
		else if(a[*m][*n-1]==3)
		{
			sprintf(map[*m][*n-1],"┼ ");
			a[*m][*n-1]=0;
		}
	}
	else if(a[*m][*n]==0)
	{
		sprintf(map[*m][*n],"⊕");
		a[*m][*n]=3;
		if(a[*m][*n-1]==1||a[*m][*n-1]==2)
		{
			;
		}
		else if(a[*m][*n-1]==3)
		{
			sprintf(map[*m][*n-1],"┼ ");
			a[*m][*n-1]=0;
		}
	}
}
void confirm(int *m,int *n,char map[15][15][4],int a[][15],int *c)
{
	if(a[*m][*n]==3)
	{
	    sprintf(map[*m][*n],"○");      //人 黑棋 
	    a[*m][*n]=1;
	    *c=1;
	}
}
int win(int *m,int *n,int a[][15],int count,int side)  //人 
{
	int i,j,p;
	for(j=0;j<count;j++)
	{
		p=0;
		for(i=0;i<count;i++)
		{
			if(*m-j<0)
			    break;
		    if(a[*m-j+i][*n]==side&&*m-j+i<=14)
		        p++; 
		}
		if(p==count)
		    return 1;               //竖 
	}
	for(j=0;j<count;j++)
	{
		p=0;
		for(i=0;i<count;i++)
		{
			if(*n-j<0)
			    break;
		    if(a[*m][*n-j+i]==side&&*n-j+i<=14)
		        p++;
		}
		if(p==count)
		    return 2;             //横 
	}
	for(j=0;j<count;j++)
	{
		p=0;
		for(i=0;i<count;i++)
		{
			if(*m-j<0||*n-j<0)
			    break;
		    if(a[*m-j+i][*n-j+i]==side&&*m-j+i<=14&&*n-j+i<=14)
		        p++; 
		}
		if(p==count)
		    return 3;             //左上到右下斜 
	}
	for(j=0;j<count;j++)
	{
		p=0;
		for(i=0;i<count;i++)
		{
		    if(*m-j<0||*n+j>14)
			    break;
		    if(a[*m-j+i][*n+j-i]==side&&*m-j+i<=14&&*n+j-i>=0)
		        p++; 
		}
		if(p==count)
		    return 4;              //左下到右上斜 
	}
	return 0;
}
