#include <stdio.h>
#include <string.h>
#include <time.h> 
void hanoi(int n,char a,char b,char c)
{
	if(n==1)
	printf("%c→%c\n",a,c);
	else
	{
		hanoi(n-1,a,c,b);
		printf("%c→%c\n",a,c);
		hanoi(n-1,b,a,c);
	}
} 
int main(int argc, char *argv[])
{
	int n;
	printf("请输入盘子总数"); 
	scanf("%d",&n);
	clock_t start, finish;                         
    double Total_time; 
	start = clock();  
	hanoi(n,'A','B','C');
	finish = clock();                              
    Total_time = (double)(finish-start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", Total_time);  
	return 0;
}                            
//                                             
                             
//                                             
         