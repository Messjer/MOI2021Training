# "基礎"算法入門

<i>April 3, 孔繁銘  Steven Hong</i>

## Bogo-sort

1. 將序列中所有元素隨機打亂

2. 檢查是否排序正確，若不正確重覆上一步

## Selection sort

1. 首先在未排序序列中找到最小元素，存放到排序序列的起始位置。

2. 再從**剩餘**未排序元素中繼續尋找最小元素，然後放到已未排序序列的起始。
3. 重複第二步，直到所有元素均排序完畢。

## 模擬大法

- 用程序來模擬題目中要求的操作。

- 模擬題通常CODE多、思路繁複。(今日例題比較易

- DEBUG比較浪費時間。

### 例1 - Climbing Worm

> 一隻一英寸的蠕蟲位于 **n** 英寸深的井的底部。它每分鐘向上爬 **u** 英寸，但是必須休息一分鐘才能再次向上爬。在休息的時候，它滑落了 **d** 英寸。之後它將重複向上爬和休息的過程。蠕蟲爬出井口花費了多長時間？我們將不足一分鐘的部分算作一整分鐘。如果蠕蟲爬完後剛好到達井的頂部，我們也設作蠕蟲已經爬出井口。		

## DFS ( Depth First Search)

- DFS 最顯著的特徵在于其 **遞歸調用自身**。

- DFS 會對其訪問過的點打上訪問標記，在遍歷圖時跳過已打過標記的點，以確保 **每個點僅訪問一次**。

### 例題

1. Luogu P1605 迷宫  https://www.luogu.com.cn/problem/P1605

## 暴力递歸

- 利用递歸函數方便地實現暴力枚舉的算法

- 與前面DFS 算法有一定相似之處，但不完全相同。

### 例題

1. Luogu P1706 全排列问题 https://www.luogu.com.cn/problem/P1706

2. NOIP2002 普及組 選數 https://www.luogu.com.cn/problem/P1036

## Binary Search

對於一組已經排序好數據，二分查找過程如下

1. 它每次查找數組當前部分的中間元素，如果中間元素剛好是要找的，就結束搜索過程；

2. 如果中間元素小于所查找的值，那麽左側的只會更小，不會有所查找的元素，只需到右側查找；

3. 如果中間元素大于所查找的值同理，只需到左側查找。

### 例題

1. 洛谷 P2249 查找 https://www.luogu.com.cn/problem/P2249

### Linear Search vs Binary Search

| N       | Linear Search | Binary Search |
| ------- | ------------- | ------------- |
| 1       | 1             | 1             |
| 10      | 10            | 4             |
| 100     | 100           | 7             |
| 1000    | 1000          | 10            |
| 10000   | 10000         | 14            |
| 100000  | 100000        | 17            |
| 1000000 | 1000000       | 20            |
| ...     | ...           | ...           |

## 參考

- OI wiki https://oi-wiki.org/
- Luogu https://www.luogu.com.cn/