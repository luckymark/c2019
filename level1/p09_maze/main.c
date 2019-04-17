#include<stdio.h>
#include "maze.h"

void print_instruction();
void maze_create(char mymap[LINE][LINE]);
int start(char mymap[LINE][LINE]);
void ending(int result);

int main()
{
        char mymap[LINE][LINE];

        // to create a map
        maze_create(mymap);

        // to print the instructions of the game
        print_instruction();

        // to start the game
        int result = start(mymap);
        //start函数的返回值表示玩家是否顺利通关

        // to end the game
        ending(result);

        return 0;
}
