#include<iostream>
using namespace std;
void hanio(int,char,char,char);
void move(int,char,char);
unsigned long long times=0;
int main()
{
	int e=0;
	cout<<"请输入盘子数";
	cin>>e;
	if(e>=2)hanio(e,'x','z','y');//从x到z 依赖于y 
	else 
	{
		times++;
		cout<<"把1号盘从a移动到c位置"<<endl;
	}
	cout<<"一共移动了"<<times<<"次"; 
	return 0; 
 } 
void hanio(int n,char from,char to,char depend)
{
	if(n==1)move(1,from,depend);
	else
	{
		hanio(n-1,from,to,depend);//我有时候也不是很能理解这里 不过貌似移动盘子只需要先把其他的从x 到y 再从y 到z就可以了 
		move(n,from,to);
		hanio(n-1,depend,from,to);
	}
}
void move(int n,char from,char to)
{
	cout<<"把"<<n<<"号盘从"<<from<<"移动到"<<to<<"位置"<<endl;
	times++;
}

