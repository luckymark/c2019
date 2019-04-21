#include<stdio.h>
#include "box.h"

void locate(int y, int x);
void hide();

void instruction(){
        printf("\n");
        printf("%s : 玩家\n", PLAYER);
        printf("%s : 箱子\n", BOX);
        printf("%s : 炸弹\n", BOMB);
        printf("按 w s a d 键移动，把所有箱子推到炸弹上吧~\n");
        printf("如果您想重新开始当前关卡，请按 q\n");
        printf("操作前，请先将输入法调成英文哦~\n");
        printf("\n");
        hide();
}
