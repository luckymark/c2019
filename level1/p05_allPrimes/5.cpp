#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//求素数计时 
int main()
{
	int i,d;
	clock_t start,finish;
	double t;
	start=clock();
	for(i=2;i<=1000;i++){
		for(d=2;d*d<=i;d++){
			if(i%d==0)
			break;
		}
		if(d*d>i)
		printf("%d ,",i);
	}
/*	for(i=2;i<=1000;i++){
		for(d=2;d<i;d++){
			if(i%d==0)
			break;
		}
		if(d==i)
		printf("%d, ",i);
	}*/
	finish=clock();
	printf("\n");
	t=(double)(finish-start)/CLOCKS_PER_SEC;
	printf("%f",t);
	system("pause");
	return 0;
} 