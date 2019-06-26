#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	float x;
	for(x=1;x<=100;x++)
	{
		if(x*1/6+x*1/12+x*1/7+5+0.5*x+4==x)
		{
			printf("µ±Ê±¶ª·¬Í¼%.0fËê\n",x-4);
		}
	}
	system("pause");
	return 0;
}