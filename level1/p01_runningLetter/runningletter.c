#include<stdio.h>
#include<windows.h>
#include<string.h>
#define width 120//����̨�����֪120 
int main(void)
{	
	int i,j,k,n;
	char str2[] ="w";
	char str3[] =" ";
	for(i=0;;i++)
	{
		j=i/width;	
		k=i%width;
		char str1[width] ="";
		n=0;
		if(j%2==0)//�����ƶ�ʱ 
		{
			while(n<k)
			{
				strcat(str1,str3);
				++n;
			}
		}
		else//�����ƶ�ʱ 
		{
			while(n>k-width+1)
			{
				strcat(str1,str3);
				--n;
			}
		}
		strcat(str1,str2);
		printf("%s",str1);
		Sleep(100);	
		system("cls");
	}
	return 0;
}
