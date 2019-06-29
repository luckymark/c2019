#include<stdio.h>
#include<stdbool.h>
#include<windows.h>
#define P 148  //player-1
#define G 176  //goal-2
#define B 177  //box-3
#define BG 178  //box on goal-4
#define W 219  //wall-5
#define PG 232  //player on goal-6
/*todolist
1.read map;
2.print map&you;
3.move it:1)input;2)canyoumove?;
4.judge if you win;
5.score;*/ 
void gotoxy(int x,int y);
void print_map(void);
void print_block(int n);
void move(int level);
bool judge(int level);
int wasd(int * x,int * y,char way);
void load_map(int n);

int block[20][20];//0：空位 1：人物 2：目标位置 3：箱子 4：放在目标位置的箱子 5：墙 6：站在目标位置的人物 
int score=0;

int main(void)
{
	char jud;
	
	system("chcp 437");
	system("mode con cols=32 lines=23");
	system("cls");
	
	printf("Push Box\n");
	printf("Please choose a map\n");
	printf("1  2  3  4  5  6  7  q.quit\n");
	while((jud=getch())!='q')
	{
		system("cls");	
		score=0;	
		switch(jud)
		{
			case '1':
				load_map(0);
				print_map();
				move(0); 
				break;
			case '2':
				load_map(1);
				print_map();
				move(1);
				break;
			case '3':
				load_map(2);
				print_map();
				move(2);
				break;
			case '4':
				load_map(3);
				print_map();
				move(3);
				break;
			case '5':
				load_map(4);
				print_map();
				move(4);
				break;
			case '6':
				load_map(5);
				print_map();
				move(5);
				break;
			case '7':
				load_map(6);
				print_map();
				move(6);
				break;
			case 'q':
				return 0;
			default:
				;
		}
		system("cls");
		printf("Push Box\n");
		printf("Please choose a map\n");
		printf("1  2  3  4  5  6  7  q.quit\n");
	}
	
	return 0;
}
void move(int level)
{
	int i,j;
	char jud;
	
	if(level==0)
	{
		i=4;
		j=3;
	}
	else if(level==1)
	{
		i=1;
		j=1;
	}
	else if(level==2)
	{
		i=3;
		j=2;
	}
	else if(level==3)
	{
		i=2;
		j=1;
	}
	else if(level==4)
	{
		i=1;
		j=2;
	}
	else if(level==5)
	{
		i=1;
		j=8;
	}
	else if(level==6)
	{
		i=3;
		j=8;
	 } 
	while(judge(level))
	{
		jud=getch();
		if(!wasd(&i,&j,jud))
		{
			return;
		}
		gotoxy(21,0);
		printf("score:%4d",score);
	}
	system("cls");
	printf("You win!\n");
	printf("Your step is %4d.\n",score);
	system("pause");
	
}
int wasd(int * x,int * y,char way)
{
	int di,dj;
	
	switch(way)
	{
		case 'w':
			di=-1;
			dj=0;
			break;
		case 's':
			di=1;
			dj=0;
			break;
		case 'a':
			di=0;
			dj=-1;
			break;
		case 'd':
			di=0;
			dj=1;
			break;
		case 27:
			return 0;
		default:
			return;
	}
	if(block[*x+di][*y+dj]==0)
	{
		if(block[*x][*y]==6)
		{
			block[*x][*y]=2;
			block[*x+di][*y+dj]=1;
		}
		else if(block[*x][*y]==1)
		{
			block[*x][*y]=0;
			block[*x+di][*y+dj]=1;
		}
		
		gotoxy(*y,*x);
		print_block(block[*x][*y]);
		*x=*x+di;
		*y=*y+dj;
		gotoxy(*y,*x);
		print_block(block[*x][*y]);
		score++;
    }
    else if(block[*x+di][*y+dj]==2)
	{
		if(block[*x][*y]==6)
		{
			block[*x][*y]=2;
			block[*x+di][*y+dj]=6;
		}
		else if(block[*x][*y]==1)
		{
			block[*x][*y]=0;
			block[*x+di][*y+dj]=6;
		}

		gotoxy(*y,*x);
		print_block(block[*x][*y]);
		*x=*x+di;
		*y=*y+dj;
		gotoxy(*y,*x);
		print_block(block[*x][*y]);
		score++;
	}
    else if(block[*x+di][*y+dj]==3)
    {
		if(block[*x][*y]==6)
		{
			if(block[*x+2*di][*y+2*dj]==0)
			{
				block[*x+2*di][*y+2*dj]=3;
				block[*x+di][*y+dj]=1;
				block[*x][*y]=2;
				score++;
			}
		    else if(block[*x+2*di][*y+2*dj]==2)
			{
				block[*x+2*di][*y+2*dj]=4;
				block[*x+di][*y+dj]=1;
				block[*x][*y]=2;
				score++;
			}
			else
			{
				return;
			}
		}
		else
		{
			if(block[*x+2*di][*y+2*dj]==0)
			{
				block[*x+2*di][*y+2*dj]=3;
				block[*x+di][*y+dj]=1;
				block[*x][*y]=0;
				score++;
			}
			else if(block[*x+2*di][*y+2*dj]==2)
			{
				block[*x+2*di][*y+2*dj]=4;
				block[*x+di][*y+dj]=1;
				block[*x][*y]=0;
				score++;
			}
			else
			{
				return;
			}
		}
		gotoxy(*y,*x);
		print_block(block[*x][*y]);
		*x=*x+di;
		*y=*y+dj;
		gotoxy(*y,*x);
		print_block(block[*x][*y]);
		gotoxy(*y+dj,*x+di);
		print_block(block[*x+di][*y+dj]);
	}
	else if(block[*x+di][*y+dj]==4)
	{
		if(block[*x][*y]==6)
		{
			if(block[*x+2*di][*y+2*dj]==0)
			{
				block[*x+2*di][*y+2*dj]=3;
				block[*x+di][*y+dj]=6;
				block[*x][*y]=2;
				score++;
			}
			else if(block[*x+2*di][*y+2*dj]==2)
			{
				block[*x+2*di][*y+2*dj]=4;
				block[*x+di][*y+dj]=6;
				block[*x][*y]=2;
				score++;
			}
			else
			{
				return;
			}
		}
		else
		{
			if(block[*x+2*di][*y+2*dj]==0)
			{
				block[*x+2*di][*y+2*dj]=3;
				block[*x+di][*y+dj]=6;
				block[*x][*y]=0;
				score++;
			}
			else if(block[*x+2*di][*y+2*dj]==2)
			{
				block[*x+2*di][*y+2*dj]=4;
				block[*x+di][*y+dj]=6;
				block[*x][*y]=0;
				score++;
			}
			else
			{
				return;
			}
		}
		gotoxy(*y,*x);
		print_block(block[*x][*y]);
		*x=*x+di;
		*y=*y+dj;
		gotoxy(*y,*x);
		print_block(block[*x][*y]);
		gotoxy(*y+dj,*x+di);
		print_block(block[*x+di][*y+dj]);	
	}
	
	return 1;
}
//It's obviously tough to use C,if use C++ just use string +(Operator overloading),for C,we could use strcat
void load_map(int n)
{
	FILE *fp;
	int i,j;
	
	if(n==0)
	{
		fp=fopen("map1.txt","r");
	}
	else if(n==1)
	{
		fp=fopen("map2.txt","r");
	}
	else if(n==2)
	{
		fp=fopen("map3.txt","r");
	}
	else if(n==3)
	{
		fp=fopen("map4.txt","r");
	}
	else if(n==4)
	{
		fp=fopen("map5.txt","r");
	}	
	else if(n==5)
	{
		fp=fopen("map6.txt","r");
	}
	else if(n==6)
	{
		fp=fopen("map7.txt","r");
	}
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			fscanf(fp,"%d",&block[i][j]);
		}
	}
	fclose(fp);

}
void print_block(int n)
{
	if(n==0)
	{
		putchar(' ');
	}
	else if(n==1)
	{
		putchar(P);
	}
	else if(n==2)
	{
		putchar(G);
	}
	else if(n==3)
	{
		putchar(B);
	}
	else if(n==4)
	{
		putchar(BG);
	}
	else if(n==5)
	{
		putchar(W);
	}
	else if(n==6)
	{
		putchar(PG);
	} 

}
bool judge(int level)
{
	if(level==0)
	{
		if(block[3][1]==4&&block[1][4]==4&&
		   block[4][6]==4&&block[6][3]==4)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else if(level==1)
	{
		if(block[3][7]==4&&block[4][7]==4&&
		   block[5][7]==4)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	} 
	else if(level==2)
	{
		if(block[4][2]==4&&block[4][3]==4&&
		   block[5][2]==4&&block[5][3]==4)
		{
			return 0;
		}
		else
		{
			return 1;
		}
    }
    else if(level==3)
	{
		if(block[5][1]==4&&block[6][3]==4&&
		   block[6][1]==4&&block[6][2]==4&&
		   block[6][4]==4)
		{
			return 0;
		}
		else
		{
			return 1;
		}
    }
    else if(level==4)
	{
		if(block[4][1]==4&&block[5][1]==4&&
		   block[6][1]==4)
		{
			return 0;
		}
		else
		{
			return 1;
		}
    }
    else if(level==5)
	{
		if(block[6][1]==4&&block[6][2]==4&&
		   block[6][3]==4&&block[6][4]==4&&
		   block[6][5]==4)
		{
			return 0;
		}
		else
		{
			return 1;
		}
    }
    else if(level==6)
	{
		if(block[2][2]==4&&block[3][2]==4&&
		   block[4][2]==4&&block[3][1]==4&&
		   block[4][1]==4)
		{
			return 0;
		}
		else
		{
			return 1;
		}
    }
}
void print_map(void)
{
	int i,j;
	
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			print_block(block[i][j]);
		}
		printf("\n");
	}
}
void gotoxy(int x, int y)
{
	HANDLE hOutput;
	COORD coo;
	coo.X = x;
	coo.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, coo);
}