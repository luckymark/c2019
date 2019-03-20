#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
typedef long long LL;

const int L = 720;
const LL BASE = 100000000L;
const int ITERATION_TIME = 13;
int DIGIT_POS = L - 20;

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
	BigDecimal DIV(const BigDecimal);
	BigDecimal div2();
	BigDecimal mul2();
	BigDecimal sqrt();
	void tid();
	void correctSize();
	void print();
	void printDecimal();

private:
	LL num[L];
	int size;
};
