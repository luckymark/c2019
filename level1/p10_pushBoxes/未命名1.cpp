#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int main()
{
	int i,j,k,p,q;
	char ch;
	k=0;
	p=4;
	q=7;
	char a[50][50]={
	"     ###",
	"     # #",
	"     # #",
	"######@######",
	"#    @ &@   #",
	"#######@#####",
	"      # #    ",
	"      ###",
	};
	for(i=0;i<8;i++)//��ӡ�����Ϸ��ͼ 
	puts(a[i]);
	ch=getch();
	while(ch=='s'||ch=='w'||ch=='a'||ch=='d'||ch=='S'||ch=='W'||ch=='A'||ch=='D'||ch=='t')
	{
		if(ch=='s'||ch=='S')
	    {
		  if(a[p+2][q]!='#')//�ж��Ƿ�����ǽ 
		  {
		    if(a[p+1][q]=='@')//�ж��Ƿ������Ӱ��� 
		    {
		      a[p][q]=' ';
		      a[p+2][q]='@';
		      a[p+1][q]='&';
		      p+=1; 
		      system("cls");
	          for(i=0;i<8;i++)
	          puts(a[i]);
	          ch=getch();
		    }
		  } 
		  if(a[p+1][q]==' ')//�˻�ʱ�ж��Ƿ���·���� 
		   {
			  a[p][q]=' ';
			  a[p+1][q]='&';
			  p+=1; 
			  system("cls");
	          for(i=0;i<8;i++)
	          puts(a[i]);
	          ch=getch();
		   }
		  
		 
	    }
	    if(ch=='w'||ch=='W')
	    {
		  if(a[p-2][q]!='#')//�ж��Ƿ�����ǽ 
		  {
		  	if(a[p-1][q]=='@')//�ж��Ƿ������Ӱ���
		    {
		      a[p][q]=' ';
		      a[p-2][q]='@';
		      a[p-1][q]='&';
		      p-=1; 
		      system("cls");
	          for(i=0;i<8;i++)
	          puts(a[i]);
	          ch=getch();
		    }
		    
		  }
		    
		  if(a[p-1][q]==' ')//�˻�ʱ�ж��Ƿ���·���� 
		  {
			a[p][q]=' ';
			a[p-1][q]='&';
			p-=1; 
			system("cls");
	        for(i=0;i<8;i++)
	        puts(a[i]);
	        ch=getch();
		  }             
	    }
		if(ch=='a'||ch=='A')
	    {
		  if(a[p][q-2]!='#')//�ж��Ƿ�����ǽ 
		  {
		  	if(a[p][q-1]=='@')//�ж��Ƿ������Ӱ���
		    {
		      a[p][q]=' ';
		      a[p][q-2]='@';
		      a[p][q-1]='&';
		      q-=1;
		      system("cls");
	          for(i=0;i<8;i++)
	          puts(a[i]);
	          ch=getch();
		    }
		   
		  }
		    
		 if(a[p][q-1]==' ')//�˻�ʱ�ж��Ƿ���·���� 
		  {
			a[p][q]=' ';
			a[p][q-1]='&';
			q-=1;
			system("cls");
	        for(i=0;i<8;i++)
	        puts(a[i]);
	        ch=getch();
		  }             
		}
		if(ch=='D'||ch=='d')
	    {
		  if(a[p][q+2]!='#')//�ж��Ƿ�����ǽ 
		  {
		   if(a[p][q+1]=='@')//�ж��Ƿ������Ӱ���
		    {
		      a[p][q]=' ';
		      a[p][q+2]='@';
		      a[p][q+1]='&';
		      q+=1;
		      system("cls");
	          for(i=0;i<8;i++)
              puts(a[i]);
              ch=getch();
		    }
		    
		  }
		    
		  if(a[p][q+1]==' ')//�˻�ʱ�ж��Ƿ���·���� 
		    {
			   a[p][q]=' ';
			   a[p][q+1]='&';
			   q+=1;
			   system("cls");
	           for(i=0;i<8;i++)
	           puts(a[i]);
	           ch=getch();
		    }             
	    }
		if(ch=='t')
		break;                     
	}
	system("cls");
	for(i=0;i<8;i++)
	puts(a[i]);
	printf("��Ϸ����"); 
	return 0;
} 
