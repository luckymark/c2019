#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

void DrawMap(int mapz[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            //if  else  switch
            switch (mapz[i][j])
            {
            case 0:
                printf(" ");
                break;
            case 1:
                printf("#");
                break;
            case 2:
                printf("*");
                break;
            case 3:
                printf("$");
                break;
            case 4:
                printf("@");  //4人
                break;
            }
        }
        printf("\n");
    }}


void PlayGame(int mapz[8][8])
{
    int r, c;  //人的下标  //
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (mapz[i][j] == 4)   //i j 人的下标?
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
        if (mapz[r - 1][c] == 0||mapz[r - 1][c] == 2)
        {
            mapz[r - 1][c]  =4;
            mapz[r][c]  = 0;
        }
        else if (mapz[r - 1][c] == 3 && mapz[r - 2][c] == 2)
        {

                mapz[r - 2][c] = 3;
                mapz[r - 1][c] = 4;
                mapz[r][c]  = 0;
        }
        else if (mapz[r - 1][c] == 3 && mapz[r - 2][c] == 0)
        {

                mapz[r - 2][c] = 3;
                mapz[r - 1][c] = 4;
                mapz[r][c]  = 0;
        }

        break;

    case 'S':
    case 's':
        if (mapz[r + 1][c] == 0||  mapz[r + 1][c] == 2)
        {
            mapz[r + 1][c]  = 4;
            mapz[r][c]  = 0;
        }
        else if (mapz[r + 1][c] == 3 && mapz[r+ 2][c] == 2)
        {
                mapz[r + 2][c] = 3;
                mapz[r + 1][c] = 4;
                mapz[r][c]  = 0;

        }
        else if (mapz[r + 1][c] == 3 && mapz[r+ 2][c] == 0)
        {
                mapz[r + 2][c] = 3;
                mapz[r + 1][c] = 4;
                mapz[r][c]  = 0;

        }
        break;

    case 'A':
    case 'a':
        if (mapz[r ][c - 1] == 0 || mapz[r ][c - 1] == 2 )
        {
            mapz[r ][c - 1] = 4;
            mapz[r][c]  = 0;
        }
        else if (mapz[r][c - 1] == 3 && mapz[r][c - 2] == 2)
        {
                mapz[r ][c - 2] = 3;
                mapz[r ][c - 1]  = 4;
                mapz[r][c] = 0;
        }
        else if (mapz[r][c - 1] == 3 && mapz[r][c - 2] == 0)
        {
                mapz[r ][c - 2] = 3;
                mapz[r ][c - 1]  = 4;
                mapz[r][c] = 0;
        }
        break;

    case 'D':
    case 'd':
        if (mapz[r][c + 1] == 0||mapz[r][c + 1] == 2)
        {
            mapz[r][c + 1] = 4;
            mapz[r][c] = 0;
        }
        else if (mapz[r][c + 1] == 3 && mapz[r][c + 2] == 2)
        {
                mapz[r][c + 2] = 3;
                mapz[r][c + 1]  =4;
                mapz[r][c]  = 0;
        }
        else if (mapz[r][c + 1] == 3 && mapz[r][c + 2] == 0)
        {
                mapz[r][c + 2] = 3;
                mapz[r][c + 1]  =4;
                mapz[r][c]  = 0;
        }
        break;
    }
}

int main()  //主函数
{   int gamenum =  3;
  while(--gamenum){
    int aw =0;
    int mapz[8][8];
    char as[64];
    int a[64];
    FILE *fpRead;
    if(gamenum == 1)       fpRead = fopen("D:/a1.txt","r");
    else if(gamenum == 2)   fpRead = fopen("D:/a2.txt","r");
    else                    fpRead = fopen("D:/a3.txt","r");
    for(int p=0;p<64;p++)
    {
        fscanf(fpRead,"%c",&as[p]);
        a[p] = (int)as[p] - '0';
    }
    fclose(fpRead);
    for(int p = 0;p<64;p++){
        mapz[aw][p%8] = a[p];
        if(p%8 == 7){
            aw++;
        }}
    while (1)
    {
        int flag = 0;
        system("cls");
        DrawMap(mapz);
        PlayGame(mapz);
        for(int i = 0;i<8;i++){
            for(int j =0;j<8;j++)
                if(mapz[i][j] == 2)
                    flag = 1;
        }
        if(flag == 0)break;
    }
    }
    return 0;
}
