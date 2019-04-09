#include "WareHouse.h"

int main(int argc, char const *argv[])
{
    int option = 0;

    system("color f9");
    system("mode con cols=80 lines=26");

    for (size_t i = 1; i;)
    {
        system("cls");
        printf(
            "                           ╔══════════╗\n"
            "                           ║                    ║\n"
            "                           ║   请输入数字选择   ║\n"
            "                           ║                    ║\n"
            "                           ║  1 - 显示存货列表  ║\n"
            "                           ║  2 - 入库          ║\n"
            "                           ║  3 - 出库          ║\n"
            "                           ║  4 - 退出程序      ║\n"
            "                           ║                    ║\n"
            "                           ╚══════════╝\n");
        
        //scanf("%d", &option);
        option = getch();
        switch (option - 48)
        {
        case 1:
            printf("显示存货列表：\n");
            i = Print();
            break;

        case 2:
            printf("入库：\n");
            i = Inport();
            break;

        case 3:
            printf("出库：\n");
            i = Outport();
            break;

        case 4:
            i = 0;
            break;

        default:
            printf("输入错误\n");
            system("pause");
            break;
        }
    }
    return 0;
}
