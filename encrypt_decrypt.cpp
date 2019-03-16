#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

string encrypt(string str)
{
	for(int i=0;i<str.length();i++){
		switch(str[i]){
			case('a'):
				str[i]='~';
				break;
			case('d'):
				str[i]='!';
				break;
			case('g'):
				str[i]='@';
				break;
			case('j'):
				str[i]='#';
				break;
			case('m'):
				str[i]='$';
				break;
			case('p'):
				str[i]='%';
				break;
			case('s'):
				str[i]='^';
				break;
			case('v'):
				str[i]='&';
				break;
			case('y'):
				str[i]='*';
				break;
			default:
				break;
		}
	}
	return str;
}

string decrypt(string str)
{
	for(int i=0;i<str.length();i++){
		switch(str[i]){
			case('~'):
				str[i]='a';
				break;
			case('!'):
				str[i]='d';
				break;
			case('@'):
				str[i]='g';
				break;
			case('#'):
				str[i]='j';
				break;
			case('$'):
				str[i]='m';
				break;
			case('%'):
				str[i]='p';
				break;
			case('^'):
				str[i]='s';
				break;
			case('&'):
				str[i]='v';
				break;
			case('*'):
				str[i]='y';
				break;
			default:
				break;
		}
	}
	return str;
}
int main()
{
	string str,result1,result2;
	int choice;
	cout<<"Please choose encrypt or decrypt."<<endl;
	cout<<"press 1 to encrypt,press 2 to decrypt."<<endl;
	cin>>choice;
	getchar();
	if(choice==1){
		cout<<"Please input a string to encrypt."<<endl;
		getline(cin,str); 
		result1=encrypt(str);
		cout<<"Now the encrypted string is "<<result1<<endl;
	}else if(choice==2){
		cout<<"Please input a string to decrypt."<<endl;
		getline(cin,str);
		result2=decrypt(str);
		cout<<"Now the decrypted string is "<<result2<<endl;
	}
	return 0;
}
