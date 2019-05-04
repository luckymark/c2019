#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 1000
int main(void)
{
	int flag[MAX+3];
	int Prime[MAX+3];
	int i, j, pos=0;
	
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
	
	for (i=0; i<pos; i++)
		printf("%d\n", Prime[i]);
	
	printf("%.4f", (double)clock()/CLOCKS_PER_SEC);
	return 0;
	
}