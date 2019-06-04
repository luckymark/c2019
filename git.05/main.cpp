//
//  main.cpp
//  git.05
//
//  Created by 兼桑 on 2019/3/6.
//  Copyright © 2019 兼桑. All rights reserved.
//

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;
int main()
{
    clock_t st,et;
    st=clock();
    int i=3,j=2;
    printf("2\n");
    for(i=3;i<=1000;++i)
    {
        for(j=2;j<=sqrt(i);++j)
        {
            if(i%j==0)
                break;
        }
        if(j>=sqrt(i))
            printf("%d\n",i);
    }
    et=clock();
    printf("time is %lu",et-st);
    return 0;
}
