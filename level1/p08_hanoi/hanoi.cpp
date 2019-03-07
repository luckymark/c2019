#include <iostream>
#include <string>
using namespace std;
void move(int n, char x, char y, char z) {
  if (n == 1)
    cout << "Move the 1st disk from " << x << " to " << z << endl;
  else {
    string ordinal;
    if (n % 100 / 10 == 1)
      ordinal = "th";
    else
      switch (n % 10) {
        case 1:
          ordinal = "st";
          break;
        case 2:
          ordinal = "nd";
          break;
        case 3:
          ordinal = "rd";
          break;
        default:
          ordinal = "th";
      }
    move(n - 1, x, z, y);
    cout << "Move the " << n << ordinal << " disk from " << x << " to " << z
         << endl;
    move(n - 1, y, x, z);
  }
}
int main() {
  int n;
  cin >> n;
  move(n, 'A', 'B', 'C');
}