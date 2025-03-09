#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 20;

void encrypt(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len; ++i) {
    // if (str[i] == 'z' || str[i] == 'Z') {
    //   if (islower(str[i]))
    //     str[i] = 'a';
    //   else
    //     str[i] = 'A';
    // } else {
    //   str[i]++;
    // }

    if (islower(str[i])) {
      str[i] = ((str[i] + 1 - 'a') % 26) + 'a';
      continue;
    }
    str[i] = ((str[i] + 1 - 'A') % 26) + 'A';
  }
}

void decrypt(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len; ++i) {
    if (islower(str[i]))
      str[i] = (str[i] - 1 - 'a' + 26) % 26 + 'a';
    else
      str[i] = (str[i] - 'A' - 1 + 26) % 26 + 'A';
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