#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 1005;
long long x[MAXN], y[MAXN], z[MAXN];
bool isEntry[MAXN], isExit[MAXN], visted[MAXN];

double dis(int u, int v) {
  double dx = x[u] - x[v], dy = y[u] - y[v], dz = z[u] - z[v];
  return sqrt(dx * dx + dy * dy + dz * dz);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, h, r;
    cin >> n >> h >> r;
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i] >> z[i];
      isEntry[i] = isExit[i] = visted[i] = false;
      if (z[i] <= r) isEntry[i] = true;
      if (z[i] + r >= h) isExit[i] = true;
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dis(i, j) <= 2 * r && i != j) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }

    queue<int> que;
    for (int i = 0; i < n; i++) {
      if (isEntry[i]) {
        que.push(i);
        visted[i] = true;
      }
    }

    bool ok = false;
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      if (isExit[u]) {
        ok = true;
        break;
      }
      for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (visted[v]) continue;
        que.push(v);
        visted[v] = true;
      }
    }

    // cout << (ok ? "Yes" : "No") << endl;
    if (ok)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}