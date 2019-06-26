#include"maze.c"
void test()
{
    maze m;
    position enter;
    enter._x = 1;
    enter._y = 0;
    randommaze(&m);
    printmaze(&m);
    Footpath(&m, enter);
    printmaze(&m);
}

int main()
{
    test();

    return 0;
}
