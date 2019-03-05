#include <stdio.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <string.h>

int main()

{
	//通过函数loctl();获得终端界面的参数
	//定义winsize结构体变量
	struct winsize size;
	//tiocswinsz命令取到此结构的新值
	ioctl(STDIN_FILENO,TIOCGWINSZ,&size);
	printf("%d\n" ,size.ws_col);
	printf("%d\n" ,size.ws_row);

	//查了一堆后，我理解了Linux上难点在哪里(笑)
	//我仰天大呼：要一个计时器！
	//室友说
	//不，你需要睡眠
	//(这是一个双关笑话)

	int i = 0 ,j = 0 ,k = 0;

	while( 1 )
	{
		while( i < size.ws_col - 2 )//每一遍向右移动一个字符
		{
			while( j < i )//每一遍输出k个空格
			{
				printf(" ");
				j++;
			}
			printf("R\r");

			i++;
			
			j = 0;
			usleep(63240);//这是笑点
			fflush(stdout);


		}

		while( i > 0 )
		{
			while( j < i )
			{
				printf(" ");
				j++;
			}
			printf("R \r");
		
			i--;
			
			j = 0;
			usleep(63240);
			fflush(stdout);

		}
		
		i = 0;
		continue;
	}
	
	printf("\n");

	return 0 ;
}
