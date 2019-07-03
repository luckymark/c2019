#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

char sentence[1000], enc[3][334], decr[1000];

//我真的不懂大佬们说的RSA加密算法啥的……就弄了一个后移三位凯撒+三层栅栏（虽然听说栅栏不适合拿来当很长的字符串的加密
//dbq我还是没弄懂怎么多文件，下个作业再试

void encrypt()
{
	int line = 0, row = 0;
	cout << "加密模式/请输入需要加密的字符串（不含空格）：" << endl;
	cin >> sentence;
	for (int i = 0; sentence[i] != '\0'; i++)
	{
		enc[row][line] = sentence[i] + 3;
		if (row == 2)
		{
			row = 0;
			line++;
			continue;
		}
		row++;
	}
	for (row = 0; row < 4; row++)
	{
		printf("%s", enc[row]);
	}
	printf("\n");
	return;
}

void decrypt()//error
{
	int line = 0, row = 0, ex_row = 0, count = 0,line_num=0;
	cout << "解密模式/请输入用该方式加密的字符串（不含空格）：" << endl;
	cin >> sentence;
	for (count;; count++)
	{
		if (sentence[count] == '\0')
		{
			ex_row = count % 3;
			line_num = (count/3);
			break;
		}
	}
	for (int i = 0; i != count; i++)
	{
		enc[row][line] = sentence[i] - 3;
		if (ex_row == 0)
		{
			if (line == line_num - 1)
			{
				line = 0;
				row++;
			}
			else line++;
		}
		else if (ex_row == 1)
		{
			if (row == 0)
			{
				if (line == line_num)
				{
					line = 0;
					row++;
				}
				else line++;
			}
			else
			{
				if (line == line_num-1)
				{
					line = 0;
					row++;
				}
				else line++;
			}
		}
		else if (ex_row == 2)
		{
			if (line == line_num)
			{
				line = 0;
				row++;
			}
			else line++;
		}
	}
	for (line = 0; line <= line_num; line++)
	{
		for (row = 0; row < 3; row++)
		{
			printf("%c", enc[row][line]);
		}
	}
	printf("\n");
	return;
}

int main()
{
	int choose;
	while (1) 
	{
		memset(sentence, 0, sizeof sentence);
		memset(enc, 0, sizeof enc);
		memset(decr, 0, sizeof decr);
		cout << "扣1进入加密模式；扣2进入解密模式；扣0退出；" << endl;
		cin >> choose;
		if (choose == 1) encrypt();
		if (choose == 2) decrypt();
		if (choose == 0) break;
	}
}