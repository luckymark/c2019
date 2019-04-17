#include<stdio.h>
int x,y,boxnumber,cnt,howmany;
int box[100][3],position[100][3];
char boxmap[25][25];
void loadfile();
void loadmap();
void showmap();
void where(int a,int b,int c,int d);
int main()
{
	int i;
	loadfile();
	loadmap();
	showmap();
	howmany=0;cnt=0;
	char c;
	while((c=getch())!=-1)
	{
		if(c=='a')
		{
			where(0,-1,0,-2);
			cnt++;
			showmap();
		}
		else if(c=='s')
		{
			where(1,0,2,0);
			cnt++;
			showmap();
		}
		else if(c=='d')
		{
			where(0,1,0,2);
			cnt++;
			showmap();
		}
		else if(c=='w')
		{
			where(-1,0,-2,0);
			cnt++;
			showmap();
		}
		else if(c=='g')
		{
			showmap();
			printf("谢谢参与！");
			break;
		}
		else if(c=='r')
		{
			loadfile();
			loadmap();
			showmap();
			howmany=0;cnt=0;
		}
		else
		{
			printf("无效操作！");
		}
		for(i=1;i<=boxnumber;i++)
		{
			if(boxmap[position[i][1]][position[i][2]]=='@')
			{
				howmany++;
				boxmap[position[i][1]][position[i][2]]='#';
				showmap();
			}
		}
		if(howmany==boxnumber)
		{
			printf("祝贺！你成功了!");
			FILE *fin;
			if(howmany==1)
			{
				fin = fopen("/tmp/pushboxone.txt","a+");
			}
			else
			{
				fin = fopen("/tmp/pushboxtwo.txt","a+");
			}
			fprintf(fin,"你此次挑战的分数为：%d\n",cnt);
			break;
		}

	}
	return;
}
void loadfile()
{
	FILE *fin;
	int choice;
	while(1)
	{
	    printf("请输入你要挑战的关卡序号(1-2)：");
	    scanf("%d",&choice);
		if(choice==1)
	    {
	        fin = fopen("/tmp/pushboxone.txt","r");
	        break;
        }
        else if(choice==2)
        {
    	    fin = fopen("/tmp/pushboxtwo.txt","r");
			break;
        }
	    else
	    {
		    printf("error!\n");
	    }
    }
	int i,j;
	for(i=0;i<21;i++)
	{
		fgets(boxmap[i],25,fin);
	}
	fscanf(fin,"%d %d",&x,&y);
	fscanf(fin,"%d",&boxnumber);
	for(i=1;i<=boxnumber;i++)
	{
		fscanf(fin,"%d %d",&box[i][1],&box[i][2]);
		fscanf(fin,"%d %d",&position[i][1],&position[i][2]);
	}
	return;
}
void loadmap()
{
	int i;
	for(i=1;i<=boxnumber;i++)
    {
    	boxmap[position[i][1]][position[i][2]]='$';
    	boxmap[box[i][1]][box[i][2]]='@';
	}
	boxmap[x][y]='i';
	return;
}
void showmap()
{
	system("cls");
	printf("a:左 s:下 w:上 d:右 g:放弃 r:重来\n");
	int i,j;
	for(i=0;i<21;i++)
	{
		for(j=0;j<21;j++)
		{
			printf("%c",boxmap[i][j]);
	    }
		printf("\n");
    }
    return;
}
void where(int a,int b,int c,int d)
{
	if(x+a>=0&&x+a<=20&&y+b>=0&&y+b<=20)
	{
		if(boxmap[x+a][y+b]!='#')
		{
			if(boxmap[x+a][y+b]==' ')
			{
				boxmap[x][y]=' ';
				boxmap[x+a][y+b]='i';
				x+=a;y+=b;
			}
			else if(boxmap[x+a][y+b]=='@')
			{
				if(x+c>=0&&x+c<=20&&y+d>=0&&y+d<=20)
				{
					if(boxmap[x+c][y+d]==' '||boxmap[x+c][y+d]=='$')
					{
						boxmap[x+c][y+d]='@';
						boxmap[x][y]=' ';
				        boxmap[x+a][y+b]='i';
						x+=a;y+=b;
					}
				}
			}
		}
	}
	return;
}
