#include"show.h"
#include"userinput.h"
#include"exam.h"
#include"menu.h"
#include"examasume.h"
#include"input1.h"
#include"assume.h"
#include"window.h"
int main()
{
	int n;
	system("color 70");//控制台颜色
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "五子棋");

	menu();
	if (point == 1)
	{
		printf("1:   using mouse\n");
		printf("2:   using keyboard\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			point = 11;//用来传递用户选择
			break;
		case 2:
			point = 12;
			break;
		default:
			break;
		}
		if (point == 11)
		{
			int x = 800;
			int y = 800;
			MoveWindow(hwnd, 0, 0, x, y, true);
			system("cls");
			show();
			printf("不要移动控制台,鼠标指向位置,空格下棋\n");
			while (1)
			{
				if (_kbhit())
				{
					system("cls");
					ch = _getch();
					setpoint(ch);//用户互相下棋
					show();
					printf("不要移动控制台,鼠标指向位置,空格下棋 \n \n\n\n\n\n\n");
					switch (exam())
					{
					case 2:
						printf("white is win");
						getchar();
						exit(1);
						break;
					case 4:
						printf("black is win");
						getchar();
						exit(1);
						break;
					default:
						break;
					}
				}
			}
		}
		if (point == 12)
		{
			show();
			printf("a向左移动，d向右移动，w向上移动，s向下移动，空格下棋\n \n \n\n\n\n\n\n");
			while (1)
			{
				if (_kbhit())
				{
					ch = _getch();
					input();//用户下棋
					switch (exam())
					{
					case 2:
						printf("white is win");
						getchar();
						exit(1);
						break;
					case 4:
						printf("black is win");
						getchar();
						exit(1);
						break;
					default:
						break;
					}
					system("cls");
					//  assume();
					show();
					printf("a向左移动，d向右移动，w向上移动，s向下移动，空格下棋\n \n \n\n\n\n\n\n");
					Sleep(100);
				}
			}
		}
	}
	if (point == 2)
	{
		printf("1:   using mouse\n");
		printf("2:   using keyboard\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			point = 21;
			break;
		case 2:
			point = 22;
			break;
		default:
			break;
		}
		if (point == 22)
		{
			system("cls");
			board[0][0] = 2;//默认电脑先下
			show();
			printf("◎为电脑上一步下的棋a向左移动，d向右移动，w向上移动，s向下移动，空格下棋\n \n \n\n\n\n\n\n");
			while (1)
			{
				if (_kbhit())
				{
   					ch = _getch();
					input1();//用户下棋
					system("cls");
					show();
					printf("◎为电脑上一步下的棋a向左移动，d向右移动，w向上移动，s向下移动，空格下棋\n \n \n\n\n\n\n\n");
					switch (exam())
					{
					case 2:
						printf("white is win");
						getchar();
						system("pause");
						exit(1);
						break;
					case 4:
						printf("black is win");
						getchar();
						system("pause");
						exit(1);
						break;
					default:
						break;
					}
					system("cls");
					if (ch == ' '&&first1 == 0)
					{
						if (first3 == 1)
						{
							board[temp_x][temp_y] = 2;//使电脑最近下的棋◎还原
							first3 = 0;
						}
						first3 = 1;
						assume();//电脑下棋
						show();
						printf("◎为电脑上一步下的棋a向左移动，d向右移动，w向上移动，s向下移动，空格下棋\n \n \n\n\n\n\n\n");
						switch (exam())
						{
						case 2:
							printf("你被电脑打败了哈哈哈 \n \n \n\n\n\n\n\n");
							getchar();
							system("pause");
							exit(1);
							break;
						case 4:
							printf("你战胜了电脑，流弊！ \n \n \n\n\n\n\n\n");
							getchar();
							system("pause");
							exit(1);
							break;
						default:
							break;
						}
						//getchar();
						system("cls");
					}
					show();
					printf("◎为电脑上一步下的棋a向左移动，d向右移动，w向上移动，s向下移动，空格下棋\n \n \n\n\n\n\n\n");
				}
				first1 = 1;
			}
		}
		if (point == 21)
		{
			board[7][7] = 2;//默认电脑先下
			int x = 800;
			int y = 800;
			MoveWindow(hwnd, 0, 0, x, y, true);
			system("cls");
			show();
			printf("◎为电脑上一步下的棋,不要移动控制台,鼠标指向位置,空格下棋 \n \n \n\n\n\n\n\n ");
			while (1)
			{
				if (_kbhit())
				{
					system("cls");
					ch = _getch();

					setpointhum(ch);//玩家下棋
					show();
					printf("◎为电脑上一步下的棋，不要移动控制台,鼠标指向位置,空格下棋 \n  \n \n\n\n\n\n\n");
					switch (exam())
					{
					case 2:
						printf("white is win");
						getchar();
						system("pause");
						exit(1);
						break;
					case 4:
						printf("black is win");
						getchar();
						system("pause");
						exit(1);
						break;
					default:
						break;
					};
					if (ch == ' '&&first1 == 0)
					{
						system("cls");
						if (first3 == 1)
						{
							board[temp_x][temp_y] = 2;//还原◎提示的棋子
							first3 = 0;
						}
						first3 = 1;
						assume();
						show();
						printf("◎为电脑上一步下的棋,不要移动控制台,鼠标指向位置,空格下棋 \n \n \n\n\n\n\n\n ");
						switch (exam())
						{
						case 2:
							printf("你被电脑打败了哈哈哈 \n \n \n\n\n\n\n\n");
							getchar();
							system("pause");
							exit(1);
							break;
						case 4:
							printf("你战胜了电脑，流弊！ \n \n \n\n\n\n\n\n");
							getchar();
							system("pause");
							exit(1);
							break;
						default:
							break;
						}
					}
					first1 = 1;
				}
			}
		}
	}
}