#include<iostream>
#include<vector>
#include<cstring>
#include<ctime>

bool nums[1007];
std::vector<int> primes;
int len;

void init(){
	memset(nums,1,sizeof(nums));
	for(int i = 2;i<=1000;i++){
		if(nums[i]){
			primes.push_back(i);
			for(int j = i*2;j<=1000;j+=i){
				nums[j] = 0;
			}
		}
	}
}

int main(){
	init();
	len = primes.size();
	std::cout<<"the primes between 2 to 1000 are:"<<std::endl;
	for(int i = 0;i<len;i++){
		if(i == 0) std::cout<<primes[i];
		else{
			if(i%30 == 0) std::cout<<std::endl<<primes[i];
			else std::cout<<" "<<primes[i];
		}
	}
	std::cout<<std::endl;
	std::cout<<"program's runnig time is: ";
	std::cout<<(double)clock() / CLOCKS_PER_SEC <<"s"<<std::endl;
	return 0;
}