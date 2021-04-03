#include <iostream>

using namespace std;
int n, k, cnt = 0;
int x[30];
bool isPrime(int x) {
  bool flag = true;
  // 質數不能被除了自己和1之外的數整除
  for (int i = 2; i <= x - 1; i++)
    if (x % i == 0) flag = false;
  return flag;
}
// cur 代表 上一個選的數的下標
void f(int cur, int dep, int sum) {
  //當已經選擇了k個數
  if (dep == k) {
    if (isPrime(sum)) cnt++;
    return;
  }

  // 組合數 選擇比上一個選的數更後的數
  for (int i = cur + 1; i <= n; i++) f(i, dep + 1, sum + x[i]);

  return;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> x[i];
  f(0, 0, 0);
  cout << cnt;
  return 0;
}