#include<iostream>
#include<string>
using namespace std;

inline void encrypt(string &s) {
	for (int i = 0; i < s.length(); ++i) {
		if (i % 2)
			s[i] += i % 8;
		else
			s[i] -= i % 7;
	}
	cout << "The encrypted text is:\n" << s << endl;
}

inline void decrypt(string &s) {
	for (int i = 0; i < s.length(); ++i) {
		if (i % 2)
			s[i] -= i % 8;
		else
			s[i] += i % 7;
	}
	cout << "The decrypted text is:\n" << s << endl;
}

int main() {
	char option;
	string s;
	while (true) {
		cout << "Choose to ENCRYPT or DECRYPT (D / E):\n";
		cin.get(option);
		cin.get();
		if ('d' == option || 'D' == option) {
			cout << "Enter a string to decrypt:\n";
			getline(cin, s);
			decrypt(s);
		}
		else if ('e' == option || 'E' == option) {
			cout << "Enter a string to encrypt:\n";
			getline(cin, s);
			encrypt(s);
		}
		else
			cout << "Invalid option! Try again:\n";
	}
	return 0;
}
