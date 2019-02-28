### 题目：奔跑的字母

### 功能要求：

1. 在console上输出一个字母（或单词）
1. 使该字母或单词，按一定速度从左至右运动
1. 当遇到屏幕边界时反向运动
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

int main(){
	int step;
	char word;
	scanf("%c",&word);
	for(int step=1;step<=77;step++){
		system("cls");
		  for(int p=1;p<=77;p++){
		  	if(p==step){
		  		printf("c",word);
			  }
			  else{
			  	printf(" ");
			  }
		  }

	}
	for(int step=77;step>=1;step--){
		system("cls");
		  for(int j=1;j<=77;j++){
		  	if(j==step){
		  		printf("c",word);
			  }
			  else{
			  	printf(" ");
			  }
		  }

	}
	return 0;
} 
