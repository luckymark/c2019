#include<stdio.h>
int main()
{
	int x, y;
	int p[] = { 0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };
	bool t;
	for (int i = 4; i <= 100; i += 2){
		t = false;
		for (x = 1; x <= 25; x++){
			for (y = 1; y <= 25; y++){
				if ((p[x] + p[y]) == i){
					t = true;
					break;
				}
			}
			if (t == true)break;
		}
		if (t == false)printf_s("哥德巴赫猜想在100以内不成立,%d");
	}
	if (t == true)printf_s("哥德巴赫猜想在100以内成立");
	return 0;
}