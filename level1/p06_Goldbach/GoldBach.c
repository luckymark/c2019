#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 100
int bisearch(const int left, const int right, int ar[], const int key);
int main(void)
{
	int flag[MAX+3];
	int Prime[MAX+3];
	int i, j, pos=0;
	int test=0;
	memset(flag, 0, sizeof(flag));
	for (i=2; i<MAX+1; i++)
	{
		if (!flag[i])
			Prime[pos++]=i;
		
		for (j=0; i*Prime[j]<MAX+1 && j<pos; j++)
		{
			flag[i*Prime[j]]=1;
			
			if (0==i%Prime[j])
				break;
		}
		
	}
	
	/*while(1==scanf("%d", &test))
	{
		int a=bisearch(0, pos-1, Prime, test);
		printf("%d & %d\n", a, Prime[a]);
	}*/
	
	for (i=4; i<MAX; i+=2)
	{
		test=0;
		
		int a=bisearch(0, pos-1, Prime, i);
		
		while (a--)
		{
			if (0==(flag[i-Prime[a]]))
			{
				test=1;
				printf("%d:%d\n", i, Prime[a]);
				break;
			}	
		}
		
		if (!test)
			{
				printf("GoldBach is so cai!\n");
				break;
			}
	}
	return 0;
	
}

int bisearch(const int left, const int right, int ar[], const int key)
{
	int mid=(left+right)/2;
	int ans;
	if (left<mid)
	{
		if (key==ar[mid])
			ans=mid;
		else if (ar[mid]>key)
			ans=bisearch(left, mid, ar, key);
		else if (ar[mid]<key)
			ans=bisearch(mid, right, ar, key);
	}
	else 
		ans=mid;
	
	return ans;
}