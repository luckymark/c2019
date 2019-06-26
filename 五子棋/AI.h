#include<stdio.h>
struct position{
	int x;
	int y;
	int score;
}; 
extern struct position digital_max[226];
extern struct position digital_min[226];
void initialize_digital_min();
void initialize_digital_max();
void min_sense();
int sense();
int ai_move();
