#include<iostream>
using namespace std;
int main()
{
	long long in1=0;
	unsigned long long in=0,times=2;
	cout<<"请输入你需要判断的数x 1<x<18446744073709551615"<<endl;
	cin>>in;
	if(in1<=2||in1!=(int)in1)
	{
		cout<<"输入有误！"<<endl;
		return 0;
	}
	in=in1;
	for(times;times<in;times++)
	{
		if(in%times==0)
		{
			cout<<"不是质数！";
			return 0;
		}
	}
	cout<<"是质数！"; 
	return 0;
}

