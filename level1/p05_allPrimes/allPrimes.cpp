#include <cmath>
#include <cstdio>
#include <ctime>
using namespace std;
int main() {
  clock_t start = clock();
  printf("2 3 5");
  for (int i = 7; i < 998; i += 2) {
    int m = sqrt(i), j;
    for (j = 3; j <= m; j += 2)
      if (i % j == 0)
        break;
    if (j > m)
      printf(" %d", i);
  }
  putchar('\n');
  clock_t end = clock();
  printf("it costs %ldms\n", end - start);
  return 0;
}