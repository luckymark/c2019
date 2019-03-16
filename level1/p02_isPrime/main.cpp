#include <iostream>
#include<cmath>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	int a;
	cin>>a;
	for(int i=2;i<=sqrt(a);i++)
	{
		if(a%2==0)
		{
			cout<<"no!";
			return 0;
		}
	}
	cout<<"yes";
	return 0;
}
