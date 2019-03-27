#include<stdio.h>

void Hanoi(int n, char A, char B, char C);


int main()
{
    int n;
    char A = 'A';
    char B = 'B';
    char C = 'C';
    printf("Input the number of disks:");
    scanf("%d", &n);
    printf("Steps of moving 3 disks from A to B by means of C:\n");
    Hanoi(n, A, B, C);
    return 0;
}

void Hanoi(int n, char A, char B, char C)
{
    if (n == 1)
    {
        printf("Move %d: from %c to %c\n",n,A,B);
    }
    else
    {
        Hanoi(n - 1, A, C, B);
        printf("Move %d: from %c to %c\n",n,A,B);
        Hanoi(n - 1, C, B, A);
    }
}
