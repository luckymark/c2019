#include <stdio.h>
#include <string.h>

#define WIDTH 100

int main()
{

    int i, j;
    char pads[WIDTH] = "";

    while (1)
    {
        for (i = 0; i < WIDTH - 1; i++)
        {
            strcat(pads, " ");
            printf("%s", pads);
            putchar('A');
            system("CLS");
        }

        for (i = 0; i < WIDTH - 1; i++)
        {
            pads[strlen(pads) - 1] = '\0';
            printf("%s", pads);
            putchar('A');
            system("CLS");
        }
    }

    return 0;
}
