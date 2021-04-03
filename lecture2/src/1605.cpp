#include <iostream>
using namespace std;
int map[6][6];      //地圖
bool visted[6][6];  //走過的標記
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int cnt, n, m, fx, fy, sx, sy;
void DFS(int x, int y) {
  //結束條件
  if (x == fx && y == fy)  // fx表示終點x坐標，fy表示終點y坐標
  {
    cnt++;   //總數增加；
    return;  //返回，繼續搜索；
  } else {
    for (int i = 0; i <= 3; i++)  // 0——3是左，右，下，上四個方向
    {
      // 限制條件
      if (x + dx[i] < 1 || x + dx[i] > n) continue;  //不能越界
      if (y + dy[i] < 1 || y + dy[i] > m) continue;  //不能越界
      if (visted[x + dx[i]][y + dy[i]]) continue;    //走過的點不走
      if (map[x + dx[i]][y + dy[i]]) continue;  //地圖上有障礙的點不走

      visted[x][y] = 1;  //走過的地方打上標記
      DFS(x + dx[i], y + dy[i]);
      visted[x][y] = 0;  //還原狀態；
    }
  }
  return;
}
int main() {
  int T;
  cin >> n >> m >> T;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      visted[i][j] = false;  //初始狀態地圖所有點未遍歷過
      map[i][j] = 0;         // 初始狀態地圖沒有障礙 0
    }
  cin >> sx >> sy;  //起點
  cin >> fx >> fy;  //終點
  for (int i = 1; i <= T; i++) {
    int x, y;
    cin >> x >> y;
    map[x][y] = 1;  //地圖障礙為 1
  }
  cnt = 0;
  DFS(sx, sy);
  cout << cnt;
  return 0;
}
