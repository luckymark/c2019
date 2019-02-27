#include<cstdio>
#include<iostream>
#include<cmath>

typedef long long ll;

ll n;

bool check(ll x){
	if(x == 1) return false;
	ll t = (ll)std::sqrt(x);
	for(ll i = 2;i<=t;i++){
		if(x%i==0) return false;
	}
	return true;
}

int main(){
	std::cin>>n;
	if(check(n)){
		std::cout<<n<<" is prime."<<std::endl;
	}
	else{
		std::cout<<n<<" is not prime."<<std::endl;
	}
}