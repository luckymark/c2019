#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <string.h>
void readmap(char *a[100])
{
	int i,j,n;
	printf("�����ӡ�B���ƶ�����D���ϼ���\n");
	printf("������1��2ѡ��:");
	scanf("%d",&n);
	FILE *fpRead;
	if(n==1)
	{
		fpRead=fopen("boxmap1.txt","r");
	} 
    	else if(n==2) 
		{
			fpRead=fopen("boxmap2.txt","r");
		}
			else if(n==3)
			{
				fpRead=fopen("score.txt","r");
			}
	for(i=0;i<15;i++)
	{
		fscanf(fpRead,"%s",a[i]);
		for(j=0;j<20;j++)
		{
			if(a[i][j]=='#')
	        	a[i][j]=' ';
		}
	}
}