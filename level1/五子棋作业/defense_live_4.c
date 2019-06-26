#include <stdlib.h>
#include <stdio.h>
int defense_live_4(char *a[30])
{
	int i,j,n;
for(i=1;i<30;i=i+2)
	{
		if(n==1)break;//以下为判断“XXXX”型的活四，最为要紧，所以最先判断 
		for(j=0;j<29;j=j+2)
		{
			if((((a[i][j]==' ')||(a[i+10][j]==' '))&&(a[i+2][j]=='X')&&(a[i+4][j]=='X')&&(a[i+6][j]=='X'))&&(a[i+8][j]=='X'))
			{
				if(a[i][j]==' ')
				{
					a[i][j]='O';
				}
				else a[i+10][j]='O';n=1;
				break;
			}
			if((((a[i][j]==' ')||(a[i][j+10]==' '))&&(a[i][j+2]=='X')&&(a[i][j+4]=='X')&&(a[i][j+6]=='X'))&&(a[i][j+8]=='X'))
			{
			    if(a[i][j]==' ')
				{
					a[i][j]='O';
				}
				else a[i][j+10]='O';n=1;
				break;
			}
			if((((a[i][j]==' ')||(a[i+10][j+10]==' '))&&(a[i+2][j+2]=='X')&&(a[i+4][j+4]==' ')&&(a[i+6][j+6]=='X'))&&(a[i+8][j+8]=='X'))
			{
				if(a[i][j]==' ')
				{
					a[i][j]='O';
				}
				else a[i=10][j+10]='O';n=1;
				break;
			}
			if(((((a[i][j]==' ')||(a[i+10][j-10]==' '))&&(a[i+2][j-2]=='X')&&(a[i+4][j-4]==' ')&&(a[i+6][j-6]=='X'))&&(a[i+8][j-8]=='X'))&&(j>12))
			{
				if(a[i][j]==' ')
				{
					a[i][j]='O';
				}
				else a[i+10][j-10]='O';n=1;
				break;
			}	
		} 
	}
	return n;
}