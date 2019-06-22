#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
加密方式：xor 
*/
extern char *encrypt(char *strs, int length);
extern char *decrypt(char *encryptCode, int length);
extern void getCode(int origin, char *code);
extern char getChar(char *code, int first);
int main()
{
    char str[] = "Hello World!";
    int length = strlen(str);

    char *code = encrypt(str, strlen(str));
    printf("EncryptStr: %s\n", code);

    char *decryptStr = decrypt(code, strlen(code));
    printf("DecryptStr: %s", decryptStr);

    return 0;
}
char *encrypt(char *strs, int length)
{
    int i, c;
    int t = 0;
    char *encryptCode = (char *)malloc(sizeof(char) * length * 7 + 1);
    *encryptCode = 0;
    for (i = 0; i < length * 7; i = i + 7)
    {
        char temp[7];
        getCode((int)strs[t++], temp);
        for (c = 0; c < 7; c++)
        {
            encryptCode[c + i] = temp[c];
        }
    }
    encryptCode[i] = '\0';
    return encryptCode;
}
char *decrypt(char *encryptCode, int length)
{
    int i, c;
    int t = 0;
    char *decryptCode = (char *)malloc(sizeof(char) * length / 7 + 1);
    *decryptCode = 0;
    for (i = 0; i < length * 7; i = i + 7)
    {
        char c;
        c = getChar(encryptCode, i);
        decryptCode[t++] = c;
    }
    decryptCode[t] = '\0';
    return decryptCode;
}
void getCode(int origin, char *code)
{
    int i;
    char temp[7];
    char key[7] = {1, 0, 0, 0, 0, 1, 0}; //private key
    itoa(origin, temp, 2);
    int c = 7 - strlen(temp);
    for (i = 0; i < c; i++)
    {
        code[i] = '0';
    }
    for (i = c; i < 7; i++)
    {
        code[i] = temp[i - c];
    }
    for (i = 0; i < 7; i++)
    {
        code[i] ^= key[i];
    }
}
char getChar(char *code, int first)
{
    int i;
    int t = 0;
    char temp[8];
    char *c;
    char key[7] = {1, 0, 0, 0, 0, 1, 0}; //private key
    for (i = first; i < first + 7; i++, t++)
    {
        temp[t] = key[t] ^ code[i];
    }
    temp[7] = '\0';
    int t1 = 0;
    for (i = 0; i < 7; i++)
    {
      
        t1 += (temp[i]=='1'?1:0)<<6-i;
    }
    return (char)t1;
}