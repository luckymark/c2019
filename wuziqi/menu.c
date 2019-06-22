#include"menu.h"
void menu()
{
    int n;
	printf("帮助:请在控制台左上角鼠标右键选项中调为 旧版控制台，点阵字体10X20或者新宋体28，否则棋盘会很难看\n");
	printf("若选择鼠标输入，请不要移动控制台，分辨率为 1920 X 1080");
    printf("choose the pattern you want \n");
    printf("1:   p V p \n");
    printf("2:   p V computer\n");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
		point = 1;//p V p
        break;
    case 2:
		point = 2;//P V computer
        break;
	case 3:
		point = 3;//娱乐模式AI V AI
    default:
        printf("input wrong number");
		break;
    }
}
