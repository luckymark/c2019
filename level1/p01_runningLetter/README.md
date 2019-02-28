### 题目：奔跑的字母

### 功能要求：

1. 在console上输出一个字母（或单词）
1. 使该字母或单词，按一定速度从左至右运动
1. 当遇到屏幕边界时反向运动

#include<iostream>
#include<Windows.h>
#define LENGTH 60 
#define TM 60
using namespace std;
int main()
{
	int i=1,k=1;
	while(1)
	{
		for(i;;i+=k)
		{
			for(int j=1;j<i;j++)cout<<" ";
			cout<<"a";
			Sleep(TM);
			system("cls");
			if(i==0||i==LENGTH)k*=-1;
		}
	}
	return 0;
}


