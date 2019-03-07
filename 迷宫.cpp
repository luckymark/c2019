#include<iostream>
#include<conio.h>
#include<time.h>
using namespace std;
const int length = 20;
const int width = 50;
const char wall = 35;
const char you = 42;
char A[length][width];
void move(void);
void create_maze(int a,int b);
int main()
{
	for (int i = 0; i <= length - 1; i++)
		for (int b = 0; b <= width - 1; b++)
		{
			if (b == 0 || b == width - 1)
			{
				A[i][b] = wall;
				continue;
			}
			if (i == 0 || i == length - 1)
			{
				A[i][b] = wall;
				continue;
			}
			A[i][b] = ' ';
		}
	A[1][0] = you;
	A[length - 2][width - 1] = '六';

	create_maze(0,0);

	for (int i = 0; i <= length - 1; i++)  //把迷宫输出
		for (int b = 0; b <= width - 1; b++)
		{
			cout << A[i][b];
			if (b == width - 1)
				cout << endl;
		}cout << "6老师在屏幕左下角的6处等你，请你快去，不然可是要谢罪的。上下左右键控制方向，ESC键退出";
	
	move();  
	

}

void move(void)   //移动位置
{
	int d;
	int x = 1; int y = 0;
	while ((d = _getch()) != 27)
	{
		system("cls");
		
		
		switch (d)    //开始移动目前位置
		{
		case(72):
			if (A[x - 1][y] != wall)
		{
			A[x - 1][y] = A[x][y]; A[x][y] = ' '; x--;
		} 
				 break;
		case(80):
			if (A[x + 1][y] != wall)
		{
			A[x + 1][y] = A[x][y]; A[x][y] = ' '; x++;
		} 
				 break;
		case(75): 
			if (A[x][y - 1] != wall)
		{
			A[x][y - 1] = A[x][y];  A[x][y] = ' '; y--;
		} 
				  break;
		case(77): 
			if (A[x][y + 1] != wall)
		{
			A[x][y + 1] = A[x][y];  A[x][y] = ' '; y++;
		}
				  break;
		}
		
				
		for (int i = 0; i <= length - 1; i++)
			for (int b = 0; b <= width - 1; b++)
			{
				cout << A[i][b];
				if (b == width - 1)
					cout << endl;
			}
		cout << "6老师在屏幕左下角的6处等你，请你快去，不然可是要谢罪的。上下左右键控制方向，ESC键退出";
		if (x == length - 2 && y == width - 1)
			break;

	}
	system("cls");
	if (d == 27)
		cout << "不走程序直接开花!!!"<<endl;
	else cout << "恭喜你，开花开花!!!"<<endl;
	system("pause");
}

void create_maze(int a, int b)
{
	int x, y;

	srand(time(NULL));
	x = rand() % (length - 4) + 2;
	y = rand() % (width - 4) + 2;
	for (int i = 1; i <= length; i++)
		A[i][y] = wall;
	for (int i = 1; i <= width; i++)
		A[x][i] = wall;   //至此建墙,下面为开墙；

	int B[4] = { 1,2,3,4 };   //1234分别表示在当前点的上下左右边开洞，四条边总共开3边能够保证一定有出口
	int direction=rand() % 4;
	for (int i = 1; i <= 4; i++)
	{
		
			switch (direction)
			{
			case(1): 
			
				A[x - 1][y] = ' ';  break;
			
					
			case(2):
			
				A[x + 1][y] = ' ';  break;
			
			
			case(3):
			
				A[x][y - 1] = ' ';  break;
			
			case(4): 
				A[x][y+1] = ' ';  break;
			}
			
			direction++;
			if (direction >3)
				direction = 0;
	}
	
}




//case(1): A[rand() % (x - 1) + 1][y] = ' ';  break;
//case(2): A[rand() % (length - x - 1) + x + 1][y] = ' ';  break;
//case(3): A[rand() % (y - 1) + 1][x] = ' ';  break;
//case(4): A[rand() % (width - y - 1) + y - 1][x] = ' ';  break;