#include<stdio.h>
#include<stdlib.h>

const int LEN1 = 16;     //明文的最大长度
const int LEN2 = 288;    //密文最大长度

void encrypt(char plain[]);
void decrypt(char cipher[]);

int main()
{
        begin:
                ;

        printf("Please input your instructions: \n");
        printf("1: to encrypt a plain text\n");
        printf("2: to decrypt a cipher text\n");
        printf("3: to end up the program.\n");

        char ch;
        scanf("%c", &ch);
        while(getchar() != '\n')        ;

        if(ch == '1')
        {
                char plain[LEN1];
                for(int i = 0; i < LEN1; ++i)
                {
                        plain[i] = '\0';
                }

                printf("Please input your plain text: \n");
                scanf("%s", plain);
                while(getchar() != '\n')        ;
                printf("%s\n", plain);  //test
                encrypt(plain);
                goto begin;
        }
        else if(ch == '2')
        {
                char cipher[LEN2];
                for(int j = 0; j < LEN2; ++j)
                {
                        cipher[j] = '\0';
                }
                printf("Please input your cipher text: \n");
                scanf("%s", cipher);
                while(getchar() != '\n')        ;
                printf("%s\n", cipher);   //test
                decrypt(cipher);
                goto begin;
        }
        else if(ch == '3')
        {
                return 0;
        }
        else
        {
                printf("Invalid instruction!\n");
                goto begin;
        }

        return 0;
}
