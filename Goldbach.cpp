#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int isprime(int n)
{
	int flag = 1;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			flag = 0;
			break;
		}
	}
	return flag;
}
int main()
{
	int num[150],j=0,x;
	cin>>x; 
	for(int i=2;i<100;i++){
		if(isprime(i)){
			num[j]=i;
			j++;
		}
	}
	for(int q=0;q<j;q++){
		for(int w=0;w<j;w++){
			if((num[q]<=num[w])&&(num[q]+num[w]==x)){
				printf("%d=%d+%d\n",x,num[q],num[w]);
			}
		}
	}
	cout<<"对于100以内的数，哥德巴赫猜想成立."<<endl; 
	return 0;
}
