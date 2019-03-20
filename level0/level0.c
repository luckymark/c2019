### C0
#include<stdio.h>
int main()
{
      printf("Hello world! I'm Ceng Feng!");
      return 0;
}

### C1
(1)
#include<stdio.h>
int main()
{
      double a;
	    int b;
 	    scanf("%lf",&a);
 	    if(a>0)
        printf("It's a positive number.");
      else if(a==0)
        printf("It's neiher a positive number nor a negative one");
	    else
        printf("It's a negative number.");
	    b=(int)a;
	    if(a==b)
	    {
          if(b%2==0)
            printf("\nIt's an even number.");
	        else if(b%2==1)
            printf("\nIt's an odd number");
      }
	    else printf("\nIt's not an even number or an odd one.");
      return 0;
}

(2)
#include<stdio.h>
int main()
{
      int a;
	    scanf("%d",&a);
	    if(a%13==0)
        printf("%d is the multiple of 13.",a);
	    else
        printf("%d is not the multiple of 13.",a);
      return 0;
}

(3)
#include<stdio.h>
int main()
{
      int a,first=1;
	    scanf("%d",&a);
	    if(a%4==0)
	    {
	        if(a%100==0)
            first=0;
		      else
            first=1;
	        if(a%400==0)
            first=1;
	    }
	    if(first)
        printf("%d is a leap year.",a);
	    else
        printf("%d is not a leap year.",a);
	    return 0;
}

(4)
#include<stdio.h>
int main()
{
	   int a,b,max;
	   scanf("%d %d",&a,&b);
	   if(a>b)
      max=a;
	   else
      max=b;
	   printf("The max number is %d.",max);
	   return 0;
}

(5)
#include<stdio.h>
int main()
{
	   int a,b,c,max;
	   scanf("%d %d %d",&a,&b);
	   max=a;
	   if(b>max)
      max=b;
	   if(c>max)
      max=c;
	   printf("The max number is %d.",max);
	   return 0;
}

(6)
#include<stdio.h>
#define INF 1000000
int a[1000000];
int main()
{
	   int i,n,max=-INF;
	   scanf("%d",&n);
	   for(i=0;i<n;i++)
	    {
		    scanf("%d",&a[i]);
		    if(a[i]>max)
          max=a[i];
	    }
	   printf("The max number is %d.",max);
	   return 0;
}

### C2
(1)
#include<stdio.h>
int main()
{
	   int i;
	   for(i=0;i<10000;i++)
	   printf("你好！ ");
	   return 0;
}

(2)
#include<stdio.h>
int main()
{
	  system("color 0a");
	  while(1)
    {
		   printf("0 1");
    }
	  return 0;
}

(3)
#include<stdio.h>
int main()
{
	  system("color 0a");
  	while(1)
  	{
		   printf("%d\t",rand()/1000);
    }
	 return 0;
}

(4)
#include<stdio.h>
int main()
{
      int i,first=1;
	    for(i=2;i<=100;i++)
	    {
	       if(i%2)continue;
	       else
	       {
		        if(!first)printf(" %d",i);
		        else printf("%d",i);
		        first=0;
	       }
      }
      return 0;
}

(5)
#include<stdio.h>
int main()
{
      int i,first=1;
	    for(i=1;i<=100;i++)
	    {
	    if(i%3==0&&i%5!=0)
	      {
	  	  if(!first)
          printf(" %d",i);
	  	  else
           {
	  		    printf("%d",i);
	  		    first=0;
		       }
	      }
      }
    return 0;
}

(6)
#include<stdio.h>
int main()
{
      int i,first=1,sum=0;
      for(i=1;i<=100;i++)
	    {
	       if(i%7==0||i%10==7)
	       {
	  	      if(!first)
              printf(" %d",i);
	  	      else
            {
	  		       printf("%d",i);
	  		       first=0;
		        }
		        sum+=i;
	       }
      }
      printf("\n%d",sum);
      return 0;
}

(7)
#include<stdio.h>
int main()
{
      int i,j;
      for(i=1;i<=9;i++)
	    {
	        for(j=1;j<=9;j++)
	         {
		         if(j!=9)
		           {
		             if(i*j<10)
                  printf("%d*%d=%d  ",i,j,i*j);
		             else
                  printf("%d*%d=%d ",i,j,i*j);
	             }
		         else printf("%d*%d=%d",i,j,i*j);
           }
         printf("\n");
       }
    return 0;
}

