#include <stdio.h>
int attack_1(int n,char *a[30])
{
	int i,j;
	if (n == 0)//�жϽ����Ƿ�ɹ� 
	{
		for (i = 1; i < 30; i = i + 2)//���Լ��䵥�����Ա������� 
		{
			if (n == 1)break;
			for (j = 0; j < 29; j = j + 2)
			{
				if ((a[i][j] == 'O') && (a[i][j + 2] == ' '))
				{
					a[i][j + 2] = 'O'; n = 1; break;
				}
				else if ((a[i][j] == 'O') && (a[i][j - 2] == ' ') && (j > 2))
				{
					a[i][j - 2] = 'O'; n = 1; break;
				}
				else if ((a[i][j] == 'O') && (a[i + 2][j] == ' '))
				{
					a[i + 2][j] = 'O'; n = 1; break;
				}
				else if ((a[i][j] == 'O') && (a[i - 2][j] == ' ') && (i > 2))
				{
					a[i + 2][j - 2] = 'O'; n = 1; break;
				}
				else if ((a[i][j] == 'O') && (a[i + 2][j + 2] == ' '))
				{
					a[i + 2][j + 2] = 'O'; n = 1; break;
				}
				else if ((a[i][j] == 'O') && (a[i - 2][j - 2] == ' ') && (i > 2) && (j > 2))
				{
					a[i - 2][j - 2] = 'O'; n = 1; break;
				}
				else if ((a[i][j] == 'O') && (a[i + 2][j - 2] == ' ') && (j > 2))
				{
					a[i + 2][j - 2] = 'O'; n = 1; break;
				}
				else if ((a[i][j] == 'O') && (a[i - 2][j + 2] == ' ') && (i > 2))
				{
					a[i - 2][j + 2] = 'O'; n = 1; break;
				}
			}
		}
	}
}