#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5      //��Կ
int main()
{
    char password[50];
    int i,count;
    printf("��������Ҫ���ܵ����룺");
    gets(password);
    count = strlen(password);
    for(i = 0;i < count;i++)
    {
        password[i] = password[i] + i + N;
    }
    system("cls");
    printf("���ܺ������Ϊ��%s\n",password);
    printf("���������������\n");
    system("pause");
    for(i = 0;i < count;i++)
    {
        password[i] = password[i] - i - N;
    }
    printf("���ܺ������ǣ�%s",password);
    return 0;
}
