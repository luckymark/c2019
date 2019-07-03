#include<stdio.h>
#include"move.h"

int maparray[11][11],boxnum;
extern int score;
extern struct playerdir
{
	int x;
	int y;
};
extern playerdir player;

//1Ϊǽ��-1Ϊ·��0Ϊplayer��2Ϊ���ӣ�3ΪĿ��ص㣬4Ϊ�Ƶ��ط������ӣ�5Ϊ�˵������Ǳ�ǣ�����ͼ��ʱ������֮���ÿո������

int mapdesign(int lv)
{
	FILE *fp;
	//errno_t err����fopen_s��Ҫ��һ��������������ж��ļ��Ƿ���ڵģ���0��1����ֵ������û�ã�Ĭ�ϵ�ͼ�϶����ڣ�
	switch (lv)
	{
		case(1):
		{
			fopen_s(&fp, "map1.txt", "r");//ע��˴�fopen_s��fopen�÷���һ����fopen���÷���fp=fopen("map1.txt","r")��
			break;
		}
		case(2):
		{
			fopen_s(&fp, "map2.txt", "r");
			break;
		}
		case(3):
		{
			fopen_s(&fp, "map3.txt", "r");
			break;
		}
		default:
		{
			printf("�����Ѷ��д�����������:(\n");
			return 0;
		}
	}
	for (int line = 0; line < 11; line++)
	{
		for (int row = 0; row < 11; row++)
		{
			fscanf_s(fp, "%d", &maparray[line][row]);
			if (maparray[line][row] == 0)//���ԭ��ͼ���������λ��
			{
				player.x = line;
				player.y = row;
			}
			if (maparray[line][row] == 2)//���ԭ��ͼ��������
			{
				boxnum++;
			}
		}
	}
	fclose(fp);
	return 1;
}

void mapcreate()
{
	if (maparray[player.x][player.y] == 3 || maparray[player.x][player.y] == 4)//������Ŀ�ĵػ����Ƶ��ط������ӣ�
	{
		maparray[player.x][player.y] = 5;
	}
	else//�����������ģ�
	{
		maparray[player.x][player.y] = 0;
	}
	for (int i = 0; i < 11; i++)
	{
		for (int t = 0; t < 11; t++)
		{
			if (maparray[i][t] == 1)
			{
				printf("��");
			}
			else if (maparray[i][t] == -1)
			{
				printf("  ");
			}
			else if (maparray[i][t] == 0 || maparray[i][t] == 5)
			{
				printf("��");
			}
			else if (maparray[i][t] == 2)
			{
				printf("��");
			}
			else if (maparray[i][t] == 3)
			{
				printf("��");
			}
			else if (maparray[i][t] == 4)
			{
				printf("��");
			}
		}
		printf("\n");
	}
	printf("score:%d", score);
	return;
}