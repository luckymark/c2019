#include<bits/stdc++.h>

using namespace std;

int main()
{
	int stack[100];
	int length = 0;
	char c;
	c = getchar();
	while (c != '\n')
	{
		if (isdigit(c))
		{
			int cur = 0;
			while (isdigit(c))
			{
				cur = cur * 10 + c - '0';
				c = getchar();
			}
			stack[length] = cur;
			length++;
		}
		if (isspace(c))
		{
			if (c == '\n')
				break;
		}
		else
		{
			if (length < 2)
			{
				cout << "Wrong input.\n";
				system("pause");
				return 1;
			}
			length--;
			switch (c)
			{
			case '+':
				stack[length - 1] += stack[length]; break;
			case '-':
				stack[length - 1] -= stack[length]; break;
			case '*':
				stack[length - 1] *= stack[length]; break;
			case '/':
				stack[length - 1] /= stack[length]; break;
			default:
				cout << "Wrong input.\n";
				system("pause");
				return 1;
			}
		}
		c = getchar();
	}
	if (length == 1)
	{
		cout << "The answer is " << stack[0] <<",\n";
		system("pause");
		return 0;
	}
	else
	{
		cout << "Wrong input.\n";
		system("pause");
		return 1;
	}
}
