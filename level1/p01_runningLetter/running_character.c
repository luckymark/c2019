#include<stdio.h>
#include<windows.h>

int main(int argc, char *argv[])
{
        int columns;
	int n = 0, s = -1, i;

	//获得console的宽度
	CONSOLE_SCREEN_BUFFER_INFO csbi;

        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

        const int N = columns;
        char c[N + 1];

        c[N] = 0;   //在字符串末尾加上终止符
        for(i = 0; i < N; ++i)
                c[i] = ' ';

	while(1)
	{
		if(n == N - 1 || n == 0)	++s;
		//字母跑到了屏幕边缘

		c[n] = 'R';     //字母下一次的跑动位置

		//跑一步
		system("cls");
		printf("%s ", c);

		c[n] = ' ';

		if(s % 2)	--n;
		else ++n;
	}

	return 0;
}

