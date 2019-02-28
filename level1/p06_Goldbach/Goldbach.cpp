#include<iostream>
#include<cstring>

bool isprime[107],flag = 1;

void init(){
	memset(isprime,1,sizeof(isprime));
	for(int i = 2;i<=100;i++){
		if(isprime[i]){
			for(int j = 2*i;j<=100;j+=i) isprime[j] = 0;
		}
	}
	isprime[0] = isprime[1] = 0;
}

bool check(int x){
	bool tflag = 0;
	for(int i = 2;i<x;i++){
		if(isprime[i]&&isprime[x-i]){
			std::cout<<x<<"="<<i<<"+"<<x-i<<std::endl;
			tflag = 1;
			break;
		}
	}
	if(tflag) return true;
	else return false;
}

int main(){
	init();
	for(int i = 4;i<=100;i+=2){
		if(!check(i)){
			flag = 0;
			break;
		}
	}
	if(flag) std::cout<<"Goldbach conjecture is right when n<=100"<<std::endl;
	else std::cout<<"Goldbach conjecture is wrong when n<=100"<<std::endl;
	return 0;
}