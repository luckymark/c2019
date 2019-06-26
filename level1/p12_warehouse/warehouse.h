//
// Created by admin on 2019/5/4.
//

#ifndef P12_WAREHOUSE_WAREHOUSE_H
#define P12_WAREHOUSE_WAREHOUSE_H

#endif //P12_WAREHOUSE_WAREHOUSE_H

#define PATH "c:\\Users\\admin\\Desktop\\desk\\C_and_C++\\Level1\\p12_warehouse\\goodsList.txt"

#define TYPE_LEN 10

typedef struct goods{
    char type[TYPE_LEN];
    int num;
    struct goods *next;
}GOODS;
