#include<stdio.h>

void hide();

void ending(int result)
{
        hide();
        if(result){
                printf("你通关啦！恭喜~\n\n");
        }
        else{
                printf("真可惜，下次加油哦~\n\n");
        }
}
