//
//  main.cpp
//  git .08
//
//  Created by 兼桑 on 2019/3/27.
//  Copyright © 2019 兼桑. All rights reserved.
//

#include<iostream>
using namespace std;
int main()
{
    void hanoi(int n,char one,char two,char three);
    hanoi(64,'A','B','C');
}
void hanoi(int n,char one,char two,char three)
{
    void move(char x,char y);
    if (n == 1)
    {
        move(one,three);
    }
    else
    {
        hanoi(n-1,one,three,two);
        move(one,three);
        hanoi(n-1,two,one,three);
    }
}
void move(char x, char y)
{
    cout<<x<<"-->"<<y<<endl;
}
