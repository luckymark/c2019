#include <stdio.h>  
#include <conio.h>
#include<stdlib.h> 

int map[9][11];
void fscan()
{
	FILE* fp=fopen("file.txt","r");
        if(fp==NULL)
        {
            printf("无文件");
            return ;
        }
	for(int i=0;i<9;i++)
        {
                for(int j=0;j<11;j++)
                {
                    fscanf(fp,"%d",&map[i][j]);
                }
        }
	fclose(fp);
}

void fprint(int score)
{
	FILE* fp=fopen("score1.txt","w");
	if(fp==NULL){
		printf("打开文件失败.");
		return;
	}
	fprintf(fp,"本关分数为: ");
	fprintf(fp,"%d\n",score);
	fclose(fp);
}

void DrawMap()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            switch (map[i][j])
            {
            case 0:
                printf("  ");
                break;
            case 1:
                printf("■");
                break;
            case 3:
                printf("☆");
                break;
            case 4:
                printf("□");
                break;
            case 5:
                printf("♀");  
                break;
            case 7:    
                printf("★");
                break;
            case 8:    
                printf("♀");
                break;
            }
        }
        printf("\n");
    }
}


void PlayGame()
{
    int r, c;  
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (map[i][j] == 5||map[i][j]==8) 
            {
                r = i;
                c = j;
            }
        }
    }

    char ch;  
    ch = getch();  
    switch (ch)
    {
    case 'W':  
    case 'w':
    case 72:
        if (map[r - 1][c] == 0|| map[r - 1][c] == 3) 
        {
            map[r - 1][c] += 5;
            map[r][c] -= 5;
        }
        else if (map[r - 1][c] == 4 || map[r - 1][c] == 7)
        {
            if (map[r - 2][c] == 0 || map[r - 2][c] == 3)
            {
                map[r - 2][c] += 4;
                map[r - 1][c] += 1;
                map[r][c] -= 5;
            }
        }



        break;

    case 'S':  
    case 's':
    case 80:
        if (map[r + 1][c] == 0 || map[r + 1][c] == 3)
        {
            map[r + 1][c] += 5;
            map[r][c] -= 5;
        }
        else if (map[r + 1][c] == 4 || map[r+ 1][c] == 7)
        {
            if (map[r + 2][c] == 0 || map[r + 2][c] == 3)
            {
                map[r + 2][c] += 4;
                map[r + 1][c] += 1;
                map[r][c] -= 5;
            }
        }
        break;

    case 'A':
    case 'a':
    case 75:
        if (map[r ][c - 1] == 0 || map[r ][c - 1] == 3)
        {
            map[r ][c - 1] += 5;
            map[r][c] -= 5;
        }
        else if (map[r][c - 1] == 4 || map[r][c - 1] == 7)
        {
            if (map[r ][c - 2] == 0 || map[r ][c - 2] == 3)
            {
                map[r ][c - 2] += 4;
                map[r ][c - 1] += 1;
                map[r][c] -= 5;
            }
        }
        break;

    case 'D':
    case 'd':
    case 77:
        if (map[r][c + 1] == 0 || map[r][c + 1] == 3)
        {
            map[r][c + 1] += 5;
            map[r][c] -= 5;
        }
        else if (map[r][c + 1] == 4 || map[r][c + 1] == 7)
        {
            if (map[r][c + 2] == 0 || map[r][c + 2] == 3)
            {
                map[r][c + 2] += 4;
                map[r][c + 1] += 1;
                map[r][c] -= 5;
            }
        }
        break;
    }
}

int jug()
{
	int flag=0;
	for(int q=0;q<9;q++){
		for(int w=0;w<11;w++){
			if(map[q][w]==4){
				flag++;
			}
		}
	}
	return flag;
}

int main()  
{
	int step=0,score=0;
	fscan();
    while (1)
    {
        system("cls");
        DrawMap();
        if(jug()==0){
        	printf("恭喜过关!");
        	step/=2;
        	if(step<=15){
        		score=5;
			}else if(step>15&&step<=20){
				score=4;
			}else if(step>20&&step<=25){
				score=3;
			}else if(step>25&&step<=30){
				score=2;
			}else if(step>30){
				score=1;
			}
			fprint(score);
        	break;
		}
        PlayGame();
        step++;
    }
    return 0;
}

