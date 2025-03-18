#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 20;

void encrypt(char *str) {
  size_t len = strlen(str);
  for (size_t i = 0; i < len; i++) {
    if (islower(str[i])) {
      str[i] = (str[i] + 1 - 'a') % 26 + 'a';
      continue;
    }
    str[i] = (str[i] + 1 - 'A') % 26 + 'A';
  }
}

void decrypt(char *str) {
  size_t len = strlen(str);
  for (size_t i = 0; i < len; i++) {
    if (islower(str[i])) {
      // a: -1 % 26 == -(1 % 26) = -1
      // -1 + 26 = 25
      // (22 + 26) % 26 == 22
      str[i] = (str[i] - 1 - 'a' + 1000 * 26) % 26 + 'a';
      continue;
    }
    str[i] = (str[i] - 1 - 'A' + 26) % 26 + 'A';
  }
}

int main() {
  // b -> c
  // B -> C
  // Z -> A
  // z -> a
  char str[] = "aZAOINzscszzv";
  cout << "Before encrpying:" << str << endl;
  encrypt(str);
  cout << "After encrpying: " << str << endl;

  // C -> B
  // A -> z
  decrypt(str);
  cout << "After decrpying: " << str << endl;

  return 0;
}