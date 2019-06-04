#include<stdio.h>
int get_goal(FILE *pf,int goal[5][2]) {
	int k = 0, n = 0;
	char c, n_;
	n_ = fgetc(pf); n = n_ - '0';//get number of boxs
	do {
		c = fgetc(pf);
		if (c == '(') {
			goal[k][0] = (fgetc(pf) - '0') * 10 + (fgetc(pf) - '0');
			fgetc(pf);
			goal[k][1] = (fgetc(pf) - '0') * 10 + (fgetc(pf) - '0');
			k++;
		}
	} while (k != n && n != 1);
	fgetc(pf); fgetc(pf);
	return n;
}
