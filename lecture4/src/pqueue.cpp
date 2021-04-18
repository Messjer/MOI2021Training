#include <iostream>
#include <queue>

int main() {
  std::priority_queue<int> q;

  const int data[] = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};

  for (int n : data) q.push(n);

  while (!q.empty()) {
    std::cout << q.top() << ' ';
    q.pop();
  }
}