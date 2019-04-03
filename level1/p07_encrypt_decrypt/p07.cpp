#include <iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>

#define debug

int encrypt(char * plaintext, char * cipher);
int decrypt(char * cipher, char * plaintext);

using namespace std;

int main()
{
	const int textLength = 1000;
	char plaintext[textLength], cipher[textLength];

	srand(unsigned int(time(NULL)));
	cout << "Please choose to:" << endl
		<< "1.encrypt(e)" << endl
		<< "2.decrypt(d)" << endl
		<< "3.quit(q)" << endl;
	char c = tolower(getchar());
	while (c != 'q')
	{
		if (c == 'e')
		{
			cout << "Please input the plaintext:";
			cin >> plaintext;
			encrypt(plaintext, cipher);
			cout << "The encrypted text is: " << cipher << endl;

#ifdef debug
			decrypt(cipher, plaintext);
			cout << "The redecrypted text is:" << plaintext << endl;
#endif
		}
		else if (c == 'd')
		{
			cout << "Please input the cipher:";
			cin >> cipher;
			encrypt(cipher, plaintext);
			cout << "The decrypted text is: " << plaintext << endl;
		}
		else
		{
			cout << "Invalid input." << endl;
		}
		system("pause");
		cout << endl;

		cout << "Please choose to:" << endl
			<< "1.encrypt(e)" << endl
			<< "2.decrypt(d)" << endl
			<< "3.quit(q)" << endl;
		c = tolower(getchar());

	}
	return 0;

}

