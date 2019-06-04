//
//  main.cpp
//  git.10
//
//  Created by 兼桑 on 2019/4/3.
//  Copyright © 2019 兼桑. All rights reserved.
//

#include<cstdio>
#include<cstdlib>
using namespace std;
int i=13,j=3;//dangqianweizhi
int backcase=0,score=100;
char *s[14][14],act;
void map(int k,FILE *f){
    system("cls");
    for(i=1;i<14;++i)
    {
        for(j=1;j<14;++j)
        {
            fscanf(f,"%s",&*s[i][j]);
            if(*s[i][j]==1)
            {
                if(j==13)
                    printf("■ \n");
                else printf("■ ");
            }
            else if (*s[i][j]==0) printf("□ ");
            else if(*s[i][j]==4) printf("△");//dangqianweizhi
            else if(*s[i][j]==2) printf("⊕");//xiangzi
            else if(*s[i][j]==3) printf("＊");//huiguiweidian
            else printf("※ ");}
    }
}

void mvcase(int i,int j){
    char move_now;
    scanf("%ch",&move_now);
    if(move_now=='w')
    {
        if(*s[i-1][j]==2)
        {
            if(*s[i-2][j]==3)
                backcase+=1;
            else
                *s[i-2][j]=2;
                *s[i-1][j]=4;
        }
        i--;score--;
        return mvcase(i,j);
    }
    else if(move_now=='s')
    {
        if(*s[i+1][j]==2)
        {
            if(*s[i+2][j]==3)
                backcase++;
            else
                *s[i+2][j]=2;
            *s[i+1][j]=4;
        }
        i++;score--;
        return mvcase(i,j);
    }
    else if(move_now=='a')
    {
        if(*s[i][j-1]==2)
        {
            if(*s[i][j-2]==3)
                backcase++;
            else
                *s[i][j-2]=2;
            *s[i][j-1]=4;
        }
        j--;score--;
        return mvcase(i,j);
    }
    else if(move_now=='d')
    {
        if(*s[i][j+1]==2)
        {
            if(*s[i][j+2]==3)
                *s[i][j+2]=2;
                *s[i][j+1]=4;
        }
        j++;score--;
        return mvcase(i,j);
    }
    else if(i==2&&j==12&&backcase==3)
    {
        printf("win!");
        printf("%d",score);
    }
    
}
void move_fobid(){
    
}// 不能移动的情况，懒得写了
int main()
{
    FILE* f=0;
    int k;
    printf("choose level 1~3");
    scanf("%d",&k);
    if(k==1)
        f=fopen("/Users/tiki/map of maze/maze01.rtf","r+");
    else if(k==2)
        f=fopen("/Users/tiki/map of maze/maze02.rtf","r+");
    else if(k==3)
        f=fopen("/Users/tiki/map of maze/maze03.rtf","r+");
    map(k,f);
    mvcase(i,j);
    fprintf(f,"第%d关 %d\n",k,score);
    fclose(f);
}
