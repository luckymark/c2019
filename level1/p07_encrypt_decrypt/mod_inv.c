//计算e对于phi_n的模反元素

//用扩展欧几里得算法可求模反元素
//但我递归学得太差了
//先写一个遍历以后再来优化吧

typedef unsigned long UL;

UL mod_inv(UL e, UL phi_n)
{
        for(UL i = 0; ; ++i)
        {
                if((e * i) % phi_n == 1)
                {
                        return i;
                }
        }
}
