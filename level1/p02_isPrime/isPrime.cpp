#include <stdio.h> 
int main(){
	int i, j, n;
	j=0;
	scanf("%d", &n);
	for(i=2;i<n;i++){
		if(n%i==0){
			j++;
		}
		
	}
	if(j==0){
		printf("%d是素数",n); 
	}
	else{
		printf("%d不是素数",n);
	}
	return 0;
}
