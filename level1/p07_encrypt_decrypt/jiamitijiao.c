#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5      //秘钥
int main()
{
    char password[50];
    int i,count;
    printf("请输入需要加密的密码：");
    gets(password);
    count = strlen(password);
    for(i = 0;i < count;i++)
    {
        password[i] = password[i] + i + N;
    }
    system("cls");
    printf("加密后的密码为：%s\n",password);
    printf("按下任意键来解密\n");
    system("pause");
    for(i = 0;i < count;i++)
    {
        password[i] = password[i] - i - N;
    }
    printf("解密后密码是：%s",password);
    return 0;
}
