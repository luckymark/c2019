//
//  main.cpp
//  git _03
//
//  Created by 兼桑 on 2019/3/2.
//  Copyright © 2019 兼桑. All rights reserved.
//

#include <cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    float i;
    for(i=10;i<=150;i++)
    {
        if(i/6+i/12+i/7+i/2+9==i)
            printf("%f",i);
    }
    return 0;
}
