#include <cstdio>
#include <cstdlib>
#include <unistd.h>
using namespace std;
//Tested on Linux
#define clean() printf("\033[2J");
int main() {
  int f = 0, p = 0;
  while (1) {
    if (p == 20)
      f = 1;
    if (p == 0)
      f = 0;
    sleep(1);
    clean();
    for (int i = 0; i < p; ++i)
      printf(" ");
    puts("Howard");
    if (f)
      --p;
    else
      ++p;
  }
  return 0;
}
