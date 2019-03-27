#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int Prime1(int);
int Prime2(int);
int Prime3(const int);
int print(int);
int countTime(int(int), int);

int main()
{
	const int maxn = 2000;
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t1, t2, t3;
	cout << "Algorithm1:";
	t1 = countTime(Prime1, maxn);
	cout << "\n\nAlgorithm2:";
	t2 = countTime(Prime2, maxn);
	cout << "\n\nAlgorithm3:";
	t3 = countTime(Prime3, maxn);
	cout << "\n\nAlgorithm1: " << t1 << "ms\n"
		 << "Algorithm2: " << t2 << "ms\n"
		 << "Algorithm3: " << t3 << "ms\n";
}

int countTime(int getPrime(int), int maxn)
{
	int startTime = clock();
	getPrime(maxn);
	int endTime = clock();
	return (endTime - startTime);
}

int print(int i)
{
	if (i != 2)
		cout << " ";
	cout << i;
	return 0;
}

int Prime1(int maxn)
{
	for (int i = 2; i < maxn; i++)
	{
		bool prime = true;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				prime = false;
				break;
			}
		}
		if (prime)
		{
			print(i);
		}
	}
	return 0;
}

int Prime2(int maxn)
{
	for (int i = 2; i < maxn; i++)
	{
		int sq = sqrt(i);
		bool prime = true;
		for (int j = 2; j <= sq; j++)
		{
			if (i % j == 0)
			{
				prime = false;
				break;
			}
		}
		if (prime)
		{
			print(i);
		}
	}
	return 0;
}

int Prime3(const int maxn)
{
	
	bool notPrime[maxn+1] = { 0 };
	//这里用notPrime[maxn+1]，vs2017会报错，dev-cpp不报错，不知道为什么
	for (int i = 2; i <= maxn; i++)
	{
		if (!notPrime[i])
		{
			print(i);
			for (int j = i * i; j <= maxn; j += i)
				notPrime[j] = true;
		}
	}
	return 0;
}

int Prime4(int maxn)
{
	//Just for fun
	cout << "2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101 103 107 109 113 127 131 137 139 149 151 157 163 167 173 179 181 191 193 197 199 211 223 227 229 233 239 241 251 257 263 269 271 277 281 283 293 307 311 313 317 331 337 347 349 353 359 367 373 379 383 389 397 401 409 419 421 431 433 439 443 449 457 461 463 467 479 487 491 499 503 509 521 523 541 547 557 563 569 571 577 587 593 599 601 607 613 617 619 631 641 643 647 653 659 661 673 677 683 691 701 709 719 727 733 739 743 751 757 761 769 773 787 797 809 811 821 823 827 829 839 853 857 859 863 877 881 883 887 907 911 919 929 937 941 947 953 967 971 977 983 991 997 1009 1013 1019 1021 1031 1033 1039 1049 1051 1061 1063 1069 1087 1091 1093 1097 1103 1109 1117 1123 1129 1151 1153 1163 1171 1181 1187 1193 1201 1213 1217 1223 1229 1231 1237 1249 1259 1277 1279 1283 1289 1291 1297 1301 1303 1307 1319 1321 1327 1361 1367 1373 1381 1399 1409 1423 1427 1429 1433 1439 1447 1451 1453 1459 1471 1481 1483 1487 1489 1493 1499 1511 1523 1531 1543 1549 1553 1559 1567 1571 1579 1583 1597 1601 1607 1609 1613 1619 1621 1627 1637 1657 1663 1667 1669 1693 1697 1699 1709 1721 1723 1733 1741 1747 1753 1759 1777 1783 1787 1789 1801 1811 1823 1831 1847 1861 1867 1871 1873 1877 1879 1889 1901 1907 1913 1931 1933 1949 1951 1973 1979 1987 1993 1997 1999";
 } 
