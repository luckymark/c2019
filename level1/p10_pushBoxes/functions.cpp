#include"declarations.h"
void indir()
{
	while(getch()!=224);
	switch(getch())
	{
		case 72:				//up
		{
			if(map[h*player.m+player.n-h]!='#')
			{
				if(boxpos[h*player.m+player.n-h]!='O')
				{
					boxpos[h*player.m+player.n]=' ';
					--player.m;
					boxpos[h*player.m+player.n]='P';
					++step;
				}
				else
				{
					if(map[h*player.m+player.n-2*h]!='#'&&boxpos[h*player.m+player.n-2*h]!='O')
					{
						boxpos[h*player.m+player.n]=' ';
						--player.m;
						boxpos[h*player.m+player.n]='P';
						boxpos[h*player.m+player.n-h]='O';
						++step;
					}
				}
			}
			break;
		}
		case 75:				//left
		{
			if(map[h*player.m+player.n-1]!='#')
			{
				if(boxpos[h*player.m+player.n-1]!='O')
				{
					boxpos[h*player.m+player.n]=' ';
					--player.n; 
					boxpos[h*player.m+player.n]='P';
					++step;
				}
				else
				{
					if(map[h*player.m+player.n-2]!='#'&&boxpos[h*player.m+player.n-2]!='O')
					{
						boxpos[h*player.m+player.n]=' ';
						--player.n;
						boxpos[h*player.m+player.n]='P';
						boxpos[h*player.m+player.n-1]='O';
						++step;
					}
				}
			}
			break;
		}
		case 77:				//right
		{
			if(map[h*player.m+player.n+1]!='#')
			{
				if(boxpos[h*player.m+player.n+1]!='O')
				{
					boxpos[h*player.m+player.n]=' ';
					++player.n; 
					boxpos[h*player.m+player.n]='P';
					++step;
				}
				else
				{
					if(map[h*player.m+player.n+2]!='#'&&boxpos[h*player.m+player.n+2]!='O')
					{
						boxpos[h*player.m+player.n]=' ';
						++player.n;
						boxpos[h*player.m+player.n]='P';
						boxpos[h*player.m+player.n+1]='O';
						++step;
					}
				}
			}
			break;
		}
		case 80:				//down
		{
			if(map[h*player.m+player.n+h]!='#')
			{
				if(boxpos[h*player.m+player.n+h]!='O')
				{
					boxpos[h*player.m+player.n]=' ';
					++player.m;
					boxpos[h*player.m+player.n]='P';
					++step;
				}
				else
				{
					if(map[h*player.m+player.n+2*h]!='#'&&boxpos[h*player.m+player.n+2*h]!='O')
					{
						boxpos[h*player.m+player.n]=' ';
						++player.m;
						boxpos[h*player.m+player.n]='P';
						boxpos[h*player.m+player.n+h]='O';
						++step;
					}
				}
			}
			break;
		}
		default:printf("Error!\n");
	}
}
void getmap()
{
	char c,tmp[2];
	int dif;
	FILE *mapin;
	S1:printf("Please choose a difficulty(1/2/3):");
	scanf("%d",&dif);
	switch(dif)
	{
		case 1:mapin=fopen("map1.in","r");break;
		case 2:mapin=fopen("map2.in","r");break;
		case 3:mapin=fopen("map3.in","r");break;
		default:
			{
				printf("Error!\n");
				goto S1;
			}
	}
	map[0]='\0';
	boxpos[0]='\0';
	while(1)
	{
		fscanf(mapin,"%c",&c);
		if(c=='.')
			break;
		if(c=='O'||c=='P')
		{
			sprintf(tmp,"%c",c);
			strcat(boxpos,tmp);
			sprintf(tmp," ");
			strcat(map,tmp);
		}
		else
		{
			sprintf(tmp," ");
			strcat(boxpos,tmp);
			sprintf(tmp,"%c",c);
			strcat(map,tmp);
		}
	}
	h=maplength();
	boxpos[h*player.m+player.n]='P';				//(try to find 'P' by calculating the next time!)
	fclose(mapin);
}
int finish()
{
	int i;
	for(i=0;i<strlen(map);++i)
		if(map[i]=='X')
		{
			if(boxpos[i]=='O')
				continue;
			return 0;
		}
	return 1;
}
void cls()
{
	system("cls");
}
int maplength()
{
	int i=0;
	while(1)
	{
		if(map[i]=='\n')
			break;
		++i;
	}
	++i;
	return i;
}
void printmap()
{
	int i=0;
	while(map[i]!='\0')
	{
		if(boxpos[i]=='P'||boxpos[i]=='O')
		{
			putchar(boxpos[i]);
		}
		else
		{
			putchar(map[i]);
		}
		++i;
	}
}
