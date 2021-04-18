# STL 入門

## std::vector

```c++
#include <vector>

std::vector<int> a(20);
std::vector<std::string> b;
a[12] = 34;
b.push_back("ABC");
a.resize(15);
```



## std::queue

```c++
#include <queue>

std::queue<int> que;
que.push(45);
que.push(69);
std::cout << que.empty() << std::endl;  // 0
std::cout << que.front() << std::endl;  // 45
que.pop();
std::cout << que.front() << std::endl;  // 69
que.pop();
std::cout << que.empty() << std::endl;  // 1
```



## std::stack

```cpp
#include <stack>

std::stack<int> stk;
stk.push(67);
stk.push(46);
std::cout << stk.empty() << std::endl;  // 0
std::cout << stk.top() << std::endl;    // 46
stk.pop();
std::cout << stk.top() << std::endl;  // 67
stk.pop();
std::cout << stk.empty() << std::endl;  // 1
```



## std::pair

```cpp
#include <utility>

std::pair<int, double> p;
p = std::make_pair(12, 4.22);
std::cout << p.first << " " << p.second << std::endl;  
// 12 4.22
```



## std::sort

```cpp
#include <algorithm>
#include <vector>

int c[10] = {4, 3, 2, 5, 7, 2, 7, 2, 3, 5};
std::vector<int> d{9, 7, 5, 1, 4, 5, 7, 4, 3, 4};
std::sort(c, c + 10);
std::sort(d.begin(), d.end());
for (int i = 0; i < 10; i++) std::cout << c[i] << " "; // 2 2 2 3 3 4 5 5 7 7
std::cout << std::endl;
for (int i = 0; i < 10; i++) std::cout << d[i] << " "; // 1 3 4 4 4 5 5 7 7 9
std::cout << std::endl;
```



## std::priority_queue

```cpp
#include <queue>

std::priority_queue<int> q;
const int data[] = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
for (int n : data) q.push(n);
while (!q.empty()) {
  std::cout << q.top() << ' ';
  q.pop();
}
// 9 8 7 6 5 4 3 2 1 0
```



# 圖論入門

## 圖的基本概念

- 點 (Vertex/Node)

- 邊 (Edge)

- 度數 (Degree)

- 環 (Loop)

- 樹 (Tree)



## 有向圖/無向圖

<img src=".\direct.png" width="50%"><img src=".\undirect.png" width="50%">

## 圖的存儲

### 直接儲存邊

不作敍述

### Adjacency Matrix

```cpp
const int MAXN = 1000;
int adj[MAXN][MAXN]; 
/*......*/
int m;
std::cin >> m;
for (int i = 0; i < m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;  // a edge from u to v with weight w
    adj[u][v] = w;
    adj[v][u] = w;  // if it is a Undirected graph
}
```

### Adjacency List

```cpp
std::vector<std::vector<int> > adj;
int n, m;
cin >> n >> m;
adj.resize(n + 1);
for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;  // a edge from u to v 
    adj[u].push_back(v);
    adj[v].push_back(u);  // if it is a Undirected graph
}
```



## DFS 複習

結合建圖技巧

習題︰洛谷P3916 https://www.luogu.com.cn/problem/P3916



## BFS

- Breadth First Search，中文廣度優先搜索。

- 每次都嘗試訪問同一層的節點。 如果同一層都訪問完了，再訪問下一層。

- BFS 算法找到的路徑是從起點開始的 **最短** 合法路徑。換言之，這條路所包含的邊數最小。

<img src=".\bfs.png">

習題︰

- [NOIP2017 提高组] 奶酪 https://www.luogu.com.cn/problem/P3958

- 洛谷 P1443 馬的遍歷 https://www.luogu.com.cn/problem/P1443