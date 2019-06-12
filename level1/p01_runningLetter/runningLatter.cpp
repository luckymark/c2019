#include<cstdio>
#include<cstdlib>
/*
   By HuangChongYi 2018081306006
*/
const int _Maxlength=80
const int time=5000000

using namespace std;
void sleep(){
	for (int i=1;i<=time;i++){
	}
	return;
}
int abs(int x){
	return x>0 ? x : -x;
}
int main(){
	int blank;
	for(int i=0;i<2*_Maxlength;i++){
			sleep();
			blank=_Maxlength-abs(_Maxlength-i);
			for(int j=0;j<blank;j++) 
      		printf(" ");
			printf("8\n");
			sleep();
			system("cls");
	}
	return 0;
}


