#include"menu.h"
void menu()
{
    int n;
	printf("����:���ڿ���̨���Ͻ�����Ҽ�ѡ���е�Ϊ �ɰ����̨����������10X20����������28���������̻���ѿ�\n");
	printf("��ѡ��������룬�벻Ҫ�ƶ�����̨���ֱ���Ϊ 1920 X 1080");
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
		point = 3;//����ģʽAI V AI
    default:
        printf("input wrong number");
		break;
    }
}
