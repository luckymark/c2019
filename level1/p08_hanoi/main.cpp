#include<iostream>
#include<cmath>
using namespace std;
/* 由于我不能很好的理解递归的思想
这里采用数学分析的方法  我们从最底下个盘子往上走
最底下那个盘子只需要移动一次就够了
倒数第二个盘子需要配合最底下盘子移动一次 然后自己归到第三个柱子移动一次 一共2此
而倒数第三个盘子需要配合倒数第二个盘子和倒数第一个盘子移动三次 最后自己移动一次
因此我们可以列出递推式子 即 an=（Sn-1）+1 第n项等于前n项之和加1
不难推得an=2^(n-1)  因此所求Sn=(2^n)-1*/ 
int main()
{
	unsigned long long in,out;
	cout<<"请输入有多少个盘子"<<endl;
	cin>>in;
	out=exp(in*log(2))-1;
	cout<<"需要移动"<<out<<"次";
	return 0;
}

