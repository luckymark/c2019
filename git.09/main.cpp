//
//  main.cpp
//  git.09
//
//  Created by 兼桑 on 2019/4/3.
//  Copyright © 2019 兼桑. All rights reserved.
//

#include<cstdio>
#include<cstdlib>
char a[14][14]={0};
void maze(){
    int i=0,j=0;
    for(i=1;i<=13;++i)
    {
        a[i][1]=1;
        a[i][13]=1;
    }
    for(j=1;j<=13;++j)
    {
        a[1][j]=1;
        a[13][j]=1;
    }
    a[2][10]=a[2][7]=a[2][11]=1;
    a[3][2]=a[3][3]=a[3][4]=a[3][5]=a[3][7]=a[3][8]=1;
    a[4][4]=a[4][8]=a[4][11]=a[4][12]=1;
    a[5][4]=a[5][6]=a[5][8]=a[5][12]=1;
    a[6][4]=a[6][6]=a[6][9]=a[6][10]=a[6][12]=1;
    a[7][6]=a[7][9]=a[7][12]=1;
    a[8][3]=a[8][6]=a[8][8]=a[8][9]=1;
    a[9][3]=a[9][4]=a[9][5]=a[9][6]=a[9][8]=a[9][11]=1;
    a[10][6]=a[10][8]=a[10][9]=a[10][11]=1;
    a[11][2]=a[11][3]=a[11][4]=a[11][6]=a[11][10]=a[11][11]=1;
    a[12][6]=1;
    a[13][3]=3;
    a[2][12]=4;
    for (i=1; i<=13; ++i) {
        for (j=1; j<=13; ++j) {
            if(a[i][j]==1)
            {
                if(j==13)
                    printf("■ \n");
                else printf("■ ");
            }
            else if (a[i][j]==0) printf("□ ");
            else if(a[i][j]==3) printf("△");
            else printf("※ ");
            if(a[i][j]==9) printf("△");
        }
    }
    
}
void move(char act){
    int i=13,j=3;
    while(scanf("%c",&act)==1)
    {
        a[i][j]=9;
        if(act=='w') a[i-1][j]=9;
        else if (act=='s') a[i+1][j]=9;
        else if (act=='a') a[i][j-1]=9;
        else if (act=='d') a[i][j+1]=9;
        a[i][j]=0;
        system("clear");
        maze();
        
        
    }
}
using namespace std;
int main()
{
    char act='1';
    maze();
    printf("now game start! \n△ is where you are now.");
    move(act);
    
}

