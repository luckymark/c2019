/*
这个问题只有一个疑问，就是如何删除文件中指定的一行，这里给出的是，先判断要删除哪一行，然后把文件这行前的数据都存入另一个中
然后再跳过这一行，再把文件剩下的东西给存到这个文件里，最后我们再用这个文件覆盖原文件。
*/
#include<iostream>
#include<conio.h>
using namespace std;
int n=0;
FILE* o,*i;
void print() {
	if (n == 0) { printf("库中没有任何东西"); return;}
	char name[100];
	int sort, num;
	o = fopen("products.txt", "r");
	for (int i = 1; i <= n; i++) {
		fscanf(o, "%s", name);
		fscanf(o, "%d %d", &sort, &num);
		printf("%s %d %d\n", name, sort, num);
	}
	fclose(o);
}
void insert(char* s,int sort,int num) {
	i = fopen("products.txt", "a");
	fprintf(i, "%s %d %d\n", s, sort, num);
	n++;
	fclose(i);
}
void outcage(char s[]) {
	FILE *a, *b;
	char name[50];
	int sort, num;
	a = fopen("products.txt", "r");
	b = fopen("temp.txt", "w+");
	for (int i = 1; i <= n; i++) {
		fscanf(a, "%s %d %d", &name, &sort, &num);
		if (strcmp(name, s) !=0) {
			fprintf(b, "%s %d %d\n", name, sort, num);
		}
	}
	fclose(a);
	fclose(b);
	a = fopen("products.txt", "w");
	b = fopen("temp.txt", "r");
	n--;
	for (int i = 1; i <= n; i++) {
		fscanf(b,"%s %d %d", &name, &sort, &num);
		fprintf(a, "%s %d %d", name, sort, num);
	}
	fclose(b);
	b = fopen("temp.txt", "w");
	fclose(a);
	fclose(b);
}
int main() {
	char c;
	char name[100];
	int num, sort;
	while (1) {
		cout << "下面是您可以进行的操作\n" << "1.显示存库列表\n" << "2.入库\n" << "3.出库\n" << "4.退出程序";
		c = getch();
		if (c == '1') {
			system("cls");
			print();
			c = getch();
			system("cls");
			continue;
		}
		if (c == '2') {
			system("cls");
			cout << "请输入您想要入库的产品名称、数量、和型号\n";
			cin >> name;
			scanf("%d %d",&sort, &num);
			insert(name, sort, num);
			system("cls");
			cout << "该物品已经被放入库存中啦";
			c = getch();
			system("cls");
			continue;
		}
		if (c == '3') {
			system("cls");
			cout << "请输入您想要出货的物品名称\n";
			cin >> name;
			system("cls");
			outcage(name);
			cout << "该物品已经出货啦";
			c = getch();
			system("cls");
			continue;
		}
		if (c == '4') {
			system("cls");
			cout << "谢谢您对本系统的使用";
			break;
		}
	}
	return 0;
}