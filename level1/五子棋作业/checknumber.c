#include <stdio.h> 
int checknumber(char *a[30]){//判断横排最多有几个连子 
	int i,j,k; 
	int count=1;
	int maximum;
	int max[4]={0,0,0,0,0};
	for(i=1;i<30;i=i+2){
		for(j=0;j<29;j=j+2){
			if(a[i][j]=='X'&&a[i][j+2]=='X'){
				count++;
			}
			else{
				if(count>max[1]) max[1]=count;
				count=1; 
			}
		}
	}
	/*for(j=0;j<29;j=j+2){
		for(i=1;i+1<30;j=j+2){
			if(a[i][j]=='X'&&a[i+2][j]=='X'){
				count++;
			}
			else{
				if(count>max[2]) max[2]=count;
				count=1; 
			}
		}
	}*/
	for(i=1;i<30;i=i+2){
		for(j=0;j<29;j=j+2){
				if(a[i][j]=='X'&&a[i+2][j+2]=='X'){
					count++;
				}
				else{
					if(count>max[3]) max[3]=count;
					count=1;
			}
		}
	}
	/*for(i=0;i<30;i=i+2){
		for(j=29;j>0;j=j-2){
			for(k=0;k<30;k=k+2){
				if(a[i+k][j-k]=='X'&&a[i+k+2][j-k-2]=='X'){
					count++;
				}
				else{
					if(count>max[4]) max[4]=count;
					count=1;
				}
			}
		}
	}*/
	maximum=max[1];
	/*for(i=1;i<=4;i++)
	{
		if(max[i]>maximum)
			maximum=max[i];
	}
	/*if(maximum==5)
	{
		printf("你赢了!\n");
		exit(0);
	}*/
	return max[3];
}