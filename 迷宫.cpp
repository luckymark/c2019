#include<iostream>
#include<conio.h>
using namespace std;
const int length = 10;
const int width = 10;
char A[length][width];
int main()
{
	for (int i = 0; i <= length-1; i++)
		for (int b = 0; b <= width-1; b++)
		{
			if (b == 0 || b == width - 1)
			{
				A[i][b] = '1';
				continue;
			}
			if (i == 0 || i == length - 1)
			{
				A[i][b] = '1';
				continue;
			}
			A[i][b] = ' ';
		}
	A[1][0] = 'a';
    A[length - 2][width - 1] = ' ';
	for (int i = 0; i <= length - 1; i++)  //把迷宫输出
		for (int b = 0; b <= width - 1; b++)
		{
			cout << A[i][b];
			if (b == width - 1)
				cout << endl;
		}
	int d;
	int x = 1; int y = 0;
	cout << A[x][y] << endl;
	while ((d = _getch())!=27)
	{
		system("cls");
		switch (d)
	 {
		case(72):if (A[x - 1][y] != '1')
		{
			A[x - 1][y] = A[x][y]; A[x][y] = ' '; x--;
		} break;
		case(80):if (A[x + 1][y] != '1') 
		{
			A[x + 1][y] = A[x][y]; A[x][y] = ' '; x++;
		} break;
		case(75): if (A[x][y - 1] != '1')
		{
			A[x][y - 1] = A[x][y];  A[x][y] = ' '; y--;
		}break;
		case(77): if (A[x][y + 1] != '1')
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
		if (x == length - 2 && y == width - 1)
			break;
		
	}
	system("cls");
	if(d==27)
		cout <<"不走程序直接开花";
	else cout << "恭喜你，开花开花";
	system("pause");

}

