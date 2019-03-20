#include<cstdio>
#include<cstring>

using namespace std;

// x=1/6 x +1/12 x +1/7 x + 5 + 1/2x + 4 

int main(){
	double chushu=1.0/6.0 + 1.0/12.0+ 1.0/7.0 + 1.0/ 2.0 ;
	double beichushu=5.0+4.0 ;
	double x=beichushu / (1.0-chushu);
	int intx = int (x+0.5);
	int ans = intx-4;
	printf("%d\n",ans);
	return 0;
}
