//输入逆波兰表达式，求表达式的值

#include<stdio.h>
#include<stdlib.h>

#define N 200

int num[N/2];             //数字栈

int cal(int , char );     //运算函数，参数分别是数字栈栈顶的指针和运算符
int ext(char exp[]);      //提取数

int main()
{
        FILE *fp = fopen("RPN.txt", "r");
        if(fp == NULL)
        {
                printf("Error!000\n");
                exit(EOF);
        }

        int p_num = 0;          //指向数字栈的栈顶
        char opc;               //运算符
        char exp[N];            //表达式栈
        int p_exp = 0;          //指向表达式栈的栈顶

        //input and calculate
        for(;;)
        {
                exp[p_exp] = fgetc(fp);

                //如果读入数字，则继续读取
                if(exp[p_exp] >= '0' && exp[p_exp] <= '9')
                {
                        ++p_exp;
                }
                //如果读入空格，表示读完了一个整数
                //提取这个整数，压入数字栈
                //使表达式栈的指针重新指向栈底
                else if(exp[p_exp] == ' ')
                {
                        exp[p_exp] = '\0';
                        num[p_num] = ext(exp);
                        ++p_num;
                        p_exp = 0;
                }
                //如果读入运算符，则立即进行运算
                //弹出数字栈中的两个元素，把计算得到的新元素压入数字栈中
                //使数字栈的指针重新指向数字栈的栈顶
                //读入运算符后面的空格
                else
                {
                        opc = exp[p_exp];
                        num[p_num - 2] = cal(p_num - 2, opc);
                        --p_num;
                        //如果读到换行符
                        //使数字栈的指针指向数字栈的栈底
                        //跳出循环
                        if(fgetc(fp) == '\n')
                        {
                                --p_num;
                                break;
                        }
                }
        }

        fclose(fp);

        //output
        if(p_num == 0)
                printf("%d\n", num[p_num]);
        //如果数字栈的指针没有指向数字栈的栈底
        //说明输入的逆波兰表达式不合法
        else printf("Wrong expression!\n");

        return 0;
}
