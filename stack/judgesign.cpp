#include"dec.h"
int judgesign(char ci)
{
	int i;
	for(i=0;i<strlen(signs);++i)
		if(signs[i]==ci)
			return 1;
	return 0;
}
