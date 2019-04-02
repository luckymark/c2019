#include <cmath>
#include <cstdio>
using namespace std;
bool solve(int i, int *p);
int main() {
  int p[100] = {2, 3, 5, 0};
  int a = 3;
  for (int i = 7; i < 100; i += 2) {
    int m = sqrt(i), j;
    for (j = 3; j <= m; j += 2)
      if (i % j == 0) break;
    if (j > m) p[a++] = i;
  }
  int i = 2;
  while (solve(i += 2, p))
    ;
}
bool solve(int i, int *p) {
  for (int j = 0; p[j]; ++j)
    for (int k = 0; p[k]; ++k)
      if (p[j] + p[k] == i) {
	printf("%d = %d + %d\n", i, p[j], p[k]);
	if (i == 100) return 0;
	i += 2;
	return 1;
      }
  return 1;
}

