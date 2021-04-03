
#include <iostream>
using namespace std;

int main() {
  int n, u, d;
  cin >> n >> u >> d;
  // 所用時間   已爬距離
  int time = 0, dist = 0;

  while (true) {
    // 每分鐘向上爬 u 格
    dist += u;
    time++;

    // 如果爬完後已經離開就完結
    if (dist >= n) break;

    // 每分鐘向下爬 u 格
    dist -= d;
    time++;
  }

  cout << time << endl;

  return 0;
}