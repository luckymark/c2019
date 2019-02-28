#include<iostream>
#include<Windows.h>
#define LENGTH 60 
using namespace std;
int main()
{
	int i=1,k=1;
	while(1)
	{
		for(i;;i+=k)
		{
			for(int j=1;j<i;j++)cout<<" ";
			cout<<"a";
			Sleep(60);
			system("cls");
			if(i==0||i==LENGTH)k*=-1;
		}
	}
	return 0;
}

