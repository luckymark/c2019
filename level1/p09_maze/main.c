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
    printf("��ͼ�������ɣ���ȴ�");
    while(test(&m)!=2);
    system("cls");
    printf("��ͼ������\n");
    printf("w�����ƶ� s�����ƶ� a�����ƶ� d�����ƶ� p�����ȷ·��\n");
    printmaze(&m);
    while(1)
    {
        if(kbhit())
        {
            ch=getch();
            system("cls");
            printf("w�����ƶ� s�����ƶ� a�����ƶ� d�����ƶ� p�����ȷ·��\n");
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
