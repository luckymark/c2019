//encrypt_decrypt  : only can transform A~Z (65-90)and a~z (97-122)
//by huangchongyi 2018081306006
#include<cstdio>
#include<cstring>
using namespace std;
char key[11]="I HATE YOU";    //the key to encrypt or decrypt
void encrypt_or_decrypt(char *a,int sigma){    //sigma is to show to encrypt or decrypt
	for(int i=0;a[i]!='\0';i++){
		if (a[i]>='a'&&a[i]<='z') a[i]=(26+a[i]-'a'+sigma*((key[i%10]-'a')%26))%26 +'a';
		if (a[i]>='A'&&a[i]<='Z') a[i]=(26+a[i]-'A'+sigma*((key[i%10]-'A')%26))%26 +'A';
	}
	return;
}
int main(){
	char passage[100]="I LOVE you i love YOU I LOVE you i love YOU I LOVE you i love YOU I LOVE you i love YOU ";
	printf("the origin  ：%s\n",passage);
	
	encrypt_or_decrypt(passage,1);
	printf("the encrypt : %s\n",passage);
	
	encrypt_or_decrypt(passage,-1);
	printf("the decrypt : %s\n",passage); 
	
	return 0;
}
