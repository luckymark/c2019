#ifndef BIGDECIMAL_H
#define BIGDECIMAL_H

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
typedef long long LL;

const int L = 1360; //1360 720
const int P2L = 2048;
const LL BASE = 100000000L;
const int ITERATION_TIME = 17; // 17 16
const int DIV_ITERATION_TIME = ITERATION_TIME;
const int SQRT_ITERATION_TIME = ITERATION_TIME - 3;
const int DIGIT_POS = L - 10;

class BigDecimal
{
public:
	BigDecimal(LL , int);
	bool operator == (const BigDecimal &) const;
	bool operator > (const BigDecimal &) const;
	bool operator < (const BigDecimal &) const;
	bool operator != (const BigDecimal &) const;
	BigDecimal operator = (const BigDecimal &);
	BigDecimal operator + (const BigDecimal &);
	void operator += (const BigDecimal &);
	BigDecimal operator - (const BigDecimal &);
	void operator -= (const BigDecimal &);
	BigDecimal operator * (const BigDecimal &);
	void operator *= (const BigDecimal &);
	BigDecimal operator / (const BigDecimal &);
	BigDecimal operator << (int);
	void operator <<= (int x);
	BigDecimal mul(const BigDecimal &, const BigDecimal &);
	BigDecimal div2();
	void div2_Self();
	BigDecimal sqrt();
	void square_Self();
	void tid();
	void correctSize();
	void print();
	void printDecimal();

private:
	LL num[L];
	int size;
};

#endif
