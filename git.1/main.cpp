//
//  main.cpp
//  git.1
//
//  Created by 兼桑 on 2019/4/3.
//  Copyright © 2019 兼桑. All rights reserved.
//

#include<cstdio>
#include<cstdlib>
using namespace std;
#define width 12
int main()
{
    int i=1,j;
    bool t=0;
    while(i<=width)
    {
        for(j=0;j<=i;++j)
        {
            printf(" ");
        }
        printf("r");
        system("cls");
        if(i==width) t=1;
        if(i==0) t=0;
        if(t==1) --i;
        else ++i;
    }
    return 0;
}




