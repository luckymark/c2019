#include <iostream>
#include <string>
using namespace std;
void move(int n, char x, char y, char z);
int main() {
  int n;
  cin >> n;
  move(n, 'A', 'B', 'C');
}
void move(int n, char x, char y, char z) {
  if (n == 1) {
    cout << "Move a disk from " << x << " to " << z << endl;
    return;
  }
  move(n - 1, x, z, y);
  cout << "Move a disk from " << x << " to " << z << endl;
  move(n - 1, y, x, z);
  return;
}
