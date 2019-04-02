#include <iostream>
#include <string>
using namespace std;
int encrypt();
int decrypt();
void leave();
int main() {
  cout << "请选择操作\n1)    加密\n2)    解密\n其他) 退出" << endl;
  char item = getchar();
  switch (item) {
    case '1':
      if (encrypt()) cout << "程序出错" << endl;
      main();
    case '2':
      if (decrypt()) cout << "程序出错" << endl;
      main();
    default:
      leave();
  }
}
int encrypt() {
  cout << "请输入要加密的内容" << endl;
  string origin;
  cin >> origin;
  char encrypted[2 * origin.length() + 5];
  getchar();
  for (int i = 0; i < origin.length(); ++i) {
    int e = origin[i] * 13 + 14;
    encrypted[2 * i + 1] = e / 95 + 31;
    encrypted[2 * i] = e % 95 + 31;
  }
  cout << "加密后的内容为：\n" << encrypted << endl;
  return 0;
}
int decrypt() {
  cout << "请输入加密后的内容" << endl;
  string encrypted;
  cin >> encrypted;
  char origin[encrypted.length() / 2 + 5];
  getchar();
  for (int i = 0; i < encrypted.length() / 2; ++i) {
    int e = encrypted[2 * i] + encrypted[2 * i + 1] * 95 - 96 * 31;
    origin[i] = (e - 14) / 13;
  }
  cout << "原内容为：\n" << origin << endl;
  return 0;
}
void leave() {
  cout << "非法指令，退出。。。" << endl;
  exit(0);
}

