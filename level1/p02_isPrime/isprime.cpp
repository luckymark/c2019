#include <cmath>
#include <cstdio>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int m = sqrt(n) + 0.5;
  if (n == 1) {
    puts("n is not a prime number\n");
    return 0;
  }
  for (int i = 2; i <= m; ++i)
    if (n % i == 0) {
      puts("n is not a prime number\n");
      return 0;
    }
  puts("n is a prime number\n");
  return 0;
}