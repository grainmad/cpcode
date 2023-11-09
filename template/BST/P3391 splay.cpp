// https://www.luogu.com.cn/problem/P3391
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 100005
#define MOD 998244353
#define INF 0x3f3f3f3f
#define NINF 0xf3f3f3f3
using namespace std;

#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]

struct node {
    int s[2];  // 左右儿子
    int p;     // 父亲
    int v;     // 节点权值
    int siz;   // 子树大小
    int tag;
    void init(int p1, int v1) {
        p = p1, v = v1;
        siz = 1;
        tag = 0;
    }
} tr[N];

int root;  // 根节点编号
int idx;   // 节点个数

void pushup(int x) {
    tr[x].siz = tr[ls(x)].siz + tr[rs(x)].siz + 1;
}

void pushdown(int x) {
    if (tr[x].tag) {
        swap(ls(x), rs(x));
        tr[ls(x)].tag ^= 1;
        tr[rs(x)].tag ^= 1;
        tr[x].tag = 0;
    }
}

// 左/右旋 6个指针的断开重连
void rotate(int x) {
    int y = tr[x].p, z = tr[y].p;
    int k = tr[y].s[1] == x;
    tr[z].s[tr[z].s[1] == y] = x;
    tr[x].p = z;
    tr[y].s[k] = tr[x].s[k ^ 1];
    tr[tr[x].s[k ^ 1]].p = y;
    tr[x].s[k ^ 1] = y;
    tr[y].p = x;
    pushup(y), pushup(x);
}

// 将x不断旋转至k的儿子，k为0则x变为根
void splay(int x, int k) {
    while (tr[x].p != k) {
        int y = tr[x].p, z = tr[y].p;
        if (z != k)  // 折转底，直转中
            (ls(y) == x) ^ (ls(z) == y) ? rotate(x) : rotate(y);
        rotate(x);
    }
    if (!k)
        root = x;
}

// 先二分查找，找到v则自增，否则添加新节点v（添加的位置必为叶子），并将v旋转至根
void insert(int v) {  // 插入
    int x = root, p = 0;
    while (x && tr[x].v != v)
        p = x, x = tr[x].s[v > tr[x].v];
    x = ++idx;
    if (p)
        tr[p].s[v > tr[p].v] = x;
    tr[x].init(p, v);
    splay(x, 0);
}

// 获取排名为k的节点编号
int getid(int k) {
    int x = root;
    while (true) {
        pushdown(x);
        if (k <= tr[ls(x)].siz)  // 其必在左子树
            x = ls(x);
        else if (k == tr[ls(x)].siz + 1)
            break;
        else
            k -= tr[ls(x)].siz + 1, x = rs(x);
    }
    return x;
}

void dfs(int o) {
    if (!o)
        return;
    pushdown(o);
    dfs(ls(o));
    if (tr[o].v != INF && tr[o].v != NINF)
        cout << tr[o].v << " ";
    dfs(rs(o));
}

void sol() {
    insert(NINF);
    insert(INF);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        insert(i);
    }
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        // 将排名为 [l+1, r+1] 聚集到一颗子树上，然后打上懒标记
        int x = getid(l), y = getid(r + 2);
        splay(x, 0);
        splay(y, x);
        tr[ls(y)].tag ^= 1;
    }
    dfs(root);
}

int main() {
    cout << setprecision(15) << fixed;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef SINGLE_INPUT
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
#else
    sol();
#endif
    return 0;
}