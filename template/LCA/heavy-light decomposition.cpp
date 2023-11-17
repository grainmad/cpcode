// 1.6s
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int n, m, s, a, b;

// !!! 空节点为0，0为根节点的父节点

const int N = 500010;
vector<int> e[N];
int fa[N],   // fa[i] i的父节点
    son[N],  // son[i] i的重儿子
    dep[N],  // dep[i] i的深度
    siz[N],  // siz[i] i子树的节点数
    top[N];  // top[i] i所在链的顶端（轻儿子）

// 重链剖分将产生logn条链，基于树上启发式合并

void dfs1(int u, int f) {  // 搞fa,dep,son
    fa[u] = f;
    siz[u] = 1;
    dep[u] = dep[f] + 1;
    for (int v : e[u]) {
        if (v == f)
            continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[son[u]] < siz[v])  // 重儿子为节点数多的儿子
            son[u] = v;
    }
}
void dfs2(int u, int t) {  // 搞top
    top[u] = t;            // 记录链头
    if (!son[u])           // 每个节点必有重儿子，除非为叶子
        return;            // 无重儿子
    dfs2(son[u], t);       // 搜重儿子
    for (int v : e[u]) {
        if (v == fa[u] || v == son[u])
            continue;
        dfs2(v, v);  // 搜轻儿子，轻儿子是一条链的开端
    }
}
int lca(int u, int v) {
    while (top[u] !=
           top[v]) {  // 只有logn条链，跳转不超过logn次将处于同一条链上
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        u = fa[top[u]];
    }
    // 深度小的为lca
    return dep[u] < dep[v] ? u : v;
}
int main() {
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs1(s, 0);
    dfs2(s, s);
    while (m--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}