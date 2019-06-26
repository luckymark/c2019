#include<stdio.h>
#include "maze.h"

void locate(int y, int x);
void hide();

void print_instruction()
{
        hide();
        locate(LINE+1, 0);

        printf("w：上   s：下   a：左   d：右\n");
        printf("q：放弃\n");
        printf("键盘操作，走到右下角的出口即为胜利！\n");
        printf("开始前，请先将输入法调成英文哦~\n");
}
