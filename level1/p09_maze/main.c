#include"maze.c"
#include"userinput.c"
int test(pmaze m)
{
    position enter;
    enter._x = 1;
    enter._y = 0;
    randommaze(m);
    //printmaze(m);
    antoFootpath(m, enter);
    //printmaze(m);
    return m->_map[Maplong-2][Mapwidth-1];
}

int main()
{
    maze m;
    int frist=1;
    //test(&m);
    printf("地图正在生成，请等待");
    while(test(&m)!=2);
    system("cls");
    printf("地图已生成\n");
    printf("w向上移动 s向下移动 a向左移动 d向右移动 p输出正确路径\n");
    printmaze(&m);
    while(1)
    {
        if(kbhit())
        {
            ch=getch();
            system("cls");
            printf("w向上移动 s向下移动 a向左移动 d向右移动 p输出正确路径\n");
            if(exitmaze(&m))
            {
                system("cls");
                printf("you go out the maze");
                exit(1);
            }
            userinput(&m, ch);
            printmaze(&m);
        }
    }
//   printf("please choose the pattern");
    //  scanf("%d",&n);
    return 0;
}
