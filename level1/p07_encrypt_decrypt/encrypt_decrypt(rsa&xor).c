#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MINN 1000
#define MAXN 10000

typedef long long ll;

ll n, p, q, e, d, x, y, phi, iv, cipher[MAXN];
ll len, MesLen, primes[MAXN + 5], isprime[MAXN + 5];
char Message[MAXN], DecMes[MAXN];

int GetRand(int LowerBound, int UpperBound)
{
	return rand() % (UpperBound - LowerBound + 1) + LowerBound;
}

void GetPrime()
{
	memset(isprime, 1, sizeof(isprime));
	isprime[0] = isprime[1] = 0;
	for (int i = 2; i <= MAXN; i++)
	{
		if (isprime[i])primes[len++] = i;
		for (int j = 0; j < len; j++)
		{
			if (i*primes[j] > MAXN) break;
			isprime[i*primes[j]] = 0;
			if (i%primes[j] == 0) break;
		}
	}
}

ll gcd(ll a, ll b)
{
	if (b == 0)return a;
	return gcd(b, a%b);
}

ll pow_mod(ll a, ll b, ll mod)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1)ans = ans * a%mod;
		a = a * a%mod; b >>= 1;
	}
	return ans;
}

ll exgcd(ll a, ll b)
{
	ll d = a, tmp;
	if (b != 0)
	{
		tmp = x; x = y; y = tmp;
		d = exgcd(b, a % b);
		tmp = x; x = y; y = tmp;
		y -= (a / b) * x;
	}
	else
	{
		x = 1; y = 0;
	}
	return d;
}

ll mod_inverse(ll a, ll mod)
{
	exgcd(a, mod);
	return (mod + x % mod) % mod;
}

void init()
{
	srand(time(NULL));
	iv = GetRand(0, 255);
	GetPrime();
	p = primes[GetRand(1000, len - 1)];
	q = primes[GetRand(1000, len - 1)];
	n = p * q;
	phi = (p - 1)*(q - 1);
	e = GetRand(10, phi - 1);
	while (gcd(e, phi) != 1)
		e = GetRand(10, phi - 1);
	d = mod_inverse(e, phi);
}

ll RSA_enc(ll x)
{
	x = pow_mod(x, e, n);
	return x;
}

ll RSA_dec(ll x)
{
	return (char)pow_mod(x, d, n);
}

void get_enc()
{
	cipher[0] = iv;
	for (int i = 1; i <= MesLen; ++i)
		cipher[i] = RSA_enc(cipher[i - 1] ^ (ll)Message[i - 1]);
}

void get_dec()
{
	cipher[0] = iv;
	for (int i = 0; i < MesLen; ++i)
		DecMes[i] = (char)RSA_dec(cipher[i + 1]) ^ cipher[i];
}

int main()
{
	init();
	scanf("%s", Message);
	MesLen = strlen(Message);
	get_enc();
	printf("cipher is : ");
	for (int i = 1; i <= MesLen; ++i)
		printf("%010I64d", cipher[i]);
	printf("\n");
	get_dec();
	printf("Decrypted Message is : %s", DecMes);
	return 0;
}
