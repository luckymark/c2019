#include <stdio.h>
//1/6x+1/12x+1/7x+5+1/2x+4=x
//ת��Ϊ14x+7x+12x+5*84+42x+4*84=84x
int main()
{
    int i;
    for(i = 0;i < 200;i++)           //0-150ÿ����Ͷ����ԣ��ܻ�������ꡣ
    {
        if(14*i + 7*i + 12*i + 5*84 + 42*i + 4*84 == 84*i)
            break;
    }
    printf("year = %d",i);
    return 0;
}
