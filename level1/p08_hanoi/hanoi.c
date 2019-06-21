#include <stdio.h>

void ShowAns(int n, int Start, int Target);

int main(void)
{
	#ifdef LOCAL
	freopen("hanoi.in", "r", stdin);
	freopen("hanoi.out", "w", stdout);
	#endif
	int n, start, target;
	while(scanf("%d%d%d", &n, &start, &target)==3 && n 
	&&target && start )
	{
		if(start<1 || start>3 || target<1 || target>3)
			printf("Wrong input!\n");
		else if (target== start)
			printf("No need to move!\n");
		else
		{
			printf("Solution:\n");
			ShowAns(n, start, target);
		}	
	}
	
	return 0;
}
//function 1
void ShowAns(int n, int Start, int Target)
{
	int i= 6-Start-Target;
	if (n==1)
		printf("Move block 1 from pillar %d to the pillar %d\n", 
	Start, Target);
	else
	{
		ShowAns(n-1, Start, i);
		printf("Move block %d from pillar %d to the pillar %d\n",
		n, Start, Target);
		ShowAns(n-1, i, Target);
	}

}
	
