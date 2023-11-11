// Splay 提醒：开启 O2 优化
#include <algorithm>
#include <iostream>
using namespace std;

#define N 50005
#define INF 2147483647
#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]

// splay
struct node {
    int s[2], p;
    int v, siz;
    void init(int p1, int v1) {
        p = p1;
        v = v1;
        siz = 1;
    }
} tr[N * 40];

// splay节点总数取决于线段树层数
// 线段树每一层所有splay的节点总数为O(n)
// 线段树层数O(logn)，总节点数O(nlogn)

int n, m, w[N], idx;

// 更新子节点个数
inline void pushup(int x) {
    tr[x].siz = tr[ls(x)].siz + tr[rs(x)].siz + 1;
}

// 左/右旋
inline void rotate(int x) {
    int y = tr[x].p, z = tr[y].p;
    int k = tr[y].s[1] == x;
    tr[z].s[tr[z].s[1] == y] = x, tr[x].p = z;
    tr[y].s[k] = tr[x].s[k ^ 1], tr[tr[x].s[k ^ 1]].p = y;
    tr[x].s[k ^ 1] = y, tr[y].p = x;
    pushup(y), pushup(x);
}

// 指定线段树中某颗splay，进行伸展操作（根可能会变化，传引用）
inline void splay(int& root, int x, int k) {
    while (tr[x].p != k) {
        int y = tr[x].p, z = tr[y].p;
        if (z != k)
            if ((rs(y) == x) ^ (rs(z) == y))
                rotate(x);
            else
                rotate(y);
        rotate(x);
    }
    if (!k)
        root = x;
}

// 指定线段树中某颗splay，插入v（根可能会变化，传引用）
inline void insert(int& root, int v) {
    int u = root, p = 0;
    while (u)
        p = u, u = tr[u].s[v > tr[u].v];
    u = ++idx;
    tr[p].s[v > tr[p].v] = u;
    tr[u].init(p, v);
    splay(root, u, 0);
}

// 指定线段树中某颗splay，删除v（根可能会变化，传引用）
inline void del(int& root, int v) {
    int u = root;
    while (u) {
        if (tr[u].v == v)
            break;
        if (tr[u].v < v)
            u = rs(u);
        else
            u = ls(u);
    }
    splay(root, u, 0);
    int l = ls(u), r = rs(u);
    while (rs(l))
        l = rs(l);
    while (ls(r))
        r = ls(r);
    splay(root, l, 0);
    splay(root, r, l);
    ls(r) = 0;
    splay(root, r, 0);
}

// 指定线段树中某颗splay，获取v的排名-1（中序遍历spaly后小于v的个数）
inline int getrank(int root, int v) {
    int u = root, res = 0;
    while (u) {
        if (tr[u].v < v)
            res += tr[ls(u)].siz + 1, u = rs(u);
        else
            u = ls(u);
    }
    return res;
}

// 指定线段树中某颗splay，获取v的前驱
inline int getpre(int root, int v) {
    int u = root, res = -INF;
    while (u) {
        if (tr[u].v < v)
            res = tr[u].v, u = rs(u);
        else
            u = ls(u);
    }
    return res;
}

// 指定线段树中某颗splay，获取v的后继
inline int getnxt(int root, int v) {
    int u = root, res = INF;
    while (u) {
        if (tr[u].v > v)
            res = tr[u].v, u = ls(u);
        else
            u = rs(u);
    }
    return res;
}

// 线段树
#define lc (u << 1)
#define rc (u << 1 | 1)
int root[N * 4];

// 对于每个节点，遍历所代表的区间范围，并将权值逐个插入节点splay
// 每一层所有splay的节点和为n个。共计logn层，复杂度O(n log^2(n))
void build(int u, int l, int r) {
    insert(root[u], -INF), insert(root[u], INF);
    for (int i = l; i <= r; i++)
        insert(root[u], w[i]);
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
}

// 获取区间[ql,qr]中值为v的排名。
// 找到区间所覆盖的splay，每颗splay查找严格小于v的节点数，累计合并+1为v的排名
int queryrank(int u, int l, int r, int ql, int qr, int v) {
    if (ql <= l && r <= qr)
        return getrank(root[u], v) - 1;
    int mid = l + r >> 1, res = 0;
    if (ql <= mid)
        res += queryrank(lc, l, mid, ql, qr, v);
    if (qr > mid)
        res += queryrank(rc, mid + 1, r, ql, qr, v);
    return res;
}

// 获取排名为k的节点值。 排名随着节点值增大而增大。
// 二分节点值，查节点值的排名
int queryval(int u, int l, int r, int k) {
    int a = 0, b = 1e8 + 1;
    while (a < b) {
        int mid = a + b >> 1;
        // 对于一个x如果出现了3次。小于x的个数为t，那么小于x+1的个数为t+3
        // x的排名可以是t+1, t+2, t+3, t+4
        // 排名应该是从小到大x中最后一个满足queryrank(x)+1<=k的值
        if (queryrank(1, 1, n, l, r, mid) + 1 <= k)
            a = mid + 1;
        else
            b = mid;
    }
    return b - 1;
}

// 修改pos位置的权值为v
// 对于线段树路径上的节点splay全部删除原有权值，新增v。
void change(int u, int l, int r, int pos, int v) {
    del(root[u], w[pos]);
    insert(root[u], v);
    if (l == r)
        return;
    int mid = l + r >> 1;
    if (pos <= mid)
        change(lc, l, mid, pos, v);
    else
        change(rc, mid + 1, r, pos, v);
}

// 查询区间[l,r]中v的前驱
// 对于每个覆盖区间的splay查找v的前驱，然后维护最大值
int querypre(int u, int l, int r, int ql, int qr, int v) {
    if (ql <= l && r <= qr)
        return getpre(root[u], v);
    int mid = l + r >> 1, res = -INF;
    if (ql <= mid)
        res = max(res, querypre(lc, l, mid, ql, qr, v));
    if (qr > mid)
        res = max(res, querypre(rc, mid + 1, r, ql, qr, v));
    return res;
}

// 查询区间[l,r]中v的后继
// 对于每个覆盖区间的splay查找v的后继，然后维护最小值
int querynxt(int u, int l, int r, int ql, int qr, int v) {
    if (ql <= l && r <= qr)
        return getnxt(root[u], v);
    int mid = l + r >> 1, res = INF;
    if (ql <= mid)
        res = min(res, querynxt(lc, l, mid, ql, qr, v));
    if (qr > mid)
        res = min(res, querynxt(rc, mid + 1, r, ql, qr, v));
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    build(1, 1, n);
    while (m--) {
        int op, x, y, v;
        scanf("%d", &op);
        if (op == 3)
            scanf("%d%d", &x, &v);
        else
            scanf("%d%d%d", &x, &y, &v);

        if (op == 1)
            printf("%d\n", queryrank(1, 1, n, x, y, v) + 1);
        if (op == 2)
            printf("%d\n", queryval(1, x, y, v));
        if (op == 3)
            change(1, 1, n, x, v), w[x] = v;
        if (op == 4)
            printf("%d\n", querypre(1, 1, n, x, y, v));
        if (op == 5)
            printf("%d\n", querynxt(1, 1, n, x, y, v));
    }
    return 0;
}
