#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
const char rev[]="pqazxswedcvfrtgbnhyujmkiolp";
char encrypt(char a)
{
    int i;
    if(a!=EOF)
    {
        for(i=1;rev[i]&&rev[i]!=a;i++);
        if(rev[i])
            return (rev[i-1]);
    }
}
char decrypt(char a)
{
    int i;
    if(a!=EOF)
    {
        for(i=1;rev[i]&&rev[i]!=a;i++);
        if(rev[i])
            return (rev[i+1]);
    }
}

int main()
{
    char s[100];
    scanf("%s",s);
    int i;
    for(i=0;i<strlen(s);i++)
    {
        s[i]=encrypt(s[i]);
    }
    printf("encrypt %s\n",s);
       for(i=0;i<strlen(s);i++)
    {
        s[i]=decrypt(s[i]);
    }
    printf("decrypt %s\n",s);
    return 0;
}
