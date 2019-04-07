#include <iostream>
#include<conio.h>
#define P players
#define MAPLE_X 8
#define MAPLE_Y 8
#define NUM 4
using namespace std; 
struct point
{
	int zt;
};
struct object
{
	int x;
	int y;
};
extern point map[MAPLE_X+1][MAPLE_Y+1];
extern object players;
extern object box[NUM+1];
extern object re;
void scan();
void print();
int judge(char);
int grab(object);
object change(char,object);
void push_move(char);
