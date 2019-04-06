#include <iostream>
#include<string.h> 
#include<cmath>
#include<Windows.h> 
using namespace std;
string lock(string,int);
int r_key[4]={0};
int main(int argc, char** argv) {
	string text=" ";
	string after=" ";
	int times=0,key=0,r=0;
	cout<<"请输入您的加密或解密文本"<<endl;
	getline(cin,text);
	system("cls");
	cout<<"如果您需要加密 请输入1 解密输入-1"<<endl;
	cin>>times;
	system("cls");
	cout<<"请输入您的秘钥或要设置的秘钥"<<endl;
	cin>>key;
	system("cls");
	for(int i=0;i<4;i++)
	{
		r=pow(10,i+1);
		r_key[i]=(key%r)/(r/10);
	}
	after=lock(text,times);
	cout<<"加密/解密后的密文如下"<<endl<<after<<endl;
	return 0;
}
string lock(string text,int times)
{
	for(int i=0;i<text.length();i++)
	{
		text[i]+=(r_key[i%4]*times);
	}
	return text;
}


