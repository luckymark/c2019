#include <iostream>
#include <cstring>
#include <cstdio>
#include <ctime>

#include "bigDecimal.h"

BigDecimal N1(1, 0);
BigDecimal N2(2, 0);

BigDecimal::BigDecimal(LL number, int scale)
{
	memset(num, 0, sizeof num);
	size = 0;
	if (!number) size = 1;
	size += DIGIT_POS + scale;
	while (number)
	{
		num[size++] = number % BASE;
		number /= BASE;
	}
}

void BigDecimal::tid()
{
	for (register int s = 0; s < size; s++)
	{
		LL k = num[s], move = 0;
		while (k)
		{
			if (!move) num[s] = k % BASE;
			else num[s+move] += k % BASE;
			k /= BASE;
			move++;
		}
	}
}

void BigDecimal::correctSize()
{
	while (num[size] == 0 && size != 0)
	{
		size--;
	}
	size++;
	if (size == 0)
	{
		size = 1;
	}
}
int cnt = 0;

void prWis(int k)
{
	for (LL s = BASE/10; s > 0; s/=10)
	{
		printf("%lld", k/s);
		k -= k/s*s;
		cnt++;
	}
}

void BigDecimal::printDecimal()
{
	if (size > DIGIT_POS)
	{
		for (int s = size - 1; s >= 0; s--)
		{
			prWis(num[s]);
			if (s == DIGIT_POS && DIGIT_POS != 0)
			{
				printf(".");
			}
		}
	}
	else
	{
		prWis(num[DIGIT_POS]);
		printf(".");
		for (int s = DIGIT_POS - 1; s >= 0; s--)
		{
			prWis(num[s]);
		}
	}
	printf("\n");
	printf("Approximately %d digits\n", cnt);
}

BigDecimal BigDecimal::operator = (const BigDecimal number)
{
	for (register int s = L - 1; s >= 0; s--)
	{
		num[s] = number.num[s];
	}
	size = number.size;
	return *this;
}

bool BigDecimal::operator == (const BigDecimal &number) const
{
	if (size != number.size)
		return 0;
	for (int s = size - 1; s >= 0; s--)
	{
		if (num[s] != number.num[s])
			return 0;
	}
	return 1;
}

bool BigDecimal::operator > (const BigDecimal &number) const
{
	if (size != number.size)
		return size > number.size;
	for (register int s = size - 1; s >= 0; s--)
	{
		if (num[s] > number.num[s])
			return 1;
		if (num[s] < number.num[s])
			return 0;
	}
	return 0;
}

bool BigDecimal::operator < (const BigDecimal &number) const
{
	if (size != number.size)
		return size < number.size;
	for (register int s = size - 1; s >= 0; s--)
	{
		if (num[s] < number.num[s])
			return 1;
		if (num[s] > number.num[s])
			return 0;
	}
	return 0;
}

bool BigDecimal::operator != (const BigDecimal &number) const
{
	return !(*this == number);
}

BigDecimal BigDecimal::operator + (const BigDecimal number)
{
	BigDecimal tmp = *this;
	tmp.size = std::max(tmp.size, number.size);
	for (register int s = 0; s < tmp.size; s++)
	{
		tmp.num[s] += number.num[s];
	}
	tmp.tid();
	tmp.correctSize();
	return tmp;
}

BigDecimal BigDecimal::operator - (const BigDecimal number)
{
	BigDecimal tmp = *this;
	tmp.size = std::max(tmp.size, number.size);
	for (register int s = 0; s < tmp.size; s++)
	{
		tmp.num[s] -= number.num[s];
	}
	tmp.tid();
	for (register int s = 0; s < tmp.size; s++)
	{
		if (tmp.num[s] < 0)
		{
			tmp.num[s] += BASE;
			tmp.num[s+1]--;
		}
	}
	tmp.correctSize();
	return tmp;
}

BigDecimal BigDecimal::operator * (const BigDecimal number)
{
	BigDecimal tmp(0, 0);
	for (register int s = 0; s < size; s++)
	{
		for (register int t = 0; t < number.size; t++)
		{
			if (s + t - DIGIT_POS >= 0)
			{
				tmp.num[s + t - DIGIT_POS] += num[s] * number.num[t];
			}
		}
	}
	tmp.size = size + number.size - DIGIT_POS + 2;
	tmp.tid();
	tmp.correctSize();
	return tmp;
}

BigDecimal BigDecimal::div2()
{
	BigDecimal ret(0, 0);
	LL remain = 0;
	for (register int s = size - 1; s >= 0; s--)
	{
		LL k = num[s] + remain*BASE;
		ret.num[s] = k >> 1;
		remain = k & 1;
	}
	ret.size = size;
	ret.correctSize();
	return ret;
}

BigDecimal BigDecimal::operator << (const int shift)
{
	BigDecimal ret = (*this);
	for (register int s = 0; s < ret.size; s++)
	{
		ret.num[s] <<= shift;
	}
	ret.size = size + 2;
	ret.tid();
	ret.correctSize();
	return ret;
}

BigDecimal BigDecimal::operator / (const BigDecimal number)
{
	BigDecimal l(0, 0);
	BigDecimal r(1, L - DIGIT_POS - 1);
	BigDecimal m(1, 0);
	while (m * number > N1)
	{
		r = m;
		m = (l+r).div2();
	}
	BigDecimal ret(1, 0);
	for (int s = 0; s < ITERATION_TIME; s++)
	{
		ret = m * (N2 - (m * number));
		m = ret;
	}
	return ((*this) * ret);
}

BigDecimal BigDecimal::sqrt()
{
	BigDecimal k(1, 0);
	k = *this;
	for (int s = 0; s < ITERATION_TIME; s++)
		k = (k + (*this/k)).div2();
	return k;
}
