#include <iostream>

using namespace std;

int a[1000];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];

  for (int i = 1; i <= n; i++) {
    int k = i;  // k 為最小的元素的對應下標
    // 找出i到n最小的元素
    for (int j = i; j <= n; j++) {
      if (a[j] < a[k]) k = j;
    }
    // 交換元素
    int tmp = a[i];
    a[i] = a[k];
    a[k] = tmp;
    // swap(a[i], a[k]); // STL 交換寫法
  }

  for (int i = 1; i <= n; i++) cout << a[i] << " ";

  return 0;
}