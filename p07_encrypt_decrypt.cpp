#include<iostream>
#include<string>
using namespace std;
string s;
char a[0x3f3f3f3f];
const int key = 2;
int main() {
	while (1) {
		int i;
		cout << "请输入您想要对其操作的字符串:" ;
		cin >> s;
		int len = s.size();
		cout << "请问您想加密还是解密" << endl << "1.加密" << endl << "2.解密"<<endl;
		cin >> i;
		if (i == 1) {
			for (int i = 0; i < len; i++){
				if (s[i] >= 'A'&&s[i] <= 'Z')a[i] = ((s[i] - 'A') + key) % 26 + s[i];
				else if(s[i]>='a'&&s[i]<='z')a[i]= ((s[i] - 'a') + key) % 26 + s[i];
			}
			cout << "这是您加密后的字符串" << a << endl;
		}
		else if (i == 2) {
			for (int i = 0; i < len; i++) {
				if (s[i] >= 'A'&&s[i] <= 'Z')a[i] = ((s[i] - 'A') -key) % 26 + s[i];
				else if(s[i] >= 'a'&&s[i] <= 'z')a[i]= a[i] = ((s[i] - 'a') - key) % 26 + s[i];
			}
			cout << "这是您解密后的字符串" << a <<endl;
		}
	
	}
	return 0;
}