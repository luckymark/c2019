#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char msg[100000];
    int chose, num = 0;
    for (;;)
    {
        printf("[1] encrypt \n[2] decrypt \n");
        scanf("%d", &chose);
        switch (chose)
        {
        case 1:
            printf("Please input yuor plaintext:");
            fflush(stdin);
            gets(msg);
            printf("\nThe ciphertext is:");
            for (size_t i = 0; i < strlen(msg); i++)
            {
                printf("%d ", msg[i]);
            }
            break;
        case 2:
            printf("Please input yuor ciphertext:");
            fflush(stdin);
            gets(msg);
            printf("\nThe plaintext is:");
            for (size_t i = 0; i < strlen(msg); i++)
            {
                if (msg[i] != 32)
                {
                    num = num * 10 + msg[i] - 48;
                }
                else
                {
                    printf("%c", num);
                    num = 0;
                }
            }
            if (num != 0)
            {
                printf("%c", num);
                num = 0;
            }
            break;
        default:
            printf("wrong");
            break;
        }
        system("pause");
    }
    return 0;
}
