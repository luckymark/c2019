#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <string.h>
void gamestart()
{
	int x,y,nkey,x0,y0;
	char key;
	char *a[100];
	int i,j;
	for(i=0;i<15;i++)
	{
		a[i] = (char*)malloc(sizeof(char)*100);
	}
	createmap(a);
	x=13;y=1;
	x0=13;y0=1;
	printf("�Թ�С��Ϸ��w,s,a,d�������ң���ESC���˳������ǡ�o��\n"); 
	printf("���������ʼ"); 
	while(1)
	{
		a[14][1]='X'; 
		point:key=getch();nkey=(int)key;
		if(nkey==27)break;
		if(y>20)
		{
			system("cls"); 
			printf("��ϲ���߳��Թ�����");
			break; 
		} 
		switch(key)
		{
		   case 'w':
		   	{
   			    if(a[x-1][y]=='X')goto point;
				   if((x>0)&&(a[x-1][y]!='X'))
				   	{
				        x--;
				   		a[x0][y0]=' ';
				   		a[x][y]='o';
				   		x0=x;y0=y;
					    break;
				    }
   		    }
   		    case 'a':
		   	{
   			    if(a[x][y-1]=='X')goto point;
				   if((y>0)&&(a[x][y-1]!='X'))
   			    {
   			    	y--;
			        a[x0][y0]=' ';
				   		a[x][y]='o';
				   		x0=x;y0=y;
					break;
			    } 
   		    }
   		    case 'd':
		   	{
			   if(a[x][y+1]=='X')goto point;
			   if(a[x][y+1]!='X')
   			    {
			       y++;
				   a[x0][y0]=' ';
				   		a[x][y]='o';
				   		x0=x;y0=y;
				   break;
			    } 
   		    }
   		    case 's':
		   	{
   			    if(a[x+1][y]=='X')goto point;
				   if(a[x+1][y]!='X')
			    {
					x++;
			    	a[x0][y0]=' ';
				   		a[x][y]='o';
				   		x0=x;y0=y;
					break;
				}
   		    }defalt:break;
		}	
		system("cls");printf("�Թ�С��Ϸ��w,s,a,d�������ң���ESC���˳�\n");
		for(i=0;i<15;i++)
		{
			printf("%s\n",a[i]);
		}
	}
    system("pause");
}