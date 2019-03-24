#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
typedef long long LL;

const int L = 1360;
const LL BASE = 100000000L;
const int ITERATION_TIME = 14;
int DIGIT_POS = L - 10;

class BigDecimal
{
public:
	BigDecimal(LL , int);
	bool operator == (const BigDecimal &) const;
	bool operator > (const BigDecimal &) const;
	bool operator < (const BigDecimal &) const;
	bool operator != (const BigDecimal &) const;
	BigDecimal operator = (const BigDecimal);
	BigDecimal operator + (const BigDecimal);
	BigDecimal operator - (const BigDecimal);
	BigDecimal operator * (const BigDecimal);
	BigDecimal operator / (const BigDecimal);
	BigDecimal operator << (const int);
	BigDecimal div2();
	BigDecimal sqrt();
	void tid();
	void correctSize();
	void print();
	void printDecimal();

private:
	LL num[L];
	int size;
};
