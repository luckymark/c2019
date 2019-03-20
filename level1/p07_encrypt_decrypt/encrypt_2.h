#include<cstring>
#include<cstdlib>
#include<cctype>

char key[6] = "njjnb";

int encrypt(char * plaintext, char * cipher)
{
	int len = strlen(plaintext);
	for (int i = 0; i < len; i++)
	{
		int curKey = key[i % 5] - 'a';
		if (isupper(plaintext[i]))
		{
			cipher[i] = curKey + plaintext[i];
			if (cipher[i] > 'Z')
				cipher[i] -= 26;
		}
		else if (islower(plaintext[i]))
		{
			cipher[i] = curKey + plaintext[i];
			if (cipher[i] > 'z')
				cipher[i] -= 26;
		}
		else
		{
			cipher[i] = plaintext[i];
		}
	}
	cipher[len] = '\0';
	return 0;
}

int decrypt(char * cipher, char * plaintext)
{
	int len = strlen(plaintext);
	for (int i = 0; i < len; i++)
	{
		int curKey = key[i % 5] - 'a';
		if (isupper(plaintext[i]))
		{
			cipher[i] = curKey - plaintext[i];
			if (cipher[i] < 'A')
				cipher[i] += 26;
		}
		else if (islower(plaintext[i]))
		{
			cipher[i] = curKey + plaintext[i];
			if (cipher[i] < 'a')
				cipher[i] += 26;
		}
		else
		{
			cipher[i] = plaintext[i];
		}
	}
	plaintext[len] = '\0';
	return 0;
}
