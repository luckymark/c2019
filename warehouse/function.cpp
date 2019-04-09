#include"head.h"
using namespace std;

struct good
{
	char TYPENAME[50]; //型号
	int NUM; //数量

};
good A[1000];


void read()
{
	fstream out("goods.txt", ios::in|ios::out);

	for(int i=0; !out.eof();i++)
	{
		out >> A[i].TYPENAME>>A[i].NUM;
	}
	
		
}


void print()
{
	system("cls");
	cout << "选择要执行的功能，1：显示存货列表，2：入库，3：出库；4：退出" << endl;

}

void write()
{
	fstream in("goods.txt", ios::in | ios::out | ios::trunc);
	int x = 0;
	while (A[x].TYPENAME[0]!='\0')
	{
		in << A[x].TYPENAME << " " << A[x].NUM<<endl;
		x++;
	}
	in.close();
}

void select_mode()
{
	int x;
	cout << "选择要执行的功能，1：显示存货列表，2：入库，3：出库；4：退出"<<endl;
	while (cin >> x)
	{
		if (x < 1 || x>4)
		{
			cout << "请输入正确的指令";
			continue;
		}
		switch (x)
		{
		case 1:show_list(); break;
		case 2:in_Warehouse(); break;
		case 3:out_Warehouse(); break;
		case 4:write(); return;
		}
	}
}

void show_list()  //显示存货列表
{
	print();
	for (int i = 0; A[i].TYPENAME[0]!= '\0'; i++)
		cout << A[i].TYPENAME << " " << A[i].NUM<<endl;
}

void in_Warehouse()
{
	show_list();
	int x = 1,y=1;
	int num;
	char NAME[50];
	cout << "请输入你要入库的商品名及其数量"<<endl;
	cin >> NAME>>num;
	for (int i = 0; A[i].TYPENAME[0] != '\0'; i++)
		{
			if (strcmp(NAME, A[i].TYPENAME) == 0)
			{
			x = 0;
			A[i].NUM += num;
			cout << strcmp(NAME, A[i].TYPENAME)<<" " <<x << endl;
			}
			y = i;
		}
	if (x)
	{  
		memcpy(A[y].TYPENAME,NAME,sizeof(NAME));
		A[y].NUM = 0;    //先赋值以免出现未赋值出现未知数的情况
		A[y].NUM += num;
	}
}

void out_Warehouse()
{
	show_list();
	int x = 1, y = 1;
	int num;
	char NAME[50];
	cout << "请输入你要出库的商品名及其数量"<<endl;
	cin >> NAME>>num;
	for (int i = 0; A[i].TYPENAME[0] != '\0'; i++)
	{
		if (strcmp(NAME, A[i].TYPENAME) == 0)
		{
			x = 0;
			if (A[i].NUM >= num)
			{
				A[i].NUM -= num;
			}
			else cout << "该商品数量不足，无法出库"<<endl;
			
		}
		y = i;   //记录一下共有多少种商品
	}
	if (x)
	{
		cout << "库内没有这种商品"<<endl;
	}
}