#include<iostream>
#include<cstdlib>
#include<queue>
#include<ctime>
#include<windows.h>
#include<conio.h>
using namespace std;
int flag;
int x=1,y=1;
int maze[30][30];
char name[100];
bool vis[30][30];
struct Node
{
	int x,y;
};
void open()
{
	cout<<"\n\n---Welcome!---"<<endl<<endl;
	cout<<"Enter 1 to start the game."<<endl;
	cout<<"Enter 0 to over the game.\n"<<endl;
	cout<<"             --Made by lance \n"<<endl;
	cin>>flag;
	while(flag!=1&&flag!=0)
	{
		cout<<"Please enter a legal number!\n";
		cin>>flag;
	}
	if(!flag) return ; 
	system("cls");
	cout<<"Please leave your name:\n";
	scanf("%s",name);
	cout<<"OK!"<<name<<" Have a good game.\n";
	Sleep(1000);
	system("cls");
}
void Creative()
{
	srand((unsigned)time(NULL));
	for(int i=1;i<26;i++)
	{
		for(int j=1;j<26;j++)
		{
			if((rand()%99)<34)	maze[i][j]=1;
			else maze[i][j]=0;
		}
	}
	maze[1][1]=maze[25][25]=0;
}
bool Ismaze()
{
	memset(vis,0,sizeof(vis));
	int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1} ;
	queue<Node> q;
	Node tmp,next;
	tmp.x=1;
	tmp.y=1;
	vis[1][1]=1;
	q.push(tmp);
	while(!q.empty())
	{
		tmp=q.front();
		q.pop();
		if(tmp.x==25&&tmp.y==25) return 1;
		int xx,yy;
		for(int i=0;i<4;i++)
		{
			xx=tmp.x+dx[i];
			yy=dy[i]+tmp.y;
			if(xx<1||xx>25||yy<1||yy>25) continue;
			if(!maze[xx][yy]&&!vis[xx][yy])
			{
				next.x=xx;
				next.y=yy;
				q.push(next);
				vis[xx][yy]=1;
			}
		}
	}
	return 0;
} 
void Printmaze()
{
	for(int i=1;i<26;i++)
	{
		for(int j=1;j<26;j++)
		{
			if(i==x&&y==j) cout<<"¡ò";
			else if(i==25&&j==25) cout<<"³ö" ; 
			else if(maze[i][j]) cout<<"¡ö";
			else if(!maze[i][j]) cout<<"  "; 
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"Control direction with W S A D\n";
}
int main()
{
	open();
	if(flag)
	{
		Creative();
		while(!Ismaze())
		{
			Creative();
		}
		Printmaze();
		char c;
		while(x!=25||y!=25)
		{
		    c=getch();
			if(c=='W'||c=='w') x--;
			else if(c=='S'||c=='s') x++;
			else if(c=='a'||c=='A') y--;
			else if(c=='d'||c=='D') y++;
			else continue;
			if(x>25||x<1||y<1||y>25||maze[x][y]) 
			{
				cout<<"Cross the border! please enter again!\n";
				Sleep(500);
				if(x>25||c=='S'||c=='s') x--;
				else if(x<1||c=='W'||c=='w') x++;
				else if(y>25||c=='d'||c=='D') y--;
				else if(y<1||c=='a'||c=='A') y++; 
			}
			system("cls");
			Printmaze();
		}
		cout<<"\n\n     ---Wow!"<<name<<" you made it!---\n";
        system("pause"); 
	}
	return 0;
}
