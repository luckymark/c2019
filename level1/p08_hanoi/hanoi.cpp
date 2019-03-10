#include<cstdio>

using namespace std;

//  by huang chong yi   2018081306006
void move(int brick,char place_a,char place_b){
	if(brick==0) return ;
	move(brick-1,place_a,294-place_a-place_b);                    //  294 is the sum of 'a' , 'b' and 'c' ;
	printf("move the %dth from %c to %c\n",brick,place_a,place_b);
	move(brick-1,294-place_a-place_b,place_b);
}

int main(){
	int n;
	scanf("%d",&n);
	move(n,'a','c');  //the total move is 2^n -1 ; 
	return 0;
}
