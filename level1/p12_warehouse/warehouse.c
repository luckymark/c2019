//Reopen with GB2312
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define true 1
#define false 0
struct Product
{
    char *name;
    int count;
};
Product **list;
int listLength;

int init();
int save();
int showList();
Product *searchProductByName(char *name);
int searchProduct(char *name);
int stockNewItem(Product *p);

int main()
{
    init();
    char str[1023];
    while (true)
    {
        int operate, isNew = 0;
        printf("1.��ʾ����б�\n2.���\n3.����\n4.�˳�\n��������Ų��س�ѡ���ܣ�");
        scanf("%d", &operate);
        system("cls");
        if (operate == 1)
        {
            showList();
        }
        else if (operate == 2 || operate == 3)
        {
            int count;
            printf("��������Ʒ�ͺ�:");
            scanf("%s", str);
            Product *p = searchProductByName(str);
            if ((p == NULL || p->count == 0) && operate == 3)
            {
                printf("����ʧ�ܣ��ֿ���û������ͺţ�\n");
            }
            else
            {
                printf("������%s����Ʒ����(��ǰ��棺%d):", operate == 2 ? "�����" : "Ҫ����", p != NULL ? p->count : 0);
                scanf("%d", &count);
                if (p == NULL)
                    (p = (Product *)malloc(sizeof(Product)), isNew = true);
                else
                    count = p->count + (operate == 2 ? 0 + count : 0 - count), isNew = false;
                if (count < 0)
                {
                    printf("����ʧ�ܣ��ֿ�û����ô��Ŀ�棡\n");
                }
                else
                {
                    char *str_ = (char *)malloc(sizeof(char) * (strlen(str) + 1));
                    strcpy(str_, str);
                    p->name = str_;
                    p->count = count;
                    if (isNew ? stockNewItem(p) : true)
                        printf("�����ɹ���\n");
                    else
                        printf("����ʧ�ܣ�\n");
                }
            }
        }
        else if (operate == 4)
        {
            save();
            return 0;
        }
        printf("���»س�������...");
        getchar();
        getchar();
        system("cls");
    }

    return 0;
}
int init()
{
    char length_[20];
    int i;
    FILE *f;
    f = fopen("warehouse.ini", "rb");
    fscanf(f, "LENGTH:%s", length_);
    listLength = atoi(length_);
    list = (Product **)malloc(sizeof(Product **) * listLength);
    for (i = 0; i < listLength; i++)
    {
        Product *p = (Product *)malloc(sizeof(Product));
        char *name = (char *)malloc(sizeof(char) * 30), count_[30];
        fscanf(f, "%s", name);
        fscanf(f, "%s", count_);
        p->name = name;
        p->count = atoi(count_);
        list[i] = p;
    }
    fclose(f);
}
int save()
{
    FILE *f;
    char str[999], temp[999];
    int i;

    f = fopen("warehouse.ini", "w+");
    fprintf(f, "LENGTH:%d\n", listLength);
    for (i = 0; i < listLength; i++)
    {
        fprintf(f, "%s %d\n", list[i]->name, list[i]->count);
    }
    fclose(f);
}
int showList()
{
    int i;
    for (i = 0; i < listLength; i++)
    {
        if (list[i]->count != 0)
        {
            printf("%s - %d\n", list[i]->name, list[i]->count);
        }
    }
}
Product *searchProductByName(char *name)
{
    int i = searchProduct(name);
    return i == -1 ? NULL : list[i];
}
int searchProduct(char *name)
{
    int i;
    for (i = 0; i < listLength; i++)
    {
        if (strcmp((list[i]->name), (name)) == 0)
        {
            char *test = list[i]->name;
            return i;
        }
    }
    return -1;
}
int stockNewItem(Product *p)
{
    listLength++;
    list = (Product **)realloc(list, sizeof(Product *) * listLength);
    list[listLength - 1] = p;
    return true;
}
