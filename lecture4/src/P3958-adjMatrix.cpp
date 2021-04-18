#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 1005;
long long x[MAXN], y[MAXN], z[MAXN];
bool isEntry[MAXN], isExit[MAXN], visted[MAXN];
bool adjMatrix[MAXN][MAXN];

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
      if (z[i] - r <= 0) isEntry[i] = true;
      if (z[i] + r >= h) isExit[i] = true;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dis(i, j) <= 2 * r && i != j) {
          adjMatrix[i][j] = adjMatrix[j][i] = true;
        } else
          adjMatrix[i][j] = adjMatrix[j][i] = false;
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
      for (int v = 0; v < n; v++) {
        if (visted[v]) continue;
        if (adjMatrix[u][v] == 0) continue;
        que.push(v);
        visted[v] = true;
      }
    }

    cout << (ok ? "Yes" : "No") << endl;
  }
  return 0;
}