#include <stdio.h>
void check_5(char *a[30])
{
	int i,j;
	for(i=1;i<30;i=i+2)
		{
			for(j=0;j<29;j=j+2)
			{
				if((a[i][j]=='X')&&(a[i][j+2]=='X')&&(a[i][j+4]=='X')&&(a[i][j+6]=='X')&&(a[i][j+8]=='X'))
				{
					printf("��Ӯ��\n");exit(0); 
					break;
				}	
				if((a[i][j]=='X')&&(a[i+2][j]=='X')&&(a[i+4][j]=='X')&&(a[i+6][j]=='X')&&(a[i+8][j]=='X'))
				{
					printf("��Ӯ��\n");exit(0);
					break;
				}	
				if((a[i][j]=='X')&&(a[i+2][j+2]=='X')&&(a[i+4][j+4]=='X')&&(a[i+6][j+6]=='X')&&(a[i+8][j+8]=='X'))
				{
					printf("��Ӯ��\n");exit(0);
					break;
				}	
				if((a[i][j]=='X')&&(a[i+2][j-2]=='X')&&(a[i+4][j-4]=='X')&&(a[i+6][j-6]=='X')&&(a[i+8][j-8]=='X')&&(j>10))
				{
					printf("��Ӯ��\n");exit(0);
					break;
				}
				if((a[i][j]=='O')&&(a[i][j+2]=='O')&&(a[i][j+4]=='O')&&(a[i][j+6]=='O')&&(a[i][j+8]=='O'))
				{
					printf("������\n");exit(0); 
					break;
				}	
				if((a[i][j]=='O')&&(a[i+2][j]=='O')&&(a[i+4][j]=='O')&&(a[i+6][j]=='O')&&(a[i+8][j]=='O'))
				{
					printf("������\n");exit(0);
					break;
				}
				if((a[i][j]=='O')&&(a[i+2][j+2]=='O')&&(a[i+4][j+4]=='O')&&(a[i+6][j+6]=='O')&&(a[i+8][j+8]=='O'))
				{
					printf("������\n");exit(0);
					break;
				}
				if((a[i][j]=='O')&&(a[i+2][j-2]=='O')&&(a[i+4][j-4]=='O')&&(a[i+6][j-6]=='O')&&(a[i+8][j-8]=='O')&&(j>10))
				{
					printf("������\n");exit(0);
					break;
				}
			}
		}
}