#include"show.h"
#include"useinput.h"
#include"move.h"
#include"exam.h"
#include"second.h"
int main()
{
	    int i,j;
	    if(freopen("text.txt", "r", stdin)==NULL)
			printf("error");
		for (i = 0; i < Maplong; i++)
		{
			for (j = 0; j < Mapwidth; j++)
			{
				scanf("%d", &map[i][j]);
				rmap[i][j] = map[i][j];
				if (map[i][j] == 2)
				{
					box_x = i;
					box_y = j;
				}
			}
		}
		freopen("CON", "r", stdin);
		printf("��һ�ص�ͼ������\n");
		printf("����r���¿�ʼ\n");
		print();
		while (1)
		{
			if (_kbhit())
			{
				ch = _getch();
				Sleep(50);
				system("cls");
				printf("w�����ƶ� s�����ƶ� a�����ƶ� d�����ƶ� r����\n");
				userinput(ch);
				boxmove();
				print();
				printf("your score are %d \n", scorenumber);
				if (exam())
				{
					second();
				}
			}
		}
}
