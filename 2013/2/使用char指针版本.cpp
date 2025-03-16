#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 20;

void encrypt(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len; ++i) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      // 'c' -> 'd'
      // 'z' -> 'a' (27 1)
      str[i] = 'a' + (str[i] + 1 - 'a') % 26;
      continue;
    }

    str[i] = 'A' + (str[i] + 1 - 'A') % 26;
  }
}

void decrypt(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len; ++i) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] = 'a' + (str[i] - 1 - 'a' + 26) % 26;
      continue;
    }
    str[i] = 'A' + (str[i] - 1 - 'A' + 26) % 26;
  }
}

int main() {
  char str[] = "aZAOINzscszzv";
  //   cin >> str;
  cout << "Before encrpying:" << str << endl;
  encrypt(str);
  cout << "After encrpying: " << str << endl;
  decrypt(str);
  cout << "After decrpying: " << str << endl;

  return 0;
}