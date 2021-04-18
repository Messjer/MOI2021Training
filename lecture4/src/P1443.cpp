#include <bits/stdc++.h>
using namespace std;
const int maxn = 405;
const int dx[8] = {+1, +1, -1, -1, +2, +2, -2, -2};
const int dy[8] = {+2, -2, +2, -2, +1, -1, +1, -1};
int ans[maxn][maxn];
int vis[maxn][maxn];
struct node {
  int x, y, depth;
};
int main() {
  int n, m, sx, sy;
  cin >> n >> m >> sx >> sy;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) ans[i][j] = -1;
  }
  ans[sx][sy] = 0;

  queue<node> que;
  que.push((node){sx, sy, 0});

  while (!que.empty()) {
    node now = que.front();
    que.pop();
    int x = now.x, y = now.y, depth = now.depth;
    if (vis[x][y]) continue;
    vis[x][y] = true;
    for (int i = 0; i < 8; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx <= 0 && nx > n && ny <= 0 && ny > m) continue;
      if (vis[nx][ny]) continue;
      ans[nx][ny] = depth + 1;
      que.push((node){nx, ny, depth + 1});
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cout << left << setw(5) << ans[i][j];
    cout << endl;
  }

  return 0;
}