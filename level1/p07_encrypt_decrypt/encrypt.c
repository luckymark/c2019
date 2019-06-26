#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef unsigned long UL;

extern const int LEN1;

UL n, e;

void encrypt(char plain[LEN1])
{
        UL encrypt_single(int m);       //给单个字符加密的函数

        //获取公钥
        FILE *fp = fopen("public_key.txt", "r");
        if(fp == NULL) {printf("Error003!\n"); exit(EOF);}
        fscanf(fp, "n = %lu", &n);
        while(fgetc(fp) != '\n') ;
        fscanf(fp, "e = %lu", &e);
        while(fgetc(fp) != '\n') ;
        fclose(fp);

        //test
        printf("n = %lu e = %lu\n", n, e);

        //获取n的位数
        UL temp_n = n;
        int len_n = 0;
        while(temp_n)
        {
                temp_n = temp_n / 10;
                ++len_n;
        }
        //test
        printf("len_n = %d\n", len_n);

        //明文的长度
        const int len = strlen(plain);

        //test
        printf("len = %d\n", len);

        //获取每个字符的ASCII码
        //对每个字符加密
        int val_pla[len];
        UL cry_pla[len];
        for(int i = 0; i < len; ++i)
        {
                val_pla[i] = (int)plain[i];
                cry_pla[i] = encrypt_single(val_pla[i]);
        }

        //test
        printf("val_pla : ");
        for(int i = 0; i < len; ++i)
        {
                printf("%d\t", val_pla[i]);
        }
        printf("\ncry_pla : ");
        for(int i = 0; i < len; ++i)
        {
                printf("%lu\t", cry_pla[i]);
        }
        printf("\n");

        //把cry_pla数组中的数存到一个字符数组中，每个数占len_n位，不足的在前面补0
        char ori_cipher[len * len_n];
        for(int i = 0; i < len * len_n; ++i)
        {
                ori_cipher[i] = '\0';
        }
        UL temp_cry;
        printf("ori_cipher : ");        //test
        for(int i = 0; i < len; ++i)
        {
                temp_cry = cry_pla[i];
                for(int j = (i + 1) * len_n - 1; j >= i * len_n; --j)
                {
                        ori_cipher[j] = temp_cry % 10;
                        temp_cry = temp_cry / 10;
                        printf("%d ", (int)ori_cipher[j]);
                }
                printf("\n");
        }

        //test
        printf("The ASCII of ori_cipher : ");
        for(int i = 0; i < len * len_n; ++i)
        {
                printf("%d ", (int)ori_cipher[i]);
        }
        printf("\n");

        //处理ori_cipher数组
        //相邻两个数拼接成一个两位数
        //当这个两位数小于52时，转换成字母
        //00对应a，51对应Z
        //大于52时不作处理
        char cipher[len * len_n];
        for(int i = 0; i < len * len_n; ++i)
        {
                cipher[i] = '\0';
        }
        int temp_j;     //相邻两个数拼接成的两位数
        int cip_j = 0;      //cipher数组的下标
        for(int i = 0; i < len * len_n; ++i)
        {
                if(i + 1 == len * len_n)
                {
                        cipher[cip_j] = ori_cipher[i] + 48;
                        ++cip_j;
                        break;
                }
                temp_j = (int)ori_cipher[i] * 10 + (int)ori_cipher[i + 1];
                if(temp_j < 26)
                {
                        cipher[cip_j] = temp_j + 97;
                        ++cip_j;
                        ++i;
                }
                else if(temp_j < 52)
                {
                        cipher[cip_j] = temp_j + 39;
                        ++cip_j;
                        ++i;
                }
                else
                {
                        cipher[cip_j] = ori_cipher[i] + 48;
                        cipher[cip_j + 1] = ori_cipher[i + 1] + 48;
                        cip_j = cip_j + 2;
                        ++i;
                }
        }

        //test
        int len_cip;
        len_cip = strlen(cipher);
        printf("len_cip = %d\n", len_cip);
        printf("cip_j = %d\n", cip_j);

        //输出
        printf("The cipher text is: \n");
        printf("%s\n\n", cipher);
}

UL encrypt_single(int m)
{
        UL result = 1;
        for(UL i = 0; i < e; ++i)
        {
                result = result * m;
                result = result % n;
        }

        return result;
}