(8)
#include<stdio.h>
int a[100000];
int main()
{
      int i,n;
      scanf("%d",&n);
	    for(i=0;i<n;i++)
	    {
		      scanf("%d",&a[i]);
	    }
	    for(i=n-1;i>=0;i--)
    	{
 	       if(i==n-1)
          printf("%d",a[i]);
 	       else
          printf(" %d",a[i]);
      }
      return 0;
}

(9)
#include<stdio.h>
int a[100000];
int main()
{
      int i,j,first=1;
	    for(i=0;i<5;i++)
	    scanf("%d",&a[i]);
	    for(i=0;i<9;i++)
	    {
		     first=1;
		     for(j=0;j<5;j++)
		     if(i==a[j])
		     {
			      first=0;break;
		     }
		     if(first)
          printf("%d\n",i);
	    }
      return 0;
}

(10)
#include<stdio.h>
int a[100];
int main()
{
      int i,j,first=1;
	    for(i=0;i<=9;i++)a[i]=0;
	    for(i=0;i<5;i++)
	    {
	       scanf("%d",&j);
	       a[j]+=1;
      }
	    for(i=0;i<=9;i++)
	    if(a[i])
	    {
	       for(j=1;j<=a[i];j++)
         printf("%d ",i);
      }
	    return 0;
}

###C3
(1)
#include<stdio.h>
int sum(int* p,int n)
{
	int i,all=0;
	for(i=0;i<n;i++)
	{
		all+=p[i];
	}
	return all;
}
int main()
{
	int i,j,n,all=0;
	int a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	   scanf("%d",&a[i]);
	all=sum(a,n);
	printf("%d",all);
    return 0;
}

(2)
#include<stdio.h>
double factorial(int n)
{
      int i;
      double ans=1;
	    for(i=1;i<=n;i++)
	    {
		      ans=ans*i;
	    }
	    return ans;
}
int main()
{
      int n;
      double ans;
	    scanf("%d",&n);
	    ans=factorial(n);
	    printf("%.0lf",ans);
	    return 0;
}

(3)
#include<stdio.h>
double a[1000];
void fbnq(int n)
{
      int i;
	    for(i=2;i<n;i++)
	    {
		     a[i]=a[i-2]+a[i-1];
	    }
	    return;
}
int main()
{
      int i,n;
      a[0]=0;a[1]=1;
	    scanf("%d",&n);
	    fbnq(n);
	    for(i=0;i<n;i++)
        printf("%.0lf ",a[i]);
	    return 0;
}

(4)
#include<stdio.h>
int isrightangle(double a,double b,double c)
{
      if(a*a+b*b==c*c)
        return 1;
	    else
        return 0;
}
int main()
{
      double a,b,c;
      int first;
      scanf("%d%d%d",&a,&b,&c);
      first=isrightangle(a,b,c);
      if(first)
        printf("That is a right angle triangle.");
      else
        printf("That is not a right angle triangle.");
      return 0;
}

(5)
#include<stdio.h>
char s[1000][1000];
int isoverlap(int a,int b,int c,int d,int e,int f,int g,int h)
{
      int i,j,left,up,down,right;
      for(i=a;i<=c;i++)
	    for(j=b;j<=d;j++)
	    s[i][j]+=1;
	    for(i=a;i<=c;i++)
	    for(j=b;j<=d;j++)
	    s[i][j]+=1;
	    left=b<f?b:f;
	    up=a<e?a:e;
	    down=c>g?c:g;
	    right=d>h?d:h;
	    for(i=left;i<=right;i++)
	    for(j=up;j<=down;j++)
	    if(s[i][j]==2)return 1;
	    return 0;
}
int main()
{
      int a,b,c,d,e,f,g,h;
	    int first;
	    printf("请输入第一个矩阵坐标：\n");
	    scanf("%d%d%d%d",&a,&b,&c,&d);
	    printf("请输入第二个矩阵坐标：\n");
	    scanf("%d%d%d%d",&e,&f,&g,&h);
	    first=isoverlap(a,b,c,d,e,f,g,h);
	    if(first)
        printf("Overlap");
	    else
        printf("Not overlap");
	    return 0;
}

(6)
#include<stdio.h>
#define rate 6.7201
double dollartoyuan(double dollar)
{
      double yuan;
	    yuan=dollar*rate;
	    return yuan;
}
int main()
{
	    double yuan,dollar;
	    printf("请输入美元数额：\n");
	    scanf("%lf",&dollar);
	    yuan=dollartoyuan(dollar);
	    printf("您可换取的人民币数额为：%lf",yuan);
	    return 0;
}
