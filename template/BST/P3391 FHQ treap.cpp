#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 100005
#define MOD 998244353
using namespace std;

struct node {
    int l, r;  // 左右儿子
    int val;   // 树的权值
    int rnd;   // 堆的随机值
    int size;  // 子树大小
    int tag;   // 懒标记
} tr[N];
int root, idx;

void newnode(int& x, int v) {
    x = ++idx;
    tr[x].val = v;
    tr[x].rnd = rand();
    tr[x].size = 1;
    tr[x].tag = 0;
}

void pushup(int p) {
    tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + 1;
}

void pushdown(int p) {
    if (tr[p].tag) {
        swap(tr[p].l, tr[p].r);
        tr[tr[p].l].tag ^= 1;
        tr[tr[p].r].tag ^= 1;
        tr[p].tag = 0;
    }
}

// 按照排名进行分裂，节点排名小于等于v划分到x，其余划分到y
void split(int p, int v, int& x, int& y) {
    if (!p) {
        x = y = 0;
        return;
    }
    pushdown(p);                 // 向下分裂过程中处理懒标记
    if (tr[tr[p].l].size < v) {  // 当前划分到x
        v -= tr[tr[p].l].size + 1;
        x = p;
        split(tr[x].r, v, tr[x].r, y);
    } else {
        y = p;
        split(tr[y].l, v, x, tr[y].l);
    }
    pushup(p);
}

// x树和y树合并成新树，返回根节点
int merge(int x, int y) {
    if (!x || !y)
        return x + y;
    if (tr[x].rnd < tr[y].rnd) {
        pushdown(x);
        tr[x].r = merge(tr[x].r, y);
        pushup(x);
        return x;
    } else {
        pushdown(y);
        tr[y].l = merge(x, tr[y].l);
        pushup(y);
        return y;
    }
}

// 插入v节点，以v为分割拆分成两个树x和y，将x,v,y三树合并
void insert(int v) {
    int x, y, z;
    split(root, v, x, y);
    newnode(z, v);
    root = merge(merge(x, z), y);
}

void dfs(int p) {
    if (!p)
        return;
    pushdown(p);
    dfs(tr[p].l);
    cout << tr[p].val << " ";
    dfs(tr[p].r);
}

void sol() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        insert(i);
    }
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        int a, b, c;
        // 由于按照排名分裂的缘故，分裂有顺序要求
        split(root, r, a, c);   // 先分开[1 r] [r+1, n]
        split(a, l - 1, a, b);  // 再分开[1, l-1] [l, r]
        tr[b].tag ^= 1;
        root = merge(merge(a, b), c);
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