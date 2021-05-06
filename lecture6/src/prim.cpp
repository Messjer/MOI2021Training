#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int n, m;
const int MAXN = 5005;
vector<vector<pair<int, int>>> adj;
int vis[MAXN];
int prim() {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      que;

  que.push(make_pair(0, 1));
  int sum = 0;
  while (!que.empty()) {
    int u = que.top().second;
    int w = que.top().first;
    que.pop();
    if (vis[u]) continue;
    vis[u] = true;
    sum += w;
    for (auto x : adj[u]) {
      int v = x.first;
      int ww = x.second;
      que.push(make_pair(ww, v));
    }
  }
  return sum;
}
int main() {
  cin >> n >> m;
  adj.resize(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }

  cout << prim() << endl;

  return 0;
}