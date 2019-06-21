#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct a {
	char name[10];
	int count;
};
struct a product[1000];
int num = 0;

void read()
{
	FILE* fp = fopen("product.txt", "r");
	if (fp == NULL) {
		printf("不能打开文件!\n");
		return;
	}
	int i = 0;
	while (!feof(fp)) {
		fscanf(fp, "%s %d", product[i].name, &product[i].count);
		i++;
	}
	num = i-1;
	fclose(fp);
}

void save()
{
	FILE* fp = fopen("product.txt", "w");
	if (fp == NULL) {
		printf("不能打开文件!\n");
		return;
	}
	for (int i = 0; i < num; i++) {
		fprintf(fp, "%s  %d\n", product[i].name, product[i].count);
	}
	printf("\n操作已保存!\n");
	fclose(fp);
}

void input()
{
	char t[10];
	int tnum,i;
	printf("请输入存入货物的型号:");
	scanf("%s", t);
	for (i = 0; i < num; i++) {
		if (strcmp(product[i].name, t) == 0) {
			printf("请输入商品数量:");
			scanf("%d", &tnum);
			product[i].count = product[i].count + tnum;
			printf("\n该商品的入库量:%d", tnum);
			printf("\n入库后该商品的总量:%d", product[i].count);
			save();
			break;
		}
	}
	if (i == num) {
		strcpy(product[num].name, t);
		printf("\n请输入商品数量:");
		scanf("%d", &tnum);
		product[num].count = tnum;
		printf("\n该商品的入库量:%d", tnum);
		printf("\n入库后该商品的总量:%d", tnum);
		num++;
		save();
	}
	printf("\n是否还想继续入库商品?");
	printf("\n按y继续添加，按n不添加:");
	char choice;
	scanf("\n%c", &choice);
	if (choice == 'y') {
		input();
	}
}

void output()
{
	char str[10];
	int i,tnum;
	printf("\n请输入想要出库商品的型号:");
	scanf("%s", str);
	for (i = 0; i < num; i++) {
		if (strcmp(product[i].name, str) == 0) {
			printf("\n请输入出库商品的数量:");
			scanf("%d", &tnum);
			printf("\n该商品原库存量为:%d", product[i].count);
			if (tnum <= product[i].count) {
				printf("\n出库后该商品的剩余库存量为:%d", product[i].count - tnum);
				product[i].count -= tnum;
				save();
			}
			else {
				printf("\n库存量不足!");
				break;
			}
		}
	}
	if (i == num) {
		printf("\n没有该商品!");
	}
	printf("\n是否还想继续出库商品?");
	printf("\n按y继续出库，按n不继续出库:");
	char choice;
	scanf("\n%c", &choice);
	if (choice == 'y') {
		output();
	}
}

void show()
{
	int i;
	for (i = 0; i < num; i++) {
		printf("商品型号:%s 数量:%d\n", product[i].name, product[i].count);
	}
}

void menu()
{
	printf("菜单功能如下:\n");
	printf("   1.显示存货列表.\n");
	printf("   2.入库.\n");
	printf("   3.出库.\n");
	printf("   4.退出程序.\n");
	printf("请选择你想进行的操作(按对应数字键):");
}
int main()
{
	read();
	menu();
	int c;
	scanf("%d", &c);
	while (c != 4) {
		switch (c) {
		case 1:
			show();
			break;
		case 2:
			input();
			break;
		case 3:
			output();
			break;
		default:
			break;
		}
		printf("\n\n");
		menu();
		scanf("%d", &c);
	}
	printf("数据已保存，退出程序成功!\n");
	return 0;
}