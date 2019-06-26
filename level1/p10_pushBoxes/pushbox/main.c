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
		printf("第一关地图已生成\n");
		printf("输入r从新开始\n");
		print();
		while (1)
		{
			if (_kbhit())
			{
				ch = _getch();
				Sleep(50);
				system("cls");
				printf("w向上移动 s向下移动 a向左移动 d向右移动 r重来\n");
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
