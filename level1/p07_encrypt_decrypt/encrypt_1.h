//#include<cstring>
//#include<cstdlib>
//int encrypt(char * plaintext, char * cipher)
//{
//	int len = strlen(plaintext);
//	for (int i = 0; i < len; i++)
//	{
//		cipher[2 * i] = plaintext[i];
//		cipher[2 * i + 1] = rand() % 26 + 'a' - 1;
//	}
//	cipher[2 * len] = 0;
//	return 0;
//}
//
//int decrypt(char * cipher, char * plaintext)
//{
//	int len = strlen(cipher) / 2;
//	for (int i = 0; i < len; i++)
//	{
//		plaintext[i] = cipher[2 * i];
//	}
//	plaintext[len] = 0;
//	return 0;
//}