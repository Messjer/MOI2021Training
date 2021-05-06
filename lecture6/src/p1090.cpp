#include <iostream>
#include <queue>

using namespace std;

int main() {
  int n, ans = 0;

  cin >> n;

  priority_queue<int, vector<int>, greater<int>> que;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    que.push(x);
  }
  while (que.size() > 1) {
    int x, y;
    x = que.top();
    que.pop();
    y = que.top();
    que.pop();
    que.push(x + y);
    ans += x + y;
  }
  cout << ans;
  return 0;
}
