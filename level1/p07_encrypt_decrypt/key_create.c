#include<stdio.h>
#include<stdlib.h>
#define LEN 100         //输入字符串的最大长度
typedef unsigned long UL;

int p, q;               //两个不等质数
UL n;                  //p与q的乘积，公钥1,私钥1
UL phi_n;              //n的欧拉函数
const int e = 65537;    //公钥2
UL d;                  //e对于phi_n的模反元素，私钥2

int rand_prime();       //随机返回质数的函数
UL phi(int p, int q);           //计算n的欧拉函数的函数
UL mod_inv(UL a, UL b);  //计算e对于phi_n的模反元素的函数

int main()
{
        int mark;       //若mark = 0，说明e与phi_n互质
        do
        {
                mark = 0;

                //随机选择两个不等质数p，q
                p = rand_prime();
                while((q = rand_prime()) == p)  ;

                //计算p和q的乘积n
                n = (UL)p * q;

                //计算n的欧拉函数phi_n
                phi_n = phi(p, q);
                if(phi_n % e == 0 || e > phi_n)
                        mark = 1;
        }while(mark);


        //计算e对于phi_n的模反元素d
        d = mod_inv((UL)e, phi_n);

        //测试
        printf("p=%d q=%d\nn=%lu\nphi_n=%lu\ne = %d\nd=%lu\n", p, q, n, phi_n, e, d);

        //封装公钥
        FILE *fp1 = fopen("public_key.txt", "w");
        if(fp1 == NULL) {printf("Error001!\n"); exit(EOF);}
        fprintf(fp1, "n = %lu\ne = %d\n", n, e);
        fclose(fp1);

        //封装密钥
        FILE *fp2 = fopen("private_key.txt", "w");
        if(fp2 == NULL) {printf("Error002!\n"); exit(EOF);}
        fprintf(fp2, "n = %lu\nd = %lu\n", n, d);
        fclose(fp2);

        return 0;
}
