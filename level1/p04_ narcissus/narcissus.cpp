#include <cstdio>
using namespace std;
int main() {
  int f = 0;
  for (int i = 1; i <= 9; ++i)
    for (int j = 0; j <= 9; ++j)
      for (int k = 0; k <= 9; ++k)
        if (i * i * i + j * j * j + k * k * k == i * 100 + j * 10 + k) {
          if (f)
            printf(" ");
          else
            f = 1;
          printf("%d%d%d", i, j, k);
        }
  putchar('\n');
}