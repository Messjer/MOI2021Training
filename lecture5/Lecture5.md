# 2021 pre-MOI培訓．第五節

<i>April 25, Prepared by M. Hong</i>

### 複習功課

1. (3重for)UVa 11565 簡易方程式：https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2612

## 標準模版庫(STL)

"數據結構"的意思

### 動態陣列的實現

即`vector<T>`的實現。講解了簡單的length-doubling的思想，shrinking等操作留作功課。

### 界面轉換器

以下的轉插（界面轉換器Adaptor)底層實現為`vector`,`string`,`deque`等幾種容器之一（也可以是自定義類），但對外的接口有所改變。

- 堆棧`stack`：`stack<T>`。底層是一個`vector<T>`，但用`stack<T>`的接口程式可讀式會提高。
- 隊列`queue<T>`。優先隊列`priority_queue<T, Container, Comparator>`。展示自定義比較器的方法。
- `pair<A, B>`
    `pair<A, B> make_pair(a,b);`
- **下次介紹：**`set<A>`（自平衡二叉樹，鍵值不重覆）
- **下次介紹：** `map<A, B> `（自平衡二叉樹，鍵值不重覆，鍵值有對應的Value值）
- **Optional** 其餘可能會用的還包括`bitmap`等，但不常用。

## <algorithm>頭文件

- `sort`及`stable_sort`已提過，**下次介紹排序算法時重温**。
- `next_permuataion(a.begin(),a.end())`，枚舉排列神器。（見PPT內容）

## 解題思想(Problem Solving Paradigms)

暴力搜索的方法論

- 迭代法vs遞歸法實現
- 表示狀態的方式**很重要**
- 搜索的先後次序**很重要**
- 枚舉每個狀態後，判斷其合法性
- 帶回溯/不帶回溯

幾種經典枚舉方式

- 所有子集
- 所有排列
- 狀態圖上的DFS/BFS

## 未講內容

- 貪心法
- 二分法（重温）
- 分治法
- 動態規劃
- *(選講)歸約*

## PPT內容

## STL Again Again

### **Data Structures**

A “structure” in memory that stores data.

**Abstract Data Type (ADT):** The logical form (i.e. interface) of the data structure.

**Data Structure:** The physical form of the DS in computer.

### `vector<T>`

Dynamic arrays. Length can change during runtime (c.t. array like `T[10]`)

Interface:

- `vector<T> v(size_type n, const T &b)`;
    Time O(n)
- `v[i]` : access i-th element. 
    Time O(1)
- `v.size()`
    Time O(1)
- `v.push_back(T a)`: 
    Amortized time O(1)
- `v.pop_back()`: 
    Amortized time O(1)
- `v.clear()`: 
    Time O(size).
    Note: remember to clear the global vector if the problem has multiple test cases in a single run.
- `v.resize(a, b)`: 
    Time O(|size -a|).

### `vector<T>` : Dynamic Arrays

#### Problem
Maintain a **data structure** storing a collection of items supporting the following:

- **Random access**: Access (read/write) the i-th element in time O(1).
     *This is essentially* `a[i]` in C++*.*
- **Resizable**: Array length unspecified, dynamically (online) adjusts.

#### Memory Layout in OS

- What computers can do
    - Allocate a chunk of cells of fixed size 
         (say 100 bytes) in memory from the OS.
    - Inspect (or modify) the content in some cell by its address.

**Solution**: Fixed size array
Allocate a very large array.

**Drawback:** Is not dynamic. Either waste space or fail.

**Solution2:** **Eager re-allocation.**
 Re-allocate whenever the array changes.

- Pros: **Is dynamic**, optimal usage of space.

- Drawback: Need to re-allocate everything whenever the size changes!...
    This is very realistic: $$n$$ insertions require $$O(n^2)$$ memory manipulations!

**Solution3: ** **Lazy re-allocation**---Look further 
Re-allocate only when some event $$E$$ (that are supposed rare) happens.

- **Question:** How to design E?
- For example, maybe we can re-allocate between every 100 operations?

**But what if we really need more space?**
Allocate a larger space **in advance**!

**Solution3: ** **Look further** 
Get 2 extra cells if we need 1 more cell.

- How many operations are needed for $$n$$ insertions?
- It’s still bad --- $$O(n^2)$$ needed. What if we can $$k$$ more cells? (still $$O(n^2)$$ if $k$ is constant).

#### Amortized Complexity

**Solution:**  Look even further!
**Double** the size whenever we need space!

- For $$n$$ insertions…
     We need $$1+2+…+2^{\lfloor\log n\rfloor} \approx n$$ operations.
- Amortized(均攤) Complexity of each inversion is $$(O(n))/n=O(1)$$.

#### Are we done?

- Can we support deletion?
    Yes… Left as an exercise
    ***Note\*:** pop_back is already implemented in STL.

- Can we have more powerful access patterns
    E.g. membership queries (is $$x\in S$$?)

    Many, many brilliant ideas to address different use cases… 
    (some of which, like `set<T>` are implemented in STL).

### **Adaptor Container** **轉插**

Modifies the interface ofsome basic container (vector, list, …) to another interface.

Typically restricts the usage

- Can prevent unintended usage
- Make codes more readable 

Most of them already discussed…

- `queue` (FIFO)
- `stack` (LIFO)
- `priority_queue`
- Some other to-be-discussed `set`, `map`, `multi_set`, `unordered_set`

