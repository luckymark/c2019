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
	system("color 70");//����̨��ɫ
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "������");

	menu();
	if (point == 1)
	{
		printf("1:   using mouse\n");
		printf("2:   using keyboard\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			point = 11;//���������û�ѡ��
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
			printf("��Ҫ�ƶ�����̨,���ָ��λ��,�ո�����\n");
			while (1)
			{
				if (_kbhit())
				{
					system("cls");
					ch = _getch();
					setpoint(ch);//�û���������
					show();
					printf("��Ҫ�ƶ�����̨,���ָ��λ��,�ո����� \n \n\n\n\n\n\n");
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
			printf("a�����ƶ���d�����ƶ���w�����ƶ���s�����ƶ����ո�����\n \n \n\n\n\n\n\n");
			while (1)
			{
				if (_kbhit())
				{
					ch = _getch();
					input();//�û�����
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
					printf("a�����ƶ���d�����ƶ���w�����ƶ���s�����ƶ����ո�����\n \n \n\n\n\n\n\n");
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
			board[0][0] = 2;//Ĭ�ϵ�������
			show();
			printf("��Ϊ������һ���µ���a�����ƶ���d�����ƶ���w�����ƶ���s�����ƶ����ո�����\n \n \n\n\n\n\n\n");
			while (1)
			{
				if (_kbhit())
				{
   					ch = _getch();
					input1();//�û�����
					system("cls");
					show();
					printf("��Ϊ������һ���µ���a�����ƶ���d�����ƶ���w�����ƶ���s�����ƶ����ո�����\n \n \n\n\n\n\n\n");
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
							board[temp_x][temp_y] = 2;//ʹ��������µ����ԭ
							first3 = 0;
						}
						first3 = 1;
						assume();//��������
						show();
						printf("��Ϊ������һ���µ���a�����ƶ���d�����ƶ���w�����ƶ���s�����ƶ����ո�����\n \n \n\n\n\n\n\n");
						switch (exam())
						{
						case 2:
							printf("�㱻���Դ���˹����� \n \n \n\n\n\n\n\n");
							getchar();
							system("pause");
							exit(1);
							break;
						case 4:
							printf("��սʤ�˵��ԣ����ף� \n \n \n\n\n\n\n\n");
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
					printf("��Ϊ������һ���µ���a�����ƶ���d�����ƶ���w�����ƶ���s�����ƶ����ո�����\n \n \n\n\n\n\n\n");
				}
				first1 = 1;
			}
		}
		if (point == 21)
		{
			board[7][7] = 2;//Ĭ�ϵ�������
			int x = 800;
			int y = 800;
			MoveWindow(hwnd, 0, 0, x, y, true);
			system("cls");
			show();
			printf("��Ϊ������һ���µ���,��Ҫ�ƶ�����̨,���ָ��λ��,�ո����� \n \n \n\n\n\n\n\n ");
			while (1)
			{
				if (_kbhit())
				{
					system("cls");
					ch = _getch();

					setpointhum(ch);//�������
					show();
					printf("��Ϊ������һ���µ��壬��Ҫ�ƶ�����̨,���ָ��λ��,�ո����� \n  \n \n\n\n\n\n\n");
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
							board[temp_x][temp_y] = 2;//��ԭ����ʾ������
							first3 = 0;
						}
						first3 = 1;
						assume();
						show();
						printf("��Ϊ������һ���µ���,��Ҫ�ƶ�����̨,���ָ��λ��,�ո����� \n \n \n\n\n\n\n\n ");
						switch (exam())
						{
						case 2:
							printf("�㱻���Դ���˹����� \n \n \n\n\n\n\n\n");
							getchar();
							system("pause");
							exit(1);
							break;
						case 4:
							printf("��սʤ�˵��ԣ����ף� \n \n \n\n\n\n\n\n");
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