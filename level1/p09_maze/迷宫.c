#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char mazemap[50][50];
void show();
int x=11,y=0;
int main()
{
	FILE *fin;
	fin = fopen("/tmp/maze.txt","r");
	int i,j;
	for(i=0;i<21;i++)
	{
		fgets(mazemap[i],25,fin);
	}
	show(x,y);
	char c;
	while((c=getch())!=-1)
	{
	    if(c=='a')
	    {
	    	if(y>0&&mazemap[x][y-1]!='#')
				{
					y--;
					show(x,y);
				}
		}
		else if(c=='s')
		{
			if(x<20&&mazemap[x+1][y]!='#')
				{
					x++;
					show(x,y);
				}
		}
		else if(c=='d')
		{
			if(y<20&&mazemap[x][y+1]!='#')
				{
					y++;
					show(x,y);
				}
		}
		else if(c=='w')
		{
			if(x>0&&mazemap[x-1][y]!='#')
				{
					x--;
					show(x,y);
				}
		}
		else if(c=='g')
		{
			show(x,y);
			printf("лл���룡");
			break;
		}
		else
		{
			printf("��Ч������");
		}
		if(x==13&&y==20)
		{
			printf("ף�أ���ɹ��ˣ�");
			break;
		}
	}
	

    fclose(fin);
	return 0;
}
void show(int x,int y)
{
	system("cls");
	printf("a:�� s:�� w:�� d:�� g:����\n");
	int i,j;
	for(i=0;i<21;i++)
	{
		for(j=0;j<21;j++)
		{
		    if(i==x&&j==y)
		    {
		    	printf("$");
		    	continue;
			}
			printf("%c",mazemap[i][j]);
	    }
		printf("\n");
    }
    return;
}














