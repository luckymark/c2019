#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
char a[11][31];
static int m=0,n=1;          //Æðµã 
int p=0,i,j,s;
void change_1()
{
	if(a[m][n]=='#')
	    m++;
	else
	 {
	   if(a[m][n]=='o') 
	   {
		  if(a[m-1][n]!='#'&&a[m-1][n]!='o')
	      {
		    a[m-1][n]='o';
	        a[m][n]='i';
	        a[m+1][n]=' ';
	        p++;
	      }
	      else
	        m++;
	   }
       else
	   {
	   	a[m][n]='i';
	    a[m+1][n]=' ';
	    p++;
	   }
     }
	  
}
		
void change_2()
{
	if(a[m][n]=='#')
	    m--;
	else
	 {
	   if(a[m][n]=='o') 
	   {
		  if(a[m+1][n]!='#'&&a[m+1][n]!='o')
	      {
		    a[m+1][n]='o';
	        a[m][n]='i';
	        a[m-1][n]=' ';
	        p++;
	      }
	      else
	        m--;
	   }
	   else
	   {
	   	a[m][n]='i';
	    a[m-1][n]=' ';
	    p++;
	   }
     }
	  
}	

void change_3()
{
	if(a[m][n]=='#')
	    n++;
	else
	 {
	   if(a[m][n]=='o') 
	   {
		  if(a[m][n-1]!='#'&&a[m][n-1]!='o')
	      {
		    a[m][n-1]='o';
	        a[m][n]='i';
	        a[m][n+1]=' ';
	        p++;
	      }
	      else
	        n++;
	   }
	   else
	   {
	   	a[m][n]='i';
	    a[m][n+1]=' ';
	    p++;
	   }
     }
	  
}

void change_4()
{
	if(a[m][n]=='#')
	    n--;
	else
	 {
	   if(a[m][n]=='o') 
	   {
		  if(a[m][n+1]!='#'&&a[m][n+1]!='o')
	      {
		    a[m][n+1]='o';
	        a[m][n]='i';
	        a[m][n-1]=' ';
	        p++;
	      }
	      else
	        n--;
	   }
	   else
	   {
	   	a[m][n]='i';
	    a[m][n-1]=' ';
	    p++;
	   }
     }
	  
}
void location()
{
	int c;
	if((c=getch())!=0x1B)
	{
		switch(c)
		{
			case 0xE0:
				switch(c=getch())
				{
					case 72: {m--; change_1();} break;
					case 80: {m++; change_2();} break;
					case 75: {n--; change_3();} break;
					case 77: {n++; change_4();} break;
					default:
						break;
				}
			    break;
			default:
				break;
		}
	}
}

void maze()
{
	for(i=0;i<=10;i++)
	{
		for(j=0;j<=30;j++)
		{
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	location();
} 
void Readmap(int s)
{
	FILE *fp;
	switch(s)
	{
		case 1: fp=fopen("maps\\map1.txt","r"); break;
		case 2: fp=fopen("maps\\map2.txt","r"); break;
		case 3: fp=fopen("maps\\map3.txt","r"); break;
		case 4: fp=fopen("maps\\map4.txt","r"); break;
		default:
			break;
	}
	if(fp==NULL)
	  printf("Cann't open file!\n");
	else
	{
		for(i=0;i<=10;i++)
	    {
		    for(j=0;j<=30;j++)
		    {
			      fscanf(fp,"%c",&a[i][j]);
			      if(a[i][j]=='\n')
			        a[i][j]='#';
		    }
	    }
	    fclose(fp); 
	}
	
}
void writescore(int pace,int level)
{
	FILE *fp;
	switch(level)
	{
		case 1: fp=fopen("D:\\maps\\map1.txt","a"); break;
		case 2: fp=fopen("D:\\maps\\map2.txt","a"); break;
		case 3: fp=fopen("D:\\maps\\map3.txt","a"); break;
		case 4: fp=fopen("D:\\maps\\map4.txt","a"); break;
		default:
			break;
	}
    fprintf(fp,"%d ",pace);
	fclose(fp);
}

int main()
{
  printf("There are 4 levels. Please choose one from 1-4.\nLevel:");
  scanf("%d",&s);
  for(i=0;i<=10;i++)
  {
		for(j=0;j<=30;j++)
		{
			a[i][j]='\0';
		}
  }
  Readmap(s);
  a[m][n]='i';
  a[m+2][n+2]='o';
  a[m+2][n+1]='o';
  a[0][28]='p'; 
  a[1][27]='p';
  while(a[0][28]!='o'||a[1][27]!='o')
  {
	maze();
	system("cls");
  }
  printf("Congratulations!You make it!\nYou moved %d paces.",p);
  writescore(p,s);
  return 0;
}
