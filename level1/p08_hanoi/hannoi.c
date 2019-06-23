#include <stdio.h>
#include <math.h>

//这是核心函数，检测状态并执行挪的操作
void hanoi(int n, char from, char by, char to)
{
	if (n == 0)
    {
        return ;
    }
	hanoi(n - 1, from, to, by);
	move(from, to);
	hanoi(n - 1, by, from, to);
}
//这是执行挪的操作的函数
void move(char from, char to)
{
	printf("%c -> %c\n", from, to);
}

int main(void)
{
	int num, s = 1;
    for (int i = 1; i < num; ++i)
	{
		s *= 2;//计算需要挪几步
	}
	printf("你有几个饼要挪？\n");
	scanf("%d", &num);
    printf("你需要挪%d步" ,s);
	printf("你需要这么挪:\n");
	hanoi(num, 'a', 'b', 'c');
	return 0;
}
