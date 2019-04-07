#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
struct goods
{
	int order;
	string name;
	int num;
};
extern goods good[1000];
void my_print(int);
int scan();
void in();
int create(int all);
int my_remove(int all);
void save(int all);
