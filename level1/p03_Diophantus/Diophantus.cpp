#include <cstdio>
using namespace std;
int main() {
  for (double i = 0;; i += 1)
    if (i / 6 + i / 12 + i / 7 + 5 + i / 2 + 4 == i) {
      printf("Diophantus was %0.f when his son died\n", i - 4);
      return 0;
    }
}