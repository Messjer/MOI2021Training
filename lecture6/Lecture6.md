# 貪心算法與最相關算法

## 貪心算法（greedy algorithm)

- 每一步行動總是按某種指標選取最優的操作
- 只看眼前，并不考慮以後可能造成的影響
- 一般使用貪心法的時候，都要確保自己能證明其正確性
- 適用範圍︰問題能够分解成子問題來解决，子問題的最優解能遞推到最終問題的最優解

### 例題

- Luogu P2240 部分背包问题 https://www.luogu.com.cn/problem/P2240
- [NOIP2004 提高组] 合并果子 https://www.luogu.com.cn/problem/P1090
- Luogu P1106 刪數問題 https://www.luogu.com.cn/problem/P1106

## Dijkstra Algorithm

- 找到圖中某個點到其他所有點的最點路徑

- 只適用于非負權圖

- 時間複雜度$O(n^2)$

- std::priority_queue優化後$O(m \log ⁡m)$

### 例題

- MOI 2018 時間鎖 timelock

- MOI 2020-R2 交通時間 traffic

## Prim算法

- 生成樹是指將一個圖中的若干邊去除後，剩下一棵樹
- 最小生成樹是指邊權之和最小的生成樹
- Prim 算法類似Dijkstra 算法，但是兩者更新點的優先度不同

### 例題

- Luogu P3366 【模板】最小生成樹 https://www.luogu.com.cn/problem/P3366