### 功能要求：

1. 任意输入一个正整数n
1. 判断n是否为素数

#include<bits/stdc++.h>
using namespace std;
int main()
{
 int a,b,c,n=0;
 scanf("%d",&a);
 c=sqrt(a);
  if(a==1)
  {
    printf("This is not a prime.");
  }
  for(b=2;b<c;b++)
  {
    if(a%b==0)
    n=n+1;
  }
  if(n==0)
  printf("This is a prime");
  else
  printf("This is not a prime");
 return 0;
}
