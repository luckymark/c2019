int Goldbach(int x)
{
	int a[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	int i_1,i_2;
	int w=0;
	
	for(i_1=0;i_1<=24;i_1++)
	{
		for(i_2=0;i_2<=24;i_2++)
		{
			if(x==a[i_1]+a[i_2])
			{
				printf("%d=%d+%d\n",x,a[i_1],a[i_2]);
				w++;
			}
		}
	}
	
	if(w==0)
	{
		printf("Goldbach for %d is wrong!",x);
	}
}

