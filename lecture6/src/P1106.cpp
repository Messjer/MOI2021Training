#include <iostream>

using namespace std;
string str;
int k;
int main() {
  cin >> str >> k;
  while (k > 0) {
    int tag = 0;
    for (int i = 0; i < str.size() - 1; i++)
      if (str[i] > str[i + 1]) {
        str.erase(i, 1);
        tag = 1;
        break;
      }
    if (tag == 0) break;
    k--;
  }
  int i = -1;
  while (str[++i] == '0')
    ;
  if (i == str.size() - k) cout << "0";
  for (int j = i; j < str.size() - k; j++) cout << str[j];
  return 0;
}