#include<iostream>

bool check(int x){
	if(x % 6 != 0 ||x % 12!= 0 || x% 7 != 0 || x%2 != 0) return false;  //年龄要求能被整除，否则返回假 
	int res = x/6 + x/12 + x/7 + 5 +x/2 + 4;
	if(res == x) return true;   //如果方程相等则返回真
	else return false; 
}

int main(){
	for(int i = 1;i<=150;i++){
		if(check(i)) std::cout<<"Diophantus' age is "<<i<<"."<<std::endl;
	}
	return 0;
}