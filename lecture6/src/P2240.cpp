#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
struct Node {
  int m, v;
} a[110];

bool cmp(Node x, Node y) {
  return x.v * y.m > x.m * y.v;
  // x.v/s.m > y.v/y.m
}
int main() {
  int n, t;
  cin >> n >> t;
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].m >> a[i].v;
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    if (a[i].m <= t)
      ans += a[i].v, t -= a[i].m;
    else {
      ans += a[i].v * t * 1.0 / (a[i].m * 1.0);
      break;
    }
  }
  printf("%.2lf", ans);
  return 0;
}