#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    FILE *fp = NULL;
    char buff[9999];
    printf("请选择操作：\n1.显示存货列表\n2.出库\n3.入库\n4.关闭文件");
    while(1){
    printf("\n");
    scanf("%d",&a);
    switch (a){
    case 1:
         fp = fopen("D:/a1.txt","r");
         int i = 1;
         while(fgets(buff, 25, (FILE*)fp)){
            printf("%d: %s",i++,buff );
         }
         fclose(fp);
         break;
    case 2:
        printf("选择需要删除的行数:\n");
        int h;
        scanf("%d",&h);
        fp = fopen("D:/a1.txt","r");
        int p = 1;
         while(fgets(buff, 25, (FILE*)fp)){
            if(p == h){
                printf("*\n");
                p++;
            }
            else
            printf("%d: %s",p++,buff );
         }
         fclose(fp);
         break;

    case 3:
        fp = fopen("D:/a1.txt", "a+");
        //fprintf(fp, "This is testing for fprintf...\n");
        char str[500];
        scanf("%s",str);
        fputs("\n",fp);
        fputs(str,fp);
        fclose(fp);
        break;
    case 4:
        fclose(fp);
        break;
        default :break;
    }
    }
    return 0;
}
