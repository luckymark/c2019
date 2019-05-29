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
		  		printf("%c",word);
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
		  		printf("%c",word);
			  }
			  else{
			  	printf(" ");
			  }
		  }

	}
	return 0;
}
