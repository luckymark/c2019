#include<stdio.h>
#include<stdlib.h>

void hanoi(int n, char A, char B, char C);

int main()
{
        FILE *fp1 = fopen("input.txt", "r");
        if(fp1 == NULL)
        {
                printf("File \"input.txt\" cannot found.\n");
                exit(EOF);
        }
        int num;        //圆盘的数量
        char A = 'A';
        char B = 'B';
        char C = 'C';   //柱子的名称

        fscanf(fp1, "%d", &num);

        fclose(fp1);

        FILE *fp2 = fopen("output.txt", "a");
        if(fp2 == NULL)
        {
                printf("File \"output.txt\" cannot found.\n");
                exit(EOF);
        }

        fprintf(fp2, "把%d个盘子从%c移动到%c上\n", num, A, C);
        fclose(fp2);

        hanoi(num, A, B, C);

        fp2 = fopen("output.txt", "a");
        fprintf(fp2, "移动完毕\n");
        fclose(fp2);

        return 0;
}
