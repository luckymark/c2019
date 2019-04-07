//三个柱子A,B,C
//n个圆盘都在A上
//要求把圆盘移到C上去

#include<stdio.h>
#include<stdlib.h>

int m = 0;
FILE *fp;

//把n个圆盘从A移动到C上
//B为辅助塔
void hanoi(int n, char A, char B, char C)
{
        void move(int disk, char post1, char post2);

        if(n == 1)      //递归终止的条件
        {
                move(n, A, C);
                return;
        }
        else
        {
                //第一步，把n-1个盘子从A移动到B
                //C为辅助塔
                hanoi(n-1, A, C, B);
                //第二步，把第n个盘子从A移动到C
                move(n, A, C);
                //第三步，把n-1个盘子从B移动到C
                //A为辅助塔
                hanoi(n-1, B, A, C);
        }
}

//输出：第m步，把当前的盘子从post1移动到post2
void move(int disk, char post1, char post2)
{
        ++m;

        fp = fopen("output.txt", "a");
        if(fp == NULL)
        {
                printf("File \"output.txt\" cannot found.\n");
                exit(EOF);
        }

        fprintf(fp, "第%d步，把第%d个盘子从%c移动到%c\n", m, disk, post1, post2);

        fclose(fp);
}
