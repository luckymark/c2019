#include <stdio.h>
#include <string.h>
#define MAXLTH 40
int main(void)
{
	char ar[MAXLTH];
	int i;	
	while (fgets(ar, MAXLTH, stdin)!=NULL 
		&& ar[0] !='\n')
		{
				
			for (i=0; i<strlen(ar); i++)
			
				if(ar[i]!='\n' && ar[i]!=' ')
				ar[i] ^= (char)31+(char)(i%10);
			
				printf("%s",ar);
			
		}
		
	return 0;
}
