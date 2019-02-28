#include<iostream>

int a,b,c,cnt = 0;

int cal(int x) {
	return x*x*x;
}

int main(){
	for(int i = 100;i<=999;i++){
		a = i/100;
		b = (i - 100*a)/10;
		c = i - 100*a - 10*b;
		if(cal(a) + cal(b) + cal(c) == i){
			cnt++;
			std::cout<<"The "<<cnt<<"th narcissus number is "<<i<<std::endl;
		}
	}
	return 0;
}