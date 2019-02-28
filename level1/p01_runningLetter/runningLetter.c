/**************************************************** 
先把空格存在数组内，再一次性输出以实现恒定速度
每次奔跑只需更改空格数组内的一个元素，效率较高
存储空格的数组为 95 是因为考虑终端光标还要占一格
暂停是为了看得清楚些
****************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

int main() {
	system("mode con lines=5 cols=50");		// 把命令行窗口宽度设置为 50
	char space[46];							// 用于预存单词前的空格
	char word[] = "test";					// 奔跑的单词

	int x = -1;							// 单词首字母横坐标 -1
	for (int i = 0; i < 46; ++i)		// 初始化空格数组
		space[i] = '\0';

	while (true) {
		while (++x < 45) {
			system("cls");
			space[x] = ' ';
			printf("%s%s", space, word);
			Sleep(100);
		}
		while (--x > -1) {
			system("cls");
			space[x] = '\0';
			printf("%s%s", space, word);
			Sleep(100);
		}
	}
	return 0;
}