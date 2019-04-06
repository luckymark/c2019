#include<iostream>
#include<string>
using namespace std;
struct goods
{
	int order;
	string name;
	int num;
};
extern goods good[100];
void print();
int scan();
void in();
int create(int all);
int my_remove(int all);
void save();