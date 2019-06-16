#include <stdio.h>
#include <io.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

struct student
{
	char no[10];  // 学号
	char name[50]; // 姓名
	float score[3];      // 分数
	float math;
	float eng;
};
struct data
{
	int count;   // 当前学生数组中学生的个数
	struct student stu[MAX]; // 学生数组
}dd;

// 显示主菜单
void menu()
{
	system("cls");//清屏 
	printf("\n\n\n");
	printf("\t\t\t  *******************************\n");
	printf("\t\t\t                              \n");
	printf("\t\t\t     仓库管理系统       \n");
	printf("\t\t\t                             \n");
	printf("\t\t\t    [1]   显示存货列表      \n");
	printf("\t\t\t    [2]   入库        \n");
	printf("\t\t\t    [3]   出库         \n");
	printf("\t\t\t    [0]   退出程序                 \n");
	printf("\t\t\t                             \n");
}

// 等待用户按回车后回到主菜单
void to_menu()
{
	char c1, c2;
	printf("\n\n\n按回车键返回主菜单...");
	scanf("%c%c", &c1, &c2);//第一个字符吸收上次的确认回车键 
	menu();
}

// 显示存货列表
void view_data()
{
	int i;
	printf("货号\t名称\t数量\t单价");
	printf("\n-------------------------------------------------------------------\n");
	for (i = 0; i < dd.count; i++)
		printf("%s\t%s\t%-7.1f\t%-7.1f\n", dd.stu[i].no, dd.stu[i].name, dd.stu[i].math, dd.stu[i].eng);
	printf("\n-------------------------------------------------------------------\n");
}


// 将数据从结构体数组保存到文件中
void save_data()
{
	FILE* fp;//文件指针 
	int i, k;
	k = dd.count; //其实k没有什么实际的意义，直接在fwrite里使用&dd.count就可以了。
	fp = fopen("D:\\data.txt", "w");//文件存储位置：当前文件夹 
	fwrite(&k, sizeof(int), 1, fp);
	for (i = 0; i < dd.count; i++)
		fwrite(&dd.stu[i], sizeof(struct student), 1, fp);
	fclose(fp);
}

// 入库
void add_data()
{
	int b;
	int k = dd.count;
	while (k < MAX)
	{
		printf("请输入货号：");  scanf("%s", dd.stu[k].no);
		printf("请输入货物名称：");  scanf("%s", dd.stu[k].name);
		printf("请输入货物数量：");  scanf("%f", &dd.stu[k].math);
		printf("请输入货物单价：");  scanf("%f", &dd.stu[k].eng);

		dd.count++; //需要提前置0，在主函数中。
		k = dd.count;
		printf("\n\n继续添加货物信息[1-yes 0-no]:");
		scanf("%d", &b);
		if (b == 0) break;
	}
	save_data();
}

// 将数据从文件读到结构体数组中
void read_data()
{
	FILE* fp;
	int i, k;

	k = 0;
	if ((fp = fopen("D:\\data.txt", "r")) == NULL) // 如果文件不存在
	{
		dd.count = 0;
	}
	else
	{
		fread(&k, sizeof(int), 1, fp);
		dd.count = k;
		for (i = 0; i < k; i++)
		{
			fread(&dd.stu[i], sizeof(struct student), 1, fp);
		}
		fclose(fp);
	}
}

// 出库
void delete_data()
{
	int i, k;
	char no[10];
	printf("\n请输入出库货物编号:");
	scanf("%s", no);
	k = -1;
	for (i = 0; i < dd.count; i++)
	{
		if (strcmp(dd.stu[i].no, no) == 0)
		{
			k = i;
			break;
		}
	}
	if (k == -1)
	{
		printf("\n\n没有找到该货物(货号-%s)!", no);
	}
	else
	{
		//你没有写删除的操作啊
		for (i = k; i < dd.count - 1; i++)    //将后面的数据前移一位
			dd.stu[i] = dd.stu[i + 1];
		memset(&dd.stu[dd.count - 1], 0, sizeof(struct student));  //将dd.stu[dd.count-1]数据置0
		dd.count--;

		save_data();
		printf("\n\n出库(货号-%s)记录成功!", no);
	}
}

// 主函数
int main()
{
	int fun;
	dd.count = 0;
	read_data();
	menu();
	while (1)
	{
		printf("请输入功能号[0-3]:");//这里不需要什么&fun，
		scanf("%d", &fun);
		switch (fun)
		{
		case 1: view_data(); break;        // 查看所有学生信息 
		case 2: add_data(); break;       // 输入学生记录  
		case 3: delete_data(); break;      // 删除学生记录
		case 0: break;                   // 退出
		}
		if (fun == 0) break;
		to_menu();
	}

	return 0;
}

