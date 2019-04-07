#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void encrypt(char* a, char* b);
void decrypt(char* a, char* b);
int main(){
	char a[9999]={0};
	int i, l, n;;
	while(1){
		puts("for 1 is to encrypt, 2 is to decrypt, others are to quit");
		scanf("%d",&l);
		getchar();
		if(l==1){
			puts("input£º");
			gets(a);
			char b[strlen(a)];
			for(i=0;i<strlen(a);i++){
			b[i]=a[i];
			}
			encrypt(a, b);
		}
		else if(l==2){
			puts("input£º");
			gets(a);
			char b[strlen(a)];
			for(i=0;i<strlen(a);i++){
			b[i]=a[i];
			}
			decrypt(a, b);
		}
		else{
			break;
		}
	}
	
	return 0;
} 
void encrypt(char* a, char* b){
	int i;
	for(i=0;i<=strlen(a)-1;i++){
		b[i]-=5;
	} 
	puts("encrypt£º");
	puts(b);
}
void decrypt(char* a, char* b){
	int i;
	for(i=0;i<=/*sizeof(a)/sizeof(a[0])*/strlen(a)-1;i++){
		b[i]+=5;
	}
	puts("decrypt:");
	puts(b);
}
