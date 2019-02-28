#include<cstdio>

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

int main()
{
	int ageFa = 6 * 12 / gcd(6, 12);
	ageFa = ageFa * 7 / gcd(ageFa, 7);
	int ageSon = ageFa / 2;
	int res = ageSon + ageFa/12 + ageFa/6 + ageFa/7 + 5;
	printf("Diophantus was at the age of %d\n", res);
}
