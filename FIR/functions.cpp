#include"head.h"
void cls()
{
	system("cls");
}
void init(char board[N][N][L])
{
	int i,j;
	Blast.m=0;
	Blast.n=0;
	Wlast.m=0;
	Wlast.n=0;
	system("color f0");
	for(i=0;i<N;++i)
		for(j=0;j<N;++j)
		{
			sprintf(board[i][j],"©à ");
			if(j==0)
				sprintf(board[i][j],"©À ");
			if(j==N-1)
				sprintf(board[i][j],"©È");
			if(i==0)
			{
				sprintf(board[i][j],"©Ð ");
				if(j==0)
					sprintf(board[i][j],"©° ");
				if(j==N-1)
					sprintf(board[i][j],"©´");
			}
			if(i==N-1)
			{
				sprintf(board[i][j],"©Ø ");
				if(j==0)
					sprintf(board[i][j],"©¸ ");
				if(j==N-1)
					sprintf(board[i][j],"©¼");
			}
		}
	HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
	//HANDLE hin=GetStdHandle(STD_INPUT_HANDLE);
	CONSOLE_CURSOR_INFO cinfo;
	//DWORD oldmode;
	cinfo.bVisible=0;
	cinfo.dwSize=100;
	SetConsoleCursorInfo(hout,&cinfo);
	SetConsoleTitle(TITLE);
	//GetConsoleMode(hin,&oldmode);
	//SetConsoleMode(hin,oldmode|ENABLE_MOUSE_INPUT);
	//CloseHandle(hin);
	//CloseHandle(hout);
}
void printboard(char board[N][N][L])
{
	int i,j;
	cls();
	printf("  ");
	for(i=0;i<N;++i)
		printf("%2c",'A'+i);
	printf("\n");
	for(i=0;i<N;++i)
	{
		printf("%2d",i+1);
		for(j=0;j<N;++j)
		{
			printf("%s",board[i][j]);
			if(j==N-1)
				printf("\n");
		}
	}
}
void PlayerPos(char board[N][N][L])
{
	int m=0,n=0;
	/*scanf("%d%c",&m,&n);
	m-=1;
	n-='A';*/
	HANDLE hin=GetStdHandle(STD_INPUT_HANDLE);
	//HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
	INPUT_RECORD inRec;
	DWORD numRead;
	DWORD oldmode;
	GetConsoleMode(hin,&oldmode);
	SetConsoleMode(hin,oldmode|ENABLE_MOUSE_INPUT);
	while(1)
	{
		ReadConsoleInput(hin,&inRec,1,&numRead);
		if(inRec.EventType==MOUSE_EVENT&&inRec.Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			m=inRec.Event.MouseEvent.dwMousePosition.Y-1;
			n=inRec.Event.MouseEvent.dwMousePosition.X/2-1;
			if(board[m][n][1]!=BC&&board[m][n][1]!=WC)
				break;
		}
	}
	sprintf(board[m][n],"¡ñ");
	Blast.m=m;
	Blast.n=n;
	//CloseHandle(hin);
	//CloseHandle(hout);
}
void gotomn(int m,int n)
{
	HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos={2*n+2,m+1};
	SetConsoleCursorPosition(hout,pos);
	//CloseHandle(hout);
}
