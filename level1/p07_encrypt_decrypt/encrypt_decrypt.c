#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXN 1000005

int XorArray[MAXN],n;
char Message[MAXN],Cipher[MAXN*2],DecMess[MAXN];

char ToHex(int _oct)
{
    if(_oct<10)return _oct+'0';
    else return _oct-10+'a';
}

int ToOct(int _hex)
{
    if(_hex>='0' && _hex<='9')return _hex-'0';
    else return _hex-'a'+10;
}

int GetRand(int LowerBound,int UpperBound)
{
    return rand()%(UpperBound-LowerBound+1)+LowerBound;
}

void GenerateXorArray()
{
    n=GetRand(10,100);
    for(int i=0;i<n;++i)
        XorArray[i]=GetRand(0,255);
}

void Encrypt()
{
    int num,len=strlen(Message);
    for(int i=0;i<len;++i)
    {
        num=(int)Message[i]^XorArray[i%n];
        Cipher[i*2]=ToHex(num/16);
        Cipher[i*2+1]=ToHex(num%16);
    }
}

void Decrypt()
{
    int num,len=strlen(Cipher);
    for(int i=0;i<len;i+=2)
    {
        num=ToOct(Cipher[i])*16+ToOct(Cipher[i+1]);
        DecMess[i/2]=(char)(num^XorArray[(i/2)%n]);
    }
}

int main()
{
    srand(time(NULL));
    GenerateXorArray();
    scanf("%s",Message);
    Encrypt();
    printf("Cipher = %s\n",Cipher);
    Decrypt();
    printf("Decrypted Message = %s\n",DecMess);
    return 0;
}
