#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
typedef long long LL;

using namespace std;

LL P = 43, Q = 59, E = 13;
LL N = P * Q;
LL PHI_N = (P-1) * (Q-1);

int mLength, cLength;

vector<LL> cipherText;

void exgcd(LL a, LL b, LL &x, LL &y)           //扩展欧几里得算法，求逆元
{
	if (b == 0)
	{
		x = 1, y = 0;
		return;
	}
	exgcd(b, a%b, x, y);
	LL tmp = y;
	y = x - y * (a / b);
	x = tmp;
}

LL qpow(LL x, LL n, LL mod)                    //快速幂，计算 x^n % mod的值
{
	LL ret = 1;
	while (n)
	{
		if (n&1)
			ret = (ret * x) % mod;
		x = (x * x) % mod;
		n >>= 1;
	}
	return ret;
}

void encrypt(string text)
{
	int len = text.length();
	for (int s = 0; s < len; s++)
	{
		LL val = qpow(text[s], E, N);     //加密，C = M^E % N
		cipherText.push_back(val);
	}
}

void decrypt(string &res)                     
{
	LL D, F;
	exgcd(E, PHI_N, D, F);   //D是 DE===1 (mod phi(N)) 即E对于(P-1)*(Q-1)的逆元
	if (D < 0)
		D += PHI_N;
	for (int s = 0; s < cipherText.size(); s++)
	{
		LL val = qpow(cipherText[s], D, N);  //解密，M = C^D % N
		res += val;
	}
}

int main()
{
	string message;
	getline(cin, message);
	encrypt(message);
	cout << "Encryped number string:\n";
	for (int s = 0; s < cipherText.size(); s++)
		cout << cipherText[s] << " ";
	string decoded;
	decrypt(decoded);
	cout << "\nDecryped message:\n" << decoded << endl;
}

