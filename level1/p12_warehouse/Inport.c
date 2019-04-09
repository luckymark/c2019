#include "WareHouse.h"

int Inport()
{

    /*
  *linebuffer：读取文件中的一行存入的缓冲
  *good2: 从文本中读取出的记录
  */
    struct Goods goods, good2;
    char linebuffer[512] = {0};
    int line_len = 0;
    int len = 0;
    FILE *fp;

    for (size_t i = 13; i == 13;)
    {
        printf("\n品名：");
        scanf("%s", &goods.name);
        printf("型号：");
        scanf("%s", &goods.model);
        
        fp = fopen("库存记录.txt", "r+");
        while (fgets(linebuffer, 512, fp))
        {
            line_len = strlen(linebuffer);
            len += line_len;

            sscanf(linebuffer, "%s%s%d", &good2.name, &good2.model, &good2.quantity);
            if (0 == strcmp(goods.name, good2.name) && 0 == strcmp(goods.model, good2.model))
            {
                /* 由于已经找到所需要写的位置，所以需要写位置的“头”*/
                len -= strlen(linebuffer);
                /* 实现文件位置的偏移，为写文件做准备*/
                fseek(fp, len, SEEK_SET);
                goto Rem;
                /*要是找到了已有记录，则直接覆写*/
            }
        }
        fclose(fp);
        fp = fopen("库存记录.txt", "a");
        good2.quantity = 0;
    Rem:
        printf("数量：");
        if (scanf("%d", &goods.quantity))
        {
        }
        else
        {
            printf("输入错误\n");
            fflush(stdin);
            goto Rem;
        }

        fprintf(fp, "\n%s %s %d", goods.name, goods.model, goods.quantity + good2.quantity);

        printf("\n按回车以继续，Esc键退出\n");
        i = getch();
    }
    fclose(fp);
    return 1;
}