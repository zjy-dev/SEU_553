#include <iostream>
using namespace std;

int main() {
  int n;
  "5,101,213,325,437,549";
  cin >> n;
  int sum = 0, temp;
  for (int i = 0; i < n; ++i) {
    // cin.ignore(); // 忽略逗号
    // cin.get();
    cin >> temp;
    sum += temp;
  }
  cout << sum;

  return 0;
}
