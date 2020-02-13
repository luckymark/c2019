#include<stdio.h>
#include<math.h>
int main()
{
	int x,y,z,w;
	w=0;
	printf("Plesse input a integer:\n");
	scanf("%d",&x);
	y=sqrt(x);
	for(z=2;z<=y;z++)
	{
		if((x/z*z)==x)
		w=1;	
	}
	
	if(w!=0)
	{
		printf("%d is not prime\n",x);
	}
	else
	{
		printf("%d is prime\n",x);
 	}
    return 0;
}
