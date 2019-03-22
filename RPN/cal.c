//进行一次计算

#define EOF -1
#define N 200

extern int num[N/2];             //数字栈

int cal(int p_num, char opc)
{
        switch(opc)
        {
        case '+':
                return num[p_num] + num[p_num + 1];
                break;
        case '-':
                return num[p_num] - num[p_num + 1];
                break;
        case '*':
                return num[p_num] * num[p_num + 1];
                break;
        case '/':
                return num[p_num] / num[p_num + 1];
                break;
        default:
                return EOF;
        }
}
