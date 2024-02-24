#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define MOD 998244353
using namespace std;

template<class t,class u> ostream& operator<<(ostream& os,const pair<t,u>& p) {
    return os<<'['<<p.first<<", "<<p.second<<']';
}
template<class t> ostream& operator<<(ostream& os,const vector<t>& v) {
    os<<'['; int s = 1;
    for(auto e:v) { if (s) s = 0; else os << ", "; os << e; }
    return os<<']';
}
template<class t,class u> ostream& operator<<(ostream& os,const map<t,u>& mp){
    os<<'{'; int s = 1;
    for(auto [x,y]:mp) { if (s) s = 0; else os << ", "; os<<x<<": "<<y; }
    return os<<'}';
}

#define N 100005

std::vector<int> g[N];

// 默认不存在的节点编号是0
int fa[N][31], dep[N];

// dfs，用来为 lca 算法做准备。接受两个参数：dfs 起始节点和它的父亲节点。
void dfs(int u, int fno) {
    // 初始化：第 2^0 = 1 个祖先就是它的父亲节点，dep 也比父亲节点多 1。
    fa[u][0] = fno;
    dep[u] = dep[fa[u][0]] + 1;
    // 初始化：其他的祖先节点：第 2^i 的祖先节点是第 2^(i-1) 的祖先节点的第
    // 2^(i-1) 的祖先节点。
    for (int i = 1; i < 31; ++i) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    // 遍历子节点来进行 dfs。
    for (int v : g[u]) {
        if (v == fno)
            continue;
        dfs(v, u);
    }
}

// lca。用倍增算法算取 x 和 y 的 lca 节点。
int lca(int x, int y) {
    // 令 y 比 x 深。
    if (dep[x] > dep[y])
        swap(x, y);
    // 令 y 和 x 在一个深度。
    int tmp = dep[y] - dep[x];
    for (int j = 0; tmp; ++j, tmp >>= 1)
        if (tmp & 1)
            y = fa[y][j];
    // 如果这个时候 y = x，那么 x，y 就都是它们自己的祖先。
    if (y == x)
        return x;
    // 不然的话，找到第一个不是它们祖先的两个点。
    for (int j = 30; j >= 0 && y != x; --j) {
        if (fa[x][j] != fa[y][j]) {
            x = fa[x][j];
            y = fa[y][j];
        }
    }
    // 返回结果。
    return fa[x][0];
}

void add(int x, int y) {
    g[x].push_back(y);
    g[y].push_back(x);
}

// 注意初始时以0作为根节点的父亲，dfs(u,0)


void sol() {
    int n;
    cin >> n;
    for (int i=0; i<=n; i++) {
        g[i].clear();
        dep[i] = 0;
        memset(fa[i], 0, sizeof(fa[i]));
    }
    for (int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y);
    }
    dfs(1, 0);
    
    int m;
    cin >> m;
    vector<int> d(n+1);
    vector<int> e, f(1<<m, N);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        int f = lca(x, y);
        while (x != f) {
            d[x] |= 1<<i;
            if (fa[x][0] == f) e.push_back(x);
            x = fa[x][0];
        }
        
        while (y != f) {
            d[y] |= 1<<i;
            if (fa[y][0] == f) e.push_back(y);
            y = fa[y][0];
        }
    }
    f[0] = 0;
    for (int x:e) {
        int i = d[x];
        for (int j=0; j<(1<<m); j++) {
            f[j|i] = min(f[j]+1, f[j|i]);
        }
    }
    cout << f[(1<<m)-1] << "\n";

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