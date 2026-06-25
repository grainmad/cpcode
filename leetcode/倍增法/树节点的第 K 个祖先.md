## 题目

[1296. 树节点的第 K 个祖先](https://leetcode.cn/problems/kth-ancestor-of-a-tree-node/)


---


给你一棵树，树上有 `n` 个节点，按从 `0` 到 `n-1` 编号。树以父节点数组的形式给出，其中 `parent[i]` 是节点 `i` 的父节点。树的根节点是编号为 `0` 的节点。

树节点的第 *`k` *个祖先节点是从该节点到根节点路径上的第 `k` 个节点。

实现 `TreeAncestor` 类：

	- `TreeAncestor（int n， int[] parent）` 对树和父数组中的节点数初始化对象。

	- `getKthAncestor``(int node, int k)` 返回节点 `node` 的第 `k` 个祖先节点。如果不存在这样的祖先节点，返回 `-1` 。

 

**示例 1：**

**[]**

**输入：**
["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"]
[[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]

**输出：**
[null,1,0,-1]

**解释：**
TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);

treeAncestor.getKthAncestor(3, 1);  // 返回 1 ，它是 3 的父节点
treeAncestor.getKthAncestor(5, 2);  // 返回 0 ，它是 5 的祖父节点
treeAncestor.getKthAncestor(6, 3);  // 返回 -1 因为不存在满足要求的祖先节点

 

**提示：**

	- `1 <= k <= n <= 5 * 10^4^`

	- `parent[0] == -1` 表示编号为 `0` 的节点是根节点。

	- 对于所有的 `0 < i < n` ，`0 <= parent[i] < n` 总成立

	- `0 <= node < n`

	- 至多查询 `5 * 10^4^` 次


## 题解


### 思路

动态规划倍增预处理
`f[i][j]`代表节点$i$的第$2^j$个父节点。
状态转移`f[i][j] = f[f[i][j-1][j-1]`
求i的第k个父节点可以通过k的二进制拆分成若干2的幂次。从大到小跳转。


### 代码


```cpp
class TreeAncestor {
public:
    int f[50005][32];// f[i][j] i的2^j个父节点
    TreeAncestor(int n, vector<int>& parent) {
        for (int i=0; i<n; i++) {
            f[i][0] = parent[i];
        }
        for (int i=1; i<=30; i++) {
            for (int j=0; j<n; j++) {
                f[j][i] = f[j][i-1] == -1 ? -1 : f[f[j][i-1]][i-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int u = node;
        for (int i=0; i<=30; i++) {
            if (k>>i&1) u = f[u][i];
            if (u == -1) return -1;
        }
        return u;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
```
