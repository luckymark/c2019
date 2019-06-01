//
//  goldbach.cpp
//  git.06
//
//  Created by 兼桑 on 2019/3/14.
//  Copyright © 2019 兼桑. All rights reserved.
//

#include "goldbach.hpp"
#include<cmath>
#include<iostream>
int prime(int n)//检验n为素数
{
    for (int i = 2; i < n; i++)
        if (n%i == 0) return 0;
    return 1;
}
int goldbach(int n)
{
    int a,b;
    for(int i=1;i<=n/2;++i)
    {
        a=prime(i);
        b=n-a;
        if(prime(b)==1)
        std::cout<<n<<"="<<a<<"+"<<b<<std::endl;
    }
    return 0;
}
