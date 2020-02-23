#include"declarations.h"
int step=0;
int h;
char map[MAXN];
char boxpos[MAXN]; 
struct point player;
int main()
{
	FILE *stepout=fopen("step.out","w");
	player.m=1;
	player.n=1;
	getmap();
	cls();
	printmap();
	while(!finish())
	{
		indir();
		cls();
		printmap();
	}
	printf("Congratulations!\n");
	fprintf(stepout,"Your step is:%d\n",step);
	fclose(stepout);
	return 0;
}
