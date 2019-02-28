//凯撒加密 + RSA加密 

#include<iostream>
#include<cstring>
#include<vector>

#define CCC 11 //Caesar Cryption Const
#define RCCE 10001 //RSA Cryption Const E
#define RCCN 517259999 //RSA Cryption Const N
#define RCCD 464152001 //RSA Cryption Const D

typedef long long ll;
typedef unsigned long long ull;

std::string s;
std::vector<ll> cryption_code;
int len;

ll pow_mod(ll a,ll b,ll c){             //快速幂计算 
	ll res = 1,t = a%c;
	while(b){
		if(b&1){
			res = (res*t)%c;
		}
		t = (t*t)%c;
		b>>=1;
	}
	return res;
}

char Caesar(char c,int type){           //type = 1表示加密  type = -1表示解密 
    return 33 + (c-33+(type*CCC+93)%93)%93;
}

std::vector<ll> Encryption(std::string ss){
	int len = ss.length();
	ll tmp,encode,decode;
	std::vector<ll> temp_code;
	for(int i = 0;i<len;i++) ss[i] = Caesar(ss[i],1);
	for(int i = 0;i<len;i+=2){
	    if(i == len-1) tmp = (ll)ss[i];
    	else tmp = (ll)(ss[i]*1000 + ss[i+1]);
		encode = pow_mod(tmp,RCCE,RCCN);
		temp_code.push_back(encode);
	}
	return temp_code;
}

std::string Decryption(std::vector<ll> cryption){
	int len = cryption.size();
	ll decode;
	char x,y;
	std::string res;
	for(int i = 0;i<len;i++){
		decode = pow_mod(cryption[i],RCCD,RCCN);
		if(decode<1000){
			x = decode;
			res.push_back(Caesar(x,-1));
			continue;
		}
		x = decode / 1000;
		y = decode - 1000*x;
		res.push_back(Caesar(x,-1));
		res.push_back(Caesar(y,-1));
	}
	return res;
}

int main(){
	std::cin>>s;
	std::cout<<"ciptertext is:"<<std::endl;
	cryption_code = Encryption(s);
	len = cryption_code.size();
	for(int i = 0;i<len;i++) std::cout<<cryption_code[i];
	std::cout<<std::endl;
	std::cout<<"it can be decrypt to:"<<std::endl;
	std::cout<<Decryption(cryption_code)<<std::endl;
	return 0;
}
