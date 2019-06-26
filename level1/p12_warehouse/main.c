#include "menu.h"
#include "show.h"
#include "putinto.h"
#include "out.h"
int main()
{
    int n;
    menu();
    scanf("%d",&n);
    while(1)
    {
        switch(n)
        {
        case 1:
            show();
            break;
        case 2:
            putinto();
            break;
        case 3:
            out();
            break;
        case 4:
            printf("goodbye");
            exit(1);
            break;
        default:
            printf("the number is error,please input again");
            break;
        }
        _getch();
        system("cls");
        menu();
        scanf("%d",&n);
    }
    return 0;
}
