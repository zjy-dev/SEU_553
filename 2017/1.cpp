#include <bits/stdc++.h>
using namespace std;

unsigned str_to_int(const char *const s) {
  unsigned ans = 0;
  size_t len = strlen(s);

  for (size_t i = 0; i < len; i++)
    ans = (ans * 10) + (s[i] - '0');
  // (ans *= 10) += (s[i] - '0');

  return ans;
}

int main() {
  ifstream ifs("date.txt");
  if (!ifs) {
    cerr << "The file can not be opened." << endl;
    exit(1);
  }

  const char *month_map[] = {
      "",     "January", "February",  "March",   "April",    "May",     "June",
      "July", "August",  "September", "October", "November", "December"};

  string line;
  while (getline(ifs, line)) {
    char *s = new char[line.size() + 1];
    strcpy(s, line.c_str());
    s[line.size()] = '\0';

    char *month_str = strtok(s, "/");
    char *day_str = strtok(nullptr, "/");
    char *year_str = strtok(nullptr, "\0");

    unsigned month = str_to_int(month_str), day = str_to_int(day_str),
             year = str_to_int(year_str);

    // istringstream ss(line);
    // unsigned day, month, year;
    // ss >> month, ss.ignore();
    // ss >> day, ss.ignore();
    // ss >> year;

    cout << month_map[month] << ' ' << day << "," << year << endl;
  }
  ifs.close();

  return 0;
}