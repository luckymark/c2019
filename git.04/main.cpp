//
//  main.cpp
//  git.04
//
//  Created by 兼桑 on 2019/3/6.
//  Copyright © 2019 兼桑. All rights reserved.
//

#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
    int a,b,c,i=100;
    while(i<1000)
    {
        c=i%10;
        b=i/10%10;
        a=i/100;
        if(pow(a,3)+pow(b,3)+pow(c,3)==i)
            printf("%d\n",i);
        ++i;
    }
    return 0;
}
