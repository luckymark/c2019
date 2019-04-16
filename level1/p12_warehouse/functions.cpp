#include"warehouse.h"
void display()
{
	printf("Goods List:\n");
	int i;
	for(i=0;i<N;i++)
	{
	    printf("%s:%d\n",g[i].a,g[i].num);
	}

}
void in()
{
	int i,t;
	char c[5];
	scanf("%s",c);
	scanf("%d",&t);
	for(i=0;i<N;i++)
	{
		if(0==strcmp(c,g[i].a))
		{
			g[i].num+=t;
			break;
		}
	}
}
void out()
{
	int i,t;
	char c[5];
	scanf("%s",c);
	scanf("%d",&t);
    for(i=0;i<N;i++)
    {
	    if(0==strcmp(c,g[i].a))
	    {
			if(g[i].num<t)
			{
				printf("No more than %d.\n",t);
				break;
			}
			else
			{
			    g[i].num-=t;
			    break;
			}
	    }
	}
}
void quit()
{
	 ;
}

