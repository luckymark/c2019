#include <stdio.h>

void main ()
{
    int vis[10000];
    int cnt;
    
	for (int i = 2; i <= 10000; ++i)
	{
		if (!vis[i])
			p[++cnt] = i;
		for (int j = 1; j <= cnt; ++j)
		{
			if (i * p[j] > n)
				break;
			vis[i * p[j]] = 1; //p[j]是i*p[j]的最小素因子 
			if (i % p[j] == 0) //再往后p[j]就不是最小素因子了 
				break;
		}
	}
}