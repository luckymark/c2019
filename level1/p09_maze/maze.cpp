/*todolist
1.read map;
2.print map&you;
3.move it:1)input;2)canyoumove?;
4.judge if you win;
5.score;*/
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#define W 219
#define P 232
#define K 224
#define E 215

unsigned char screen[22][22];
void map(int level);
void print_map(void);
void judge(int level);
void gotoxy(int x, int y);

int main(void)
{
	char input;

	system("chcp 437");
	system("mode con cols=23 lines=23");
	system("cls");

	printf("Maze\n");
	printf("Info:Use \"w\" \"a\" \"s\" \"d\" to move,and you should");
	printf("get the %c to open the door(%c)\n",K,E);
	printf("please choose a map:\n");
	printf("1  2  q.quit\n");
	while((input=getch())!='q')
	{
		switch(input)
		{
			case '1':
				map(0);
				judge(0);
				break;
			case '2':
			    map(1);
				judge(1);
				break;
			case 'q':
				return 0;
			default:
				;
		}

		map(-1);
		system("cls");
		printf("Super Maze\n");
		printf("Info:Use \"w\" \"a\" \"s\" \"d\" to move,and you should");
		printf("get the %c to open the door(%c)\n",K,E);
		printf("please choose a map:\n");
		printf("1  2  q.quit\n");

	}


	return 0;
}
void map(int level)
{
	int i,j;

    for(i=0;i<22;i++)
	{
		screen[i][0]=W;
		screen[i][21]=W;
	}
	for(j=1;j<21;j++)
	{
		screen[0][j]=W;
		screen[21][j]=W;
	}

	if(level==0)
	{

		for(i=8;i<11;i++)
		{
			screen[i][1]=W;
		}
		screen[4][1]=W;
		screen[14][1]=W;
		screen[16][1]=W;

		for(i=2;i<=14;i=i+2)
		{
			if(i!=8)
			{
				screen[i][2]=W;
			}
		}
		for(i=16;i<20;i++)
		{
			screen[i][2]=W;
		}

		for(i=1;i<15;i++)
		{
			if(i!=3&&i!=5&&i!=9&&i!=11
			&&i!=13)
			{
				screen[i][3]=W;
			}
		}

		screen[1][4]=W;
		screen[4][4]=W;
		screen[8][4]=W;
		screen[12][4]=W;
		screen[14][4]=W;
		for(i=16;i<21;i++)
		{
			if(i!=18)
			{
				screen[i][4]=W;
			}
		}

		for(i=1;i<13;i++)
		{
			if(i!=2&&i!=7)
			{
				screen[i][5]=W;
			}
		}
		screen[14][5]=W;
		screen[16][5]=W;
		screen[19][5]=W;

		screen[1][6]=W;
		screen[3][6]=W;
		screen[8][6]=W;
		screen[16][6]=W;
		screen[18][6]=W;
		screen[19][6]=W;

		for(i=1;i<8;i=i+2)
		{
			screen[i][7]=W;
		}
		screen[8][7]=W;
		for(i=10;i<19;i++)
		{
			if(i!=17)
			{
				screen[i][7]=W;
			}
		}

		for(i=3;i<8;i=i+2)
		{
			screen[i][8]=W;
		}
		screen[10][8]=W;
		screen[16][8]=W;
		screen[18][8]=W;
		screen[19][8]=W;

		for(i=2;i<15;i++)
		{
			if(i!=4&&i!=6&&i!=8&&i!=11)
			{
				screen[i][9]=W;
			}
		}

		screen[5][10]=W;
		screen[7][10]=W;
		for(i=10;i<20;i++)
		{
			if(i!=13&&i!=15)
			{
				screen[i][10]=W;
			}
		}

		for(i=1;i<9;i++)
		{
			if(i!=4&&i!=6)
			{
				screen[i][11]=W;
			}
		}
		screen[11][11]=W;
		screen[14][11]=W;
		screen[16][11]=W;

		screen[5][12]=W;
		screen[8][12]=W;
		screen[9][12]=W;
		for(i=13;i<21;i++)
		{
			screen[i][12]=W;
		}

		screen[1][13]=W;
		for(i=3;i<12;i++)
		{
			screen[i][13]=W;
		}

		screen[1][14]=W;
		screen[3][14]=W;
		screen[7][14]=W;
		for(i=11;i<21;i++)
		{
			if(i!=16)
			{
				screen[i][14]=W;
			}
		}

		for(i=3;i<20;i=i+2)
		{
			if(i!=13)
			{
				screen[i][15]=W;
			}
		}

		for(i=3;i<20;i=i+2)
		{
			if(i!=15)
			{
				screen[i][16]=W;
			}
		}
		screen[2][16]=W;

		for(i=5;i<20;i=i+2)
		{
			screen[i][17]=W;
		}
		for(i=14;i<18;i++)
		{
			screen[i][17]=W;
		}

		screen[16][18]=W;
		for(i=1;i<6;i++)
		{
			screen[i][18]=W;
		}
		for(i=7;i<12;i=i+2)
		{
			screen[i][18]=W;
		}
		screen[19][18]=W;

		screen[3][19]=W;
		screen[11][19]=W;
		for(i=7;i<10;i++)
		{
			screen[i][19]=W;
		}
		for(i=13;i<20;i++)
		{
			if(i!=17)
			{
				screen[i][19]=W;
			}
		}

		screen[1][20]=W;
		screen[11][20]=W;
		screen[5][20]=W;

		screen[0][2]=P;
		screen[21][15]=E;
		screen[8][18]=K;
	}
	else if(level==1)
	{
		for(i=5;i<8;i++)
		{
			screen[i][1]=W;
		}
		screen[11][1]=W;
		screen[15][1]=W;

		for(i=1;i<14;i=i+2)
		{
			if(i!=5)
			{
				screen[i][2]=W;
			}
		}
		for(i=15;i<19;i++)
		{
			screen[i][2]=W;
		}

		for(i=3;i<6;i++)
		{
			screen[i][3]=W;
		}
		for(i=9;i<14;i=i+2)
		{
			screen[i][3]=W;
		}
		screen[18][3]=W;
		screen[20][3]=W;

		screen[2][4]=W;
		screen[3][4]=W;
		for(i=5;i<10;i++)
		{
			screen[i][4]=W;
		}
		for(i=13;i<17;i++)
		{
			screen[i][4]=W;
		}
		screen[18][4]=W;

		screen[5][5]=W;
		screen[12][5]=W;
		screen[13][5]=W;
		screen[16][5]=W;
		screen[18][5]=W;
		screen[19][5]=W;

		for(i=1;i<13;i++)
		{
			if(i!=4&&i!=6)
			{
				screen[i][6]=W;
			}
		}
		screen[14][6]=W;
		screen[16][6]=W;

		screen[5][7]=W;
		screen[14][7]=W;
		for(i=16;i<20;i++)
		{
			screen[i][7]=W;
		}

		screen[1][8]=W;
		screen[16][8]=W;
		screen[19][8]=W;
		for(i=3;i<15;i++)
		{
			if(i!=11)
			{
				screen[i][8]=W;
			}
		}

		screen[6][9]=W;
		screen[10][9]=W;
		screen[16][9]=W;
		screen[17][9]=W;

		screen[1][10]=W;
		screen[3][10]=W;
		for(i=4;i<9;i=i+2)
		{
			screen[i][10]=W;
		}
		for(i=10;i<15;i++)
		{
			screen[i][10]=W;
		}
		screen[16][10]=W;
		screen[19][10]=W;

		for(i=4;i<19;i=i+2)
		{
			if(i!=6&&i!=12)
			{
				screen[i][11]=W;
			}
		}
		screen[19][11]=W;

		for(i=1;i<9;i++)
		{
			if(i!=3)
			{
				screen[i][12]=W;
			}
		}
		for(i=10;i<17;i=i+2)
		{
			screen[i][12]=W;
		}
		screen[19][12]=W;

		screen[4][13]=W;
		screen[10][13]=W;
		screen[12][13]=W;
		screen[16][13]=W;
		screen[17][13]=W;
		screen[19][13]=W;

		for(i=2;i<18;i++)
		{
			if(i!=5)
			{
				screen[i][14]=W;
			}
		}

		screen[2][15]=W;
		screen[4][15]=W;
		screen[14][15]=W;
		screen[17][15]=W;
		screen[19][15]=W;
		screen[20][15]=W;

		for(i=1;i<13;i++)
		{
			if(i!=3)
			{
				screen[i][16]=W;
			}
		}
		screen[16][16]=W;
		screen[17][16]=W;

		screen[2][17]=W;
		screen[6][17]=W;
		screen[19][17]=W;
		for(i=12;i<17;i++)
		{
			screen[i][17]=W;
		}

		for(i=2;i<11;i=i+2)
		{
			screen[i][18]=W;
		}
		screen[9][18]=W;
		screen[18][18]=W;

		for(i=2;i<9;i=i+2)
		{
			screen[i][19]=W;
		}
		screen[3][19]=W;
		screen[20][19]=W;
		for(i=10;i<19;i++)
		{
			screen[i][19]=W;
		}

		screen[8][20]=W;

		screen[0][15]=P;
		screen[0][17]=E;
		screen[16][15]=K;
	}
	else if(level==-1)
	{
		for(i=0;i<22;i++)
		{
			for(j=0;j<22;j++)
			{
				screen[i][j]=' ';
			}
		}
	}
}
void print_map(void)
{
	int i,j;

	system("cls");
	for(i=0;i<22;i++)
	{
		for(j=0;j<22;j++)
		{
			printf("%c",screen[i][j]);
		}
		printf("\n");
	}
}
void judge(int level)
{
	char move;
	int i,j,k,l,m,n;

	if(level==0)
	{
		i=0;
		j=2;
		k=21;
		l=15;
		m=8;
		n=18;
	}
	else if(level==1)
	{
		i=0;
		j=15;
		k=0;
		l=17;
		m=16;
		n=15;
	}
	print_map();
	while(screen[k][l]!=P)
	{
		gotoxy(j,i);
		move=getch();
		switch(move)
		{
			case 'w':
				if(i!=0&&screen[i-1][j]!=W&&screen[i-1][j]!=E)//did not come to the final.
				{
					screen[i][j]=' ';
					gotoxy(j,i);
					printf("%c",screen[i][j]);
					i--;
					screen[i][j]=P;
					gotoxy(j,i);
					printf("%c",screen[i][j]);
				}
				break;
			case 's':
				if(i!=21&&screen[i+1][j]!=W&&screen[i+1][j]!=E)
				{
					screen[i][j]=' ';
					gotoxy(j,i);
					printf("%c",screen[i][j]);
					i++;
					screen[i][j]=P;
					gotoxy(j,i);
					printf("%c",screen[i][j]);
				}
				break;
			case 'a':
				if(j!=0&&screen[i][j-1]!=W&&screen[i][j-1]!=E)
				{
					screen[i][j]=' ';
					gotoxy(j,i);
					printf("%c",screen[i][j]);
					j--;
					screen[i][j]=P;
					gotoxy(j,i);
					printf("%c",screen[i][j]);
				}
				break;
			case 'd':
				if(j!=21&&screen[i][j+1]!=W&&screen[i][j+1]!=E)
				{

					screen[i][j]=' ';
					gotoxy(j,i);
					printf("%c",screen[i][j]);
					j++;
					screen[i][j]=P;
					gotoxy(j,i);
					printf("%c",screen[i][j]);
				}
				break;
			case 27:
				return ;
			default:
			    ;
		}
		if(screen[m][n]!=K&&screen[k][l]!=P)
		{
			screen[k][l]=' ';
			gotoxy(l,k);
			printf("%c",screen[k][l]);
		}

	}
	system("cls");
	printf("YOU WIN!\n");
	system("pause");
}
//MFC set Console Cursor Position
void gotoxy(int x, int y)
{
	HANDLE hOutput;
	COORD coo;
	coo.X = x;
	coo.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, coo);
}
