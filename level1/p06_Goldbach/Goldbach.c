#include<stdio.h>
int main()
{
	int p[110];
	int i,j,ans1,ans2;
	for(i=2;i<=100;i++)p[i]=1;
	for(i=2;i<=100;i++)
	{
       for(j=2*i;j<=100;j=j+i)p[j]=0;
	}
	for(i=2;i<=100;i++)if(i%2==0)
    {
		for(j=2;j<=50;j++)
		if(p[j]&&i-j>1&&p[i-j])
		{
            ans1=j;
            ans2=i-j;
            printf("%d=%d+%d\n",i,j,i-j);
            break;
        }
    }
    return 0;
}
