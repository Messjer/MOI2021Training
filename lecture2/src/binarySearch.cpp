#include <iostream>

using namespace std;

int a[1000005];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) {
    int x;
    cin >> x;
    int l = 1, r = n;
    while (l < r) {
      int mid = (l + r) / 2;
      if (a[mid] < x)
        l = mid + 1;
      else
        r = mid;
    }
    if (a[l] == x)
      cout << l << " ";
    else
      cout << -1 << " ";
  }
  return 0;
}