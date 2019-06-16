#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

char a[11][31]=    {{"# ########################## #"},
	                {"# #           #   # # #   #  #"},              
					{"# # # #########  #  #   # # ##"},
					{"#   # # #        # #  ### #  #"}, 
					{"##### #   ### # ## #  # # ## #"},
					{"#     #   # # #    #  # # #  #"},
					{"# ### # # # # #### #  # # # ##"},
					{"# # # # #   ########  # # #  #"},
					{"#   #   ##              #    #"}, 
					{"##############################"}};
static int m=0,n=1;          //Æðµã 
void change_1()
{
	if(a[m][n]=='#')
	    m++;
	else
	 {
	   a[m][n]='o';
	   a[m+1][n]=' ';
     }
	  
}
		
void change_2()
{
	if(a[m][n]=='#')
	    m--;
	else
	 {
	   a[m][n]='o';
	   a[m-1][n]=' ';
     }
	  
}	

void change_3()
{
	if(a[m][n]=='#')
	    n++;
	else
	 {
	   a[m][n]='o';
	   a[m][n+1]=' ';
     }
	  
}

void change_4()
{
	if(a[m][n]=='#')
	    n--;
	else
	 {
	   a[m][n]='o';
	   a[m][n-1]=' ';
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
	int i,j;
	for(i=0;i<=9;i++)
	{
		for(j=0;j<=30;j++)
		{
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	location();
} 

int main()
{
  a[m][n]='o';
  while(a[0][28]!='o')
  {
	maze();
	system("cls");
  }
  printf("Congratulations!You make it!");
  return 0;
}
