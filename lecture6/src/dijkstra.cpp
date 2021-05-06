#include <bits/stdc++.h>
using namespace std;
int n, m, s;
vector<vector<pair<int, int>>> edge(100005);
int dis[100005], vis[100005];
void dijk(int s) {
  priority_queue<pair<int, int>> que;
  memset(dis, 0x3f, sizeof(dis));
  memset(vis, 0, sizeof(vis));
  dis[s] = 0;
  que.push(make_pair(0, s));
  while (!que.empty()) {
    int u = que.top().second;
    que.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto e : edge[u]) {
      int v = e.first;
      int dist = e.second;
      if (dis[u] + dist < dis[v]) {
        dis[v] = dis[u] + dist;
        que.push(make_pair(-dis[v], v));
      }
    }
  }
}
int main() {
  cin >> n >> m >> s;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edge[u].push_back({v, w});
  }
  dijk(s);
  for (int i = 1; i <= n; i++) cout << dis[i] << " ";

  return 0;
}