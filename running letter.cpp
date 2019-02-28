#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
const int length = 80;
int main()
{
	string A;
	cin >> A;
	while (1)   //it can run forever
	{
		for (int i = 1; i <= length; i++)
		{
			for (int b = i; b >= 1; b--)
				cout << " ";
			cout << A;
			Sleep(100); //prevent the word moveing too fast to see it
			system("cls");
		}

		for (int i = length; i >= 1; i--)
		{
			for (int b = i; b >= 1; b--)
				cout << " ";
			cout << A;
			Sleep(200);
			system("cls");
		}
	}
}
