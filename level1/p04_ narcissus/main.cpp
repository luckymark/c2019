#include<iostream>
using namespace std;
int main()
{
	for(int i=120;i<=999;i++)
	{
		int h=(i-i%100)/100;
		int t=(i%100)/10;
		int o=(i%10);
		if(h*h*h+t*t*t+o*o*o==i)cout<<i<<endl;
	}
	return 0;
}

