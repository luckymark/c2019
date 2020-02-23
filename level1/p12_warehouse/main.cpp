#include"head.h"
int main()
{
	int i,n;
	good a[N];
	n=getdata(a);
	while(i=getchoice())
	{
		switch(i)
		{
			case 1:
			{
				disphouse(a,n);
				system("pause");
				break;
			}
			case 2:
			{
				inhouse(a,&n);
				break;
			}
			case 3:
			{
				outhouse(a,&n);
				break;
			}
			default:printf("Error!\n");
		}
	}
	savedata(a,n);
	return 0;
}
