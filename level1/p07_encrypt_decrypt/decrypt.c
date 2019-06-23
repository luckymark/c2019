#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef unsigned long UL;

extern const int LEN2;

UL n, d;

void decrypt(char cipher[LEN2])
{
        UL decrypt_single(UL c);

        //获取私钥
        FILE *fp = fopen("private_key.txt", "r");
        if(fp == NULL) {printf("Error004!\n"); exit(EOF);}
        fscanf(fp, "n = %lu", &n);
        while(fgetc(fp) != '\n') ;
        fscanf(fp, "d = %lu", &d);
        while(fgetc(fp) != '\n') ;
        fclose(fp);

        //test
        printf("n = %lu\td = %lu\n", n, d);

        //n的长度
        int len_n = 0;
        UL temp_n = n;
        while(temp_n)
        {
                temp_n = temp_n / 10;
                ++len_n;
        }

        //test
        printf("len_n = %d\n", len_n);

        //密文的长度
        const int len_cip = strlen(cipher);

        //把密文还原成一段只包含数字的字符串
        char num_str[LEN2];
        for(int i = 0; i < LEN2; ++i)
        {
                num_str[i] = '\0';
        }
        int ns_i = 0;   //num_str数组的下标
        int temp_i;     //把字母还原为数值
        for(int i = 0; i < len_cip; ++i)
        {
                if(cipher[i] >= 'a' && cipher[i] <= 'z')
                {
                        temp_i = cipher[i] - 97;
                        num_str[ns_i] = temp_i / 10;
                        num_str[ns_i + 1] = temp_i % 10;
                        ns_i = ns_i + 2;
                }
                else if(cipher[i] >= 'A' && cipher[i] <= 'Z')
                {
                        temp_i = cipher[i] - 39;
                        num_str[ns_i] = temp_i / 10;
                        num_str[ns_i + 1] = temp_i % 10;
                        ns_i = ns_i + 2;
                }
                else
                {
                        num_str[ns_i] = cipher[i] - '0';
                        num_str[ns_i + 1] = cipher[i + 1] - '0';
                        ns_i = ns_i + 2;
                        ++i;
                }
        }

        //test
        int j_j = 0;
        printf("num_str : ");
        for(int i = 0; i < 5; ++i)
        {
                int temp_j = j_j + len_n;
                for(; j_j < temp_j; ++j_j)
                {
                        printf("%d", (int)num_str[j_j]);
                }
                printf("\t");
        }
        printf("\n");

        //明文的长度
        int len = ns_i / len_n;

        //test
        printf("len = %d\n", len);

        //把上一步得到的字符串分割成单个的数
        UL num[len];
        UL temp_num;
        UL t10;
        for(int i = 0; i < len; ++i)
        {
                temp_num = 0;
                t10 = 1;
                for(int j = (i + 1) * len_n - 1; j >= i * len_n; --j)
                {
                        temp_num = temp_num + (int)num_str[j] * t10;
                        t10 = t10 * 10;
                }
                num[i] = temp_num;
        }

        //test
        printf("num : ");
        for(int i = 0; i < len; ++i)
        {
                printf("%lu ", num[i]);
        }
        printf("\n");

        //还原字符串
        char plain[len + 1];
        plain[len] = '\0';
        printf("temp_result : ");//test
        for(int i = 0; i < len; ++i)
        {
                //test
                UL temp_result = decrypt_single(num[i]);
                printf("%lu ", temp_result);

                plain[i] = (char)temp_result;
        }
        printf("\n");//test

        //test
        printf("The ASCII of plain : ");
        for(int i = 0; i < len; ++i)
        {
                printf("%d ", (int)plain[i]);
        }
        printf("\n");

        //输出
        printf("The plain text is: \n");
        printf("%s\n\n", plain);
}

UL decrypt_single(UL c)
{
        UL result = 1;
        for(UL i = 0; i < d; ++i)
        {
                result = result * c;
                result = result % n;
        }

        return result;
}
