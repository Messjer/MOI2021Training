#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
const int MAXN = 100005;
int ans[MAXN];
bool vis[MAXN];
vector<vector<int>> adj;
void dfs(int u, int x) {
  ans[u] = max(ans[u], x);
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (ans[v] || vis[v]) continue;
    vis[v] = true;
    dfs(v, x);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[v].push_back(u);
  }

  for (int i = n; i >= 1; i--) {
    if (ans[i] == 0) {
      dfs(i, i);
    }
  }

  for (int i = 1; i <= n; i++) cout << ans[i] << " ";

  return 0;
}