#include<cstdio>
#include<cstring>

using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
bool is_prime(int x){
	for(int i=2;i*i<=x;i++){
		if (x%i==0) return false;
	}
	return true;
}
int main(){
	int flag;
	FOR(i,4,100)
		if (!(i&1)){    // i%2==0 
			flag=1;
			FOR(j,i>>1,i)
				if(flag)
				if(is_prime(j)&&is_prime(i-j)){
					printf("%d=%d+%d\n",i,i-j,j);
					flag=0;
				}
			if (flag) printf("Congratulation! You have proved goldbach is wrong !!!!!\n");
		}
	return 0;
}
