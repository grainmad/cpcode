#include <bits/stdc++.h>
#define ll long long
#define N 1000005
using namespace std;

/*
期望dp
设$dp_i$为从点i到i+1的期望, $S_i$为i点的返祖边所连接的点集合,
$S_i$的大小为$size_i$。 求$dp_i$要考虑i点有多少条出边。
每条出边被选择的概率都为$\frac{1}{size_i}$。
转移式
$dp_i = \frac{1}{size_i+1} \times 1 + \frac{1}{size_i+1} \sum \limits_{j \in
S_i}(1+ \sum \limits_{k=j}^idp_k)$ 这里的$\sum
\limits_{k=j}^idp_k$是从返祖边指向的点j到i+1的期望，其实就是$dp_j+dp_{j+1}+\cdots+dp_i$
对这个式子变形：
$dp_i = 1 + \frac{1}{size_i+1} \sum \limits_{j \in S_i}\sum \limits_{k=j}^idp_k$
将dp的区间和改为前缀和的差，便于计算。
$dp_i = 1 + \frac{1}{size_i+1} \sum \limits_{j \in S_i}(\sum
\limits_{k=1}^idp_k-\sum \limits_{k=1}^{j-1}dp_k)$ 将等号右边的$dp_i$移到左边。
$dp_i = size_i+1 + \sum \limits_{j \in S_i}(\sum \limits_{k=1}^{i-1}dp_k-\sum
\limits_{k=1}^{j-1}dp_k)$

*/

const ll MOD = 998244353;
std::vector<int> v[N];
ll pre[N];
ll dp[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int id, n, m;
    cin >> id >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = v[i].size() + 1;
        for (int j : v[i]) {
            dp[i] = (dp[i] + pre[i - 1] - pre[j - 1] + MOD) % MOD;
        }

        pre[i] = (pre[i - 1] + dp[i]) % MOD;
    }
    cout << pre[n] << endl;
    return 0;
}

/*
# [Cnoi2020]线形生物

## 题目背景

>
为了能够在冥界过上这种愉快的生活而不是被判入地狱，人类们摒弃了自行结束生命的做法，拼尽全力地生活着。如此看来，人类似乎也显得有些积极与可爱了呢。
（射命丸 文）

线形生物沿着一维的阶梯向着冥界单向地前行着。

照这样的话，它只需要一级一级地，走 $n$ 步就能够到达白玉楼。

但 Cirno
觉得这样太单调了，于是，一维的壁垒被打破，链状的道路生出了花椰菜状的枝桠。

## 题目描述

线形生物要从 $1$ 号台阶走到 $n+1$ 号台阶。

最开始，$1,2,3,\ldots,n$ 号台阶都有一条连向下一台阶的有向边 $i\rightarrow i+1$。

之后 Cirno 加入了 $m$ 条**返祖边** $u_i \rightarrow v_i (u_i \ge
v_i)$，它们构成了一个**返祖图**。

线形生物每步会 **等概率地** 选取当前台阶的一条出边并走向对应的台阶。

当走到 $n+1$ 号台阶时，线形生物就会停止行走。

同时，Cirno 会统计线性生物总共走的步数，记作 $\delta$。

Cirno 想知道 $E(\delta)$（即 $\delta$ 的**数学期望**）对 $998244353$
取模后的结果。

## 输入格式

第一行三个整数 $id$，$n$，$m$。

以下 $m$ 行，每行两个整数 $u_i$，$v_i$。

$id$ 表示 subtask 编号，其它字母含义同上文。

## 输出格式

一行，一个整数 $E(\delta)$，字母含义同上文。

## 样例 #1

### 样例输入 #1

```
1 5 5
1 1
2 2
3 3
4 4
5 5
```

### 样例输出 #1

```
10
```

## 样例 #2

### 样例输入 #2

```
2 5 5
1 1
2 1
3 2
4 3
5 4
```

### 样例输出 #2

```
30
```

## 样例 #3

### 样例输入 #3

```
3 5 5
1 1
2 1
3 1
4 1
5 1
```

### 样例输出 #3

```
62
```

## 样例 #4

### 样例输入 #4

```
4 5 5
1 1
3 1
4 2
5 1
5 5
```

### 样例输出 #4

```
35
```

## 提示

## 后置数学知识
 - **可能用到的幂级数求和** : 若 $x>1$，则有
$\sum\limits_{i=1}^{\infty}\big(\frac{1}{x}\big)^i=\frac{1}{x}+\frac{1}{x^2}+\frac{1}{x^3}+\cdots=\frac{1}{x-1}$。
 - **数学期望** :
随机试验中每次可能结果的概率乘以其结果的总和，反映随机变量平均取值的大小。
 - **离散期望公式** : $E(x)=\sum\limits_{k=1}^{\infty}x_kp_k$。

## 数据范围与约定

对于 $100\%$ 的数据，保证：$id \in \lbrace 1,2,3,4,5\rbrace $，$0 < n,m \le 10^6$，$1 \le
v_i \le u_i \le n$。

#### 子任务「本题采用捆绑测试」

 - Subtask1（$10\%$）: 返祖图中所有点都有自环且所有边均为自环(未画出)，总图形如
:
 ![](https://cdn.luogu.com.cn/upload/image_hosting/6fikv6ft.png)

 - Subtask2（$10\%$）: 返祖图中所有点均向且仅向自己的前驱连边，特别地，$1$
号节点的前驱是 $1$ 号节点，总图形如 :
   ![](https://cdn.luogu.com.cn/upload/image_hosting/6rc9dazb.png)

 - Subtask3（$10\%$）: 返祖图中所有点均向且仅向 $1$ 号节点连边，总图形如 :
 ![](https://cdn.luogu.com.cn/upload/image_hosting/wup1ctvu.png)

 - Subtask4（$10\%$）: $n \le 100$，$m \le 1000$。

 - Subtask5（$60\%$）: 无特殊限制。

 ## 后记

  题目名称出自 th17 东方鬼形兽 6 Boss 埴安神袿姬 Hard / Lunatic 难度符卡
線形「リニアクリーチャー」。

*/