#include "WareHouse.h"

int Print()
{
    struct Goods goods;
    FILE *fp;

    fp = fopen("库存记录.txt", "r");
    while (fscanf(fp, "%s%s%d", &goods.name, &goods.model, &goods.quantity) != EOF)
    {
        printf("\n品名：%s  型号：%s  数量：%d", goods.name, goods.model, goods.quantity);
    }
    fclose(fp);
    printf("\n");
    system("pause");
    return 1;
}