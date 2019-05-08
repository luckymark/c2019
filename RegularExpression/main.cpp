#include"head.h"
int main()
{
	char s1[10],s2[10];
	scanf("%s %s",s1,s2);
	if(match(s1,s2))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
