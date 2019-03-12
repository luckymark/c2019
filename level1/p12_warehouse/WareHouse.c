#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* DB_PATH = "data.db";

typedef struct good {
    unsigned long id;  // 从1开始，0表示该数据被删除
    char name[20];     // 名称
    int size;          // 型号 0：small，1：medium，2：large
    int count;         // 库存
} good;

good* goods = NULL;
unsigned long dataCount = 0L;  // 数据条数
unsigned long goodsLen = 0L;   // goods长度
unsigned long lastIndex = 0L;  // 最后一条数据的索引 + 1
unsigned long maxId = 0L;

void initConsole();          // 设置控制台样式
void readData();             // 从文件中读取数据
void showMenu();             // 菜单
void printGood(good* good);  // 打印货物
void list();                 // 显示货物列表
void input();                // 添加元素
void output();               // 删除并返回元素
void dumpExit();             // 持久化数据并退出程序
void expandList();           // 扩容

int main() {
    initConsole();
    readData();
    showMenu();
    return 0;
}

void initConsole() { system("color 2"); }

void readData() {
    FILE* fp;
    if (!(fp = fopen(DB_PATH, "r"))) {
        printf("error open file %s\n", DB_PATH);
        return;
    }
    fscanf(fp, "%d", &dataCount);
    // 分配两倍的空间，为添加元素做准备
    if (!(goods = (good*)malloc(2 * dataCount * sizeof(good)))) {
        printf("分配内存空间失败，程序退出！");
        return;
    }
    goodsLen = 2 * dataCount;
    lastIndex = dataCount;
    for (int i = 0; i < dataCount; i++) {
        fscanf(fp, "%d%s%d%d", &goods[i].id, goods[i].name, &goods[i].size,
               &goods[i].count);
    }
    maxId = goods[dataCount - 1].id;
    fclose(fp);
}

void printGood(good* good) {
    char size[10];
    switch (good->size) {
        case 0:
            strcpy(size, "small");
            break;
        case 1:
            strcpy(size, "medium");
            break;
        case 2:
            strcpy(size, "large");
            break;
        default:
            break;
    }
    printf("| %-6d| %-20s| %-10s| %-8d|\n", good->id, good->name, size,
           good->count);
}

void list() {
    system("cls");
    printf("+-------+---------------------+-----------+---------+\n");
    printf("| id    | name                | size      | count   |\n");
    printf("+-------+---------------------+-----------+---------+\n");
    for (int i = 0; i < lastIndex; i++) {
        if (goods[i].id) printGood(&goods[i]);
    }
    printf("+-------+---------------------+-----------+---------+\n");
    printf("press [m] to return to menu\n");
    char ch;
    while (ch = getch()) {
        if (ch == 'm') {
            showMenu();
            return;
        }
    }
}

void input() {
    system("cls");
    char name[20];
    int size = 0;
    int count = 0;
    good* tg;
    printf("请输入数据:\n");
    printf("1.货物名称：");
    scanf("%s", name);
    do {
        printf("请输入型号（0表示小，1表示中，2表示大）：");
        scanf("%d", &size);
    } while (!(size == 0 || size == 1 || size == 2));
    do {
        printf("请输入数量：");
        scanf("%d", &count);
    } while (count < 0);
    if (goodsLen == lastIndex) expandList();
    tg = &goods[lastIndex++];
    tg->id = ++maxId;
    strcpy(tg->name, name);
    tg->size = size;
    tg->count = count;
    dataCount++;
    printf("添加成功！\n");
    printf("press [m] to return to menu\n");
    printf("press [c] to continue");
    char ch;
    while (ch = getch()) {
        if (ch == 'm') showMenu();
        if (ch == 'c') input();
    }
}

void output() {
    system("cls");
    int success = 0;
    unsigned long id;
    do {
        printf("请输入要出库的货物的id：");
        scanf("%d", &id);
    } while (id < 0);
    for (int i = 0; i < lastIndex; i++) {
        if (id == goods[i].id) {
            success = 1;
            char size[10];
            switch (goods[i].size) {
                case 0:
                    strcpy(size, "small");
                    break;
                case 1:
                    strcpy(size, "medium");
                    break;
                case 2:
                    strcpy(size, "large");
                    break;
                default:
                    break;
            }
            goods[i].id = 0;
            dataCount--;
            printf("出库成功!出库货物信息为：\n");
            printf("name: %s\t size: %s\t count: %d\n", goods[i].name, size,
                   goods[i].count);
        }
    }
    if (!success) printf("未找到id为%d的货物\n", id);
    printf("press [m] to return to menu\n");
    printf("press [c] to continue");
    char ch;
    while (ch = getch()) {
        if (ch == 'm') showMenu();
        if (ch == 'c') output();
    }
}

void dumpExit() {
    // dump
    FILE* fp;
    if (!(fp = fopen(DB_PATH, "w+"))) {
        printf("error open file %s\n", DB_PATH);
        return;
    }
    fprintf(fp, "%d\n", dataCount);
    for (int i = 0; i < lastIndex; i++) {
        // id不为0说明该记录没有被删除
        if (goods[i].id) {
            fprintf(fp, "%d %s %d %d\n", goods[i].id, goods[i].name,
                    goods[i].size, goods[i].count);
        }
    }
    fclose(fp);

    // exit
    if (goods) free(goods);
    goods = NULL;
    exit(0);
}

void showMenu() {
    system("cls");
    char ch;
    printf("[1] 显示存货列表\n");
    printf("[2] 入库\n");
    printf("[3] 出库\n");
    printf("[q] 退出程序\n");

    while (ch = getch()) {
        switch (ch) {
            case '1':
                list();
                break;
            case '2':
                input();
                break;
            case '3':
                output();
                break;
            case 'q':
                dumpExit();
                break;
            default:
                break;
        }
    }
}

void expandList() {
    good* newGoods;
    if (!(newGoods = (good*)malloc(2 * goodsLen * sizeof(good)))) {
        printf("扩容时分配内存空间失败，程序退出！");
        return;
    }
    for (int i = 0; i < dataCount; i++) {
        newGoods[i].id = goods[i].count;
        strcpy(newGoods[i].name, goods[i].name);
        newGoods[i].size = goods[i].size;
        newGoods[i].count = goods[i].count;
    }
    free(goods);
    goods = newGoods;
    newGoods = NULL;
    goodsLen = 2 * goodsLen;
}
