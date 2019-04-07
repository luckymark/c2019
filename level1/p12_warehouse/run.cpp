#include"myhead.h"
int scan()
{
	ifstream infile("data.txt");
	int i = 1;
	for (;infile!=NULL;i++)
	{
		infile >> good[i].order;
		infile >> good[i].name >> good[i].num;
	}
	infile.close();
	return i - 1;
}
void my_print(int all)
{
	cout<<"现在仓库里面有如下库存"<<endl;
	for (int i = 1;i<=all; i++)
	{
		if (good[i].order == 0)break;
		else if (good[i].order == 2)continue;
		cout << i << " " << good[i].name << " " << good[i].num <<"件"<< endl;
	}
	cout << "如果需要入库或出库请输入1 需要创建新项目请输入2 需要删除项目请输入3 退出请输入4"<<endl;
	cout<<"退出时请输入4退出 否则会导致数据丢失"<<endl;
}
void save(int all)
{
	ofstream outfile("data.txt");
	for (int i = 1;i<=all; i++)
	{
		if (good[i].order == 2)continue;
		outfile << good[i].order << " " << good[i].name << " " << good[i].num << endl;
	}
	outfile.close();
}
void in()
{
	int x = 0, nums = 0, times = 0, in_out = 0;;
	cout << "输入1入库 输入2出库" << endl;
	cin >> times;
	if (times == 2)in_out = -1;
	else in_out = 1;
	cout << "请输入您需要入/出库物品的序号" << endl;
	cin >> x;
	cout << "请输入您需要入/出库物品的数量" << endl;
	cin >> nums;
	good[x].num += (nums*in_out);
}
int create(int all)
{
	good[all].order = 1;
	cout << "请输入该物品名称" << endl;
	cin >> good[all].name;
	cout << "请输入数量" << endl;
	cin >> good[all].num;
	cout << "创建完成" << endl;
	cout<<all<<endl;
	cout<<good[all].name<<" "<<good[all].num<<endl;
	return all + 1;
}
int my_remove(int all)
{
	int x = 0;
	cout << "请输入该物品的序号" << endl;
	cin >> x;
	good[x].order = 2;
	return all - 1;
}
