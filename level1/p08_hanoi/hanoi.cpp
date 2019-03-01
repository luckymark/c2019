#include<iostream>

int n;

void print(int x,char a,char b){
	std::cout<<"Move disk "<<x<<": "<<a<<"---------->"<<b<<std::endl;
}
//递归 
void solve(int x,char a,char b,char c){              //递归处理，表示将第x个盘子从a柱移动到c柱 
	if(x==1){
		print(1,a,c);
	}
	else{
		solve(x-1,a,c,b);         //将当前处理的盘子上面的盘子先放到B柱上 
		print(x,a,c);
		solve(x-1,b,a,c);         //然后将当前处理的盘子之前的盘子又放到C柱上，此时A柱子起到临时放置的作用 
	} 
}

int main(){
	std::cout<<"Please input the num of disk:";
	std::cin>>n;
	std::cout<<"Solve problem:"<<std::endl;
	solve(n,'A','B','C');
	return 0;
}