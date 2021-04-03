#include <iostream>

using namespace std;

bool tag[10];  // 標記數組
int ans[10];   // 答案儲存數組
// 當前值 層數 N
void f(int x, int dep, int n) {
  if (dep > 0) ans[dep] = x;  // 當深度不為0時記錄每層的值
  if (dep == n) {             // 當層數為n時結束
    // 注意輸出格式
    for (int i = 1; i <= n; i++) cout << "    " << ans[i];
    cout << endl;
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (tag[i]) continue;
    tag[i] = true;  // 標記 排列不能重覆
    f(i, dep + 1, n);
    tag[i] = false;  // 取消標記
  }
  return;
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) tag[i] = false;
  f(0, 0, n);

  return 0;
}