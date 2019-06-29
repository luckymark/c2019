#include <cstdio>
#include <set>
#define MAX_RANGE /*(2 << 29 - 1)*/ 100000
using namespace std;
int main()
{
    const int n=101;//The range of number you want to prove
    set<int> storage_Prime;

    int A[MAX_RANGE] = {0}; //Use zero to represent this is a prime.Use one to represent this is a prime.
    int num = 0;
    //generate Prime
    int TempOfPrime[MAX_RANGE];
    for (int i = 2; i <= n; i++)
    {
        if (!A[i])
        {
            num += 1;
            TempOfPrime[num] = i; //Attention:First element is a[1]
        }
        for (int j = 1; j <= num && i * TempOfPrime[j] <= n; j++)
        {
            A[i * TempOfPrime[j]] = 1;
            if ((i % TempOfPrime[j]) == 0)
                break;
        }
        for (int i = 2; i <= n; i++)
        {
            if (!A[i])
            {
                storage_Prime.insert(i);
            }
        }
    }
    for(int i=4;i<n;i+=2)
    {
        int flag=1;//有问题
        for(set<int>::const_iterator citer=storage_Prime.begin();(*citer)<=i&&citer!=storage_Prime.end();citer++)
        {
            int remainder=i-*citer;
            if(storage_Prime.find(remainder) != storage_Prime.end())//If find in Prime Set
            {
                flag=0;//
            }
        }
        if(flag)
        {
            printf("Goldbach is not right.");
            return 0;
        }
    }
    printf("Goldbach is right.");
}
