#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char password[50];
    char miwen[50];
    int i,order,count;
    printf("����1��������루18λ��ĸ�����ܽ��ܣ�����q�˳�����\n");
    while(1){
        printf("����1�������ģ�����2�Ըոյ����Ľ��н��ܣ�����3�˳�����\n");
        scanf("%d",&order);

        if(order==1){
            printf("��������Ҫ���ܵ����ģ�\n");
            scanf("%s",&password);
            count=strlen(password);
            for(i=0;i<=count;i++)
                miwen[i]=password[i]+2*i+1;
            printf("���ܺ������Ϊ��%s\n",miwen);

        }
        else if(order==2){
            count=strlen(miwen);
            for(i=0;i<=count;i++)
                password[i]=miwen[i]-2*i-1;
            printf("���ܺ������Ϊ��%s\n",password);
        }
        else if(order==3)
            break;

    }

    return 0;
}