## Algorithm Design

### Search

Two ways to implement

- Iterative (for)
- Recursive (using function calls).

Key Points:

- Think about how to represent a candidate
- Then think about how to enumerate each of them, and how to check if it’s valid.

Search orders can be crucial

- Can prune (剪枝) the search if the solution appears early.

What are some possible orders?

- DFS/BFS on state graphs
- Alphabetical orders?
- Numerical (from smallest to largest?)

#### Back-tracking vs non-Back-tracking

What is Back-tracking?

Recovering the state when we encounter a “dead-end”.

Necessarily if we need to find all solutions.

#### Search Patterns

Some common search patterns

- Use bitmasks to enumerate subsets
- Use `next_permutation`
- DFS/BFS
- More…

### Bitmask

**Problem**
Store a subset of [n]={1,2,…, n}.

Solution: **Characteristic vectors**

Examples:

- $$S= \{1,3,4\}⊂[6];\chi_S=101100.$$
- $$S= \{1\}⊂[6];\chi_S=100000. $$
- $$S=\emptyset⊂[6];\chi_S=000000. $$
- $$S= \{1,2,3,4,5,6\}⊂[6];\chi_S=111111. $$

**Idea:** Store each 0/1 vector in an integer type and use bit operations!

Recap: Every **int** type contains a 32-bit data which is the binary form of the integer.

For i in range ($$0 \le i \le 31$$):

- Set i-th bit: **mask**=**mask** | (1<<i).
- Unset i-th bit: **mask**=**mask** & (~(1<<i))**.**
- Test i-th bit: **mask** & (1<<i)?

Can also work with long long to get 64 bits.

#### Enumerating Subsets

```c++
for (int mk = 0, mk < (1 <<n); mk++) {
  // test if the set represented by mk is good
 }
```

There is a total of $$2^n$$ subsets to enumerate. So typically one can handle $$n\le 23$$ in OI.

### Permutations

An extremely helpful STL function:

- `next_permutation(a.begin(), a.end());`
- `next_permutation(a, a + n);`

Here **a** is a vector/array containing a permutation of {1,2,…,n}.

The function returns true if **a** has an (lexicographically) next permutation, and false if **a** = (n,n-1,…,3,2,1)**.**

#### Enumerating permutations

```c++
int a[10];
for (int i = 0; I < 10; i++)
  a[i] = i;
 do {
 // check if **a** contains a good permutation
 } while (next_permutation(a,a+10));
```

There is a total of n! subsets to enumerate. So typically one can handle $$n\le 10$$ in OI.

### Searching on “graphs”

Graphs can come from the input, or some **“state graph”** conceived on YOUR OWN philosophically.

Basic search orders are

- Breadth-first search (BFS)
- Depth-first search (DFS)

#### DFS, BFS

Common confusion

Are they deterministic algorithms?
 **Not really!!!**

What is the complexity?

"O(n+m)“…?

This only applies if you use adj list… If you use adj matrix it is always O(n^2)… (so be careful)

Isn’t O(n+m) already very small?

Here n=|V| is the state graph size!

**Number of nodes |V| can itself be exponential in the input size (typically denotes as n too…).**

How to decide which to choose from?

Sometimes doesn’t matter…

But sometimes matter a lot!!

**Practice, practice, practice!!!**

### Example Problems

- 8-digit problem: [https://](https://www.luogu.com.cn/problem/P1379)[www.luogu.com.cn/problem/P1379](https://www.luogu.com.cn/problem/P1379)
     [https://](https://en.wikipedia.org/wiki/15_puzzle)[en.wikipedia.org/wiki/15_puzzle](https://en.wikipedia.org/wiki/15_puzzle)
     (數字推碼問題)
- 8-queen problem:
     [https](https://www.luogu.com.cn/problem/P1219)[://www.luogu.com.cn/problem/P1219](https://www.luogu.com.cn/problem/P1219)
     [https://zh.wikipedia.org/zh-hk/%](https://zh.wikipedia.org/zh-hk/八皇后问题)[E5%85%AB%E7%9A%87%E5%90%8E%E9%97%AE%E9%A2%98](https://zh.wikipedia.org/zh-hk/八皇后问题) (八皇后問題)

## Homework

- Chapter 3 (problem solving paradigms) on uHunt
    - Like[Uva12192](https://onlinejudge.org/external/121/12192.pdf), [Uva1047](https://onlinejudge.org/external/10/1047.pdf) ,[Uva1262](https://onlinejudge.org/external/12/1262.pdf), [Uva416](https://onlinejudge.org/external/4/416.pdf), [Uva11553](https://onlinejudge.org/external/115/11553.pdf) [Uva10567](https://onlinejudge.org/external/105/10567.pdf), [Uva10576](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1517),[Uva 11085](https://onlinejudge.org/external/110/11085.pdf), [Uva 10503](https://onlinejudge.org/external/105/10503.pdf), [Uva574](https://onlinejudge.org/external/5/574.pdf), and others.
- Similar problems on luogu and other OJs.

## 參考資料

### 香港代表隊培訓講義

https://assets.hkoi.org/training2019/big-o.pdf

### 建國中學校內培訓講義：

1. 09年：http://pisces.ck.tp.edu.tw/~peng/index.php?year=2009
2. 16年：https://tioj.ck.tp.edu.tw/articles/5

