#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char password[50];
    char miwen[50];
    int i,order,count;
    printf("输入1后进行密码（18位字母）加密解密，输入q退出程序\n");
    while(1){
        printf("输入1加密明文，输入2对刚刚的明文进行解密，输入3退出程序：\n");
        scanf("%d",&order);

        if(order==1){
            printf("请输入你要加密的明文：\n");
            scanf("%s",&password);
            count=strlen(password);
            for(i=0;i<=count;i++)
                miwen[i]=password[i]+2*i+1;
            printf("加密后的密文为：%s\n",miwen);

        }
        else if(order==2){
            count=strlen(miwen);
            for(i=0;i<=count;i++)
                password[i]=miwen[i]-2*i-1;
            printf("解密后的密文为：%s\n",password);
        }
        else if(order==3)
            break;

    }

    return 0;
}
