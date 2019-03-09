#include<stdio.h>
#include<time.h>
#include<math.h>

int isprime(int n)
{
	int flag = 1;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			flag=0;
			break;
		}
	}
	return flag;
}
int main()
{
	clock_t start,finish;
	double totaltime;
	start=clock();
	for(int i=2;i<=1000;i++){
		if(isprime(i)){
			printf("%d ",i);
		}
	}
	finish=clock();
	totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
	printf("\n\n该程序总的计算时间为%f毫秒。\n",totaltime);
	return 0;
}
