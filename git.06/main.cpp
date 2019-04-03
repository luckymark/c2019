//
//  main.cpp
//  git.06
//
//  Created by 兼桑 on 2019/3/14.
//  Copyright © 2019 兼桑. All rights reserved.
//

#include <iostream>
using namespace std;
int goldbach(int);
int prime(int);
int main()
{
    int n;
    for(n=6;n<=100;n+=2)
    {
        goldbach(n);
    }
    return 0;
}
