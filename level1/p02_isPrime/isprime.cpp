#include <cmath>
#include <cstdio>
using namespace std;
bool isprime(int n);
int main() {
  int n;
  scanf("%d", &n);
  if (isprime(n))
    puts("n is a prime number\n");
  else
    puts("n is not a prime number\n");
  return 0;
}
bool isprime(int n) {
  int m = sqrt(n) + 0.5;
  if (n == 1) {
    return 0;
  }
  for (int i = 2; i <= m; ++i)
    if (n % i == 0) {
      return 0;
    }
  return 1;
}
