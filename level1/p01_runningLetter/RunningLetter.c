#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int WIDTH = 100, TIME = 100;
char word[128] = "RunningLetter", WIDTHLOCK[128];

void Run(int i)
{
    for(size_t t = 0; t < i; t++)
    {
        printf(" ");
    }
    printf("%s",word);
    Sleep(TIME);
    system("cls");
}

int main(int argc, char const *argv[])
{
    sprintf(WIDTHLOCK,"mode con cols=%d", WIDTH + strlen(word));
    system(WIDTHLOCK);

    Rem:for(size_t i = 0; i < WIDTH; i++)
    {
        Run(i);
    }

    for(size_t i = WIDTH; i > 0; i--)
    {
        Run(i);
    }
    goto Rem;
    return 0;
}
