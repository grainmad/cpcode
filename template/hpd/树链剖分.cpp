// p3384
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int N = 100010;
int n, m, a, b, root, P, w[N];
#define ll long long
#define lc (u << 1)
#define rc (u << 1 | 1)
vector<int> e[N];
int fa[N], dep[N], sz[N], son[N];
int top[N], id[N], nw[N], cnt;  // 重链

/*
    fa[u] u的父节点
    dep[u] u的深度
    sz[u] 以u为根的子树节点数
    son[u] u的重儿子
    top[u] u所在重链的顶点
    id[u] u剖分后的新编号cnt
    nw[cnt] 新编号对应的权值
*/

struct tree {
    int l, r;
    ll add, sum;
} tr[N * 4];  // 线段树

void dfs1(int u, int father) {  // 搞fa,dep,sz,son
    fa[u] = father, dep[u] = dep[father] + 1, sz[u] = 1;
    for (int v : e[u]) {
        if (v == father)
            continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[son[u]] < sz[v])
            son[u] = v;
    }
}
void dfs2(int u, int t) {  // 搞top,id,nw
    top[u] = t, id[u] = ++cnt, nw[cnt] = w[u];
    if (!son[u])
        return;
    dfs2(son[u], t);
    for (int v : e[u]) {
        if (v == fa[u] || v == son[u])
            continue;
        dfs2(v, v);
    }
}
void pushup(int u) {
    tr[u].sum = tr[lc].sum + tr[rc].sum;
}
void pushdown(int u) {
    if (tr[u].add) {
        tr[lc].sum += tr[u].add * (tr[lc].r - tr[lc].l + 1);
        tr[rc].sum += tr[u].add * (tr[rc].r - tr[rc].l + 1);
        tr[lc].add += tr[u].add;
        tr[rc].add += tr[u].add;
        tr[u].add = 0;
    }
}
void build(int u, int l, int r) {  // 构建线段树
    tr[u] = {l, r, 0, nw[r]};
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(lc, l, mid), build(rc, mid + 1, r);
    pushup(u);
}
ll query(int u, int l, int r) {  // 线段树查询
    if (l <= tr[u].l && tr[u].r <= r)
        return tr[u].sum;
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    ll res = 0;
    if (l <= mid)
        res += query(lc, l, r);
    if (r > mid)
        res += query(rc, l, r);
    return res;
}
ll query_path(int u, int v) {  // 查询路径
    ll res = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        res += query(1, id[top[u]], id[u]);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v])
        swap(u, v);
    res += query(1, id[v], id[u]);  // 最后一段
    return res;
}
ll query_tree(int u) {  // 查询子树
    return query(1, id[u], id[u] + sz[u] - 1);
}
void update(int u, int l, int r, int k) {  // 线段树修改
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].add += k;
        tr[u].sum += k * (tr[u].r - tr[u].l + 1);
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid)
        update(lc, l, r, k);
    if (r > mid)
        update(rc, l, r, k);
    pushup(u);
}
void update_path(int u, int v, int k) {  // 修改路径
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        update(1, id[top[u]], id[u], k);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v])
        swap(u, v);
    update(1, id[v], id[u], k);  // 最后一段
}
void update_tree(int u, int k) {  // 修改子树
    update(1, id[u], id[u] + sz[u] - 1, k);
}
int main() {
    scanf("%d%d%d%d", &n, &m, &root, &P);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs1(root, 0);
    dfs2(root, root);  // 把树拆成链
    build(1, 1, n);    // 用链建线段树
    while (m--) {
        int t, u, v, k;
        scanf("%d%d", &t, &u);
        if (t == 1) {
            scanf("%d%d", &v, &k);
            update_path(u, v, k);
        } else if (t == 3) {
            scanf("%d", &k);
            update_tree(u, k);
        } else if (t == 2) {
            scanf("%d", &v);
            printf("%d\n", query_path(u, v) % P);
        } else
            printf("%d\n", query_tree(u) % P);
    }
}