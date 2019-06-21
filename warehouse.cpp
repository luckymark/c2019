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
		printf("���ܴ��ļ�!\n");
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
		printf("���ܴ��ļ�!\n");
		return;
	}
	for (int i = 0; i < num; i++) {
		fprintf(fp, "%s  %d\n", product[i].name, product[i].count);
	}
	printf("\n�����ѱ���!\n");
	fclose(fp);
}

void input()
{
	char t[10];
	int tnum,i;
	printf("��������������ͺ�:");
	scanf("%s", t);
	for (i = 0; i < num; i++) {
		if (strcmp(product[i].name, t) == 0) {
			printf("��������Ʒ����:");
			scanf("%d", &tnum);
			product[i].count = product[i].count + tnum;
			printf("\n����Ʒ�������:%d", tnum);
			printf("\n�������Ʒ������:%d", product[i].count);
			save();
			break;
		}
	}
	if (i == num) {
		strcpy(product[num].name, t);
		printf("\n��������Ʒ����:");
		scanf("%d", &tnum);
		product[num].count = tnum;
		printf("\n����Ʒ�������:%d", tnum);
		printf("\n�������Ʒ������:%d", tnum);
		num++;
		save();
	}
	printf("\n�Ƿ�����������Ʒ?");
	printf("\n��y������ӣ���n�����:");
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
	printf("\n��������Ҫ������Ʒ���ͺ�:");
	scanf("%s", str);
	for (i = 0; i < num; i++) {
		if (strcmp(product[i].name, str) == 0) {
			printf("\n�����������Ʒ������:");
			scanf("%d", &tnum);
			printf("\n����Ʒԭ�����Ϊ:%d", product[i].count);
			if (tnum <= product[i].count) {
				printf("\n��������Ʒ��ʣ������Ϊ:%d", product[i].count - tnum);
				product[i].count -= tnum;
				save();
			}
			else {
				printf("\n���������!");
				break;
			}
		}
	}
	if (i == num) {
		printf("\nû�и���Ʒ!");
	}
	printf("\n�Ƿ������������Ʒ?");
	printf("\n��y�������⣬��n����������:");
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
		printf("��Ʒ�ͺ�:%s ����:%d\n", product[i].name, product[i].count);
	}
}

void menu()
{
	printf("�˵���������:\n");
	printf("   1.��ʾ����б�.\n");
	printf("   2.���.\n");
	printf("   3.����.\n");
	printf("   4.�˳�����.\n");
	printf("��ѡ��������еĲ���(����Ӧ���ּ�):");
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
	printf("�����ѱ��棬�˳�����ɹ�!\n");
	return 0;
}