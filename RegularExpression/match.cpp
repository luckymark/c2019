#include"head.h"
bool jfirst(char s1[],char s2[]);
bool jlast(char s1[],char s2[]);
bool jstar(char s1[],char s2[],int i);
bool jdot(char s1[],char s2[]);
bool match(char s1[],char s2[])
{
	int i;
	if(s1[0]=='^')
		if(!jfirst(s1,s2))
			return false;
	if(s1[strlen(s1)-1]=='$')
		if(!jlast(s1,s2))
			return false;
	for(i=0;i<strlen(s1);i++)
	{
		switch(s1[i])
		{
			case '*':
				{
					if(!jstar(s1,s2,i))
						return false;
					break;
				}
			case '.':
				{
					if(!jdot(s1,s2))
						return false;
					break;
				}
			default:;
		}
	}
	return true;
}
bool jfirst(char s1[],char s2[])
{
	for(int i=1;i<strlen(s1);i++)
	{
		if(s2[i-1]!=s1[i])
			return false;
	}
	return true;
}
bool jlast(char s1[],char s2[])
{
	int n=strlen(s2);
	for(int i=strlen(s1)-2;i>=0;i--)
	{
		n--;
		if(s1[i]!=s2[n])
			return false;
	}
	return true;
}
bool jstar(char s1[],char s2[],int i)
{
	int n=i+1;
	for(int j=0;n<strlen(s2);j++)
	{
		while(s2[j]==s1[i-1])
			j++;
		if(s1[n]!=s2[j])
			return false;
		n++;
	}
	return true;
}
bool jdot(char s1[],char s2[])
{
	if(strlen(s1)!=strlen(s2))
		return false;
	for(int j=0;j<strlen(s1);j++)
	{
		if(s1[j]=='.')
			j++;
		if(s1[j]!=s2[j])
			return false;
	}
	return true;
}
