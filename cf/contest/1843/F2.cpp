#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 200005
#define LG 31
#define MOD 998244353
using namespace std;

std::vector<int> g[N];

int fa[N][LG], dep[N];

struct Info {
    int sum, max_prf, min_prf, max_suf, min_suf, max_seg, min_seg;
    Info(int val = 0) {
        sum = val;
        max_prf = max_suf = max_seg = max(0, val);
        min_prf = min_suf = min_seg = min(0, val);
    }
    Info operator+(const Info& o) {
        Info rt(0);
        rt.sum = sum + o.sum;
        rt.min_prf = min(min_prf, sum + o.min_prf);
        rt.max_prf = max(max_prf, sum + o.max_prf);
        rt.min_suf = min(o.min_suf, o.sum + min_suf);
        rt.max_suf = max(o.max_suf, o.sum + max_suf);
        rt.min_seg = min({min_suf + o.min_prf, min_seg, o.min_seg});
        rt.max_seg = max({max_suf + o.max_prf, max_seg, o.max_seg});
        return rt;
    }
} info[N][LG];

// fa[i][j] i节点的第2^j个祖先
// info[i][j] 在i节点的第2^j个祖先（不包含f[i][j]）到当前的节点i的区间信息。

// dfs，用来为 lca 算法做准备。接受两个参数：dfs 起始节点和它的父亲节点。
void dfs(int u, int fno) {
    // 初始化：第 2^0 = 1 个祖先就是它的父亲节点，dep 也比父亲节点多 1。
    fa[u][0] = fno;
    dep[u] = dep[fa[u][0]] + 1;
    // 初始化：其他的祖先节点：第 2^i 的祖先节点是第 2^(i-1) 的祖先节点的第
    // 2^(i-1) 的祖先节点。
    for (int i = 1; i < LG; ++i) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        info[u][i] = info[fa[u][i - 1]][i - 1] + info[u][i - 1];
    }
    // 遍历子节点来进行 dfs。
    for (int v : g[u]) {
        if (v == fno)
            continue;
        dfs(v, u);
    }
}

Info lca(int x, int y) {
    // 令 y 比 x 深。
    if (dep[x] > dep[y])
        swap(x, y);
    // 令 y 和 x 在一个深度。
    Info a, b;
    int tmp = dep[y] - dep[x];
    for (int j = 0; tmp; ++j, tmp >>= 1)
        if (tmp & 1)
            b = info[y][j] + b, y = fa[y][j];
    // 如果这个时候 y = x，那么 x，y 就都是它们自己的祖先。
    if (y == x) {
        return info[x][0] + b;
    }
    // 不然的话，找到第一个不是它们祖先的两个点。
    for (int j = LG - 1; j >= 0 && y != x; --j) {
        if (fa[x][j] != fa[y][j]) {
            a = info[x][j] + a;
            x = fa[x][j];
            b = info[y][j] + b;
            y = fa[y][j];
        }
    }
    // 返回结果。
    a = info[x][1] + a;
    b = info[y][0] + b;
    swap(a.max_prf, a.max_suf);
    swap(a.min_prf, a.min_suf);
    return a + b;
}

void add(int x, int y) {
    g[x].push_back(y);
    g[y].push_back(x);
}

void sol() {
    int n;
    cin >> n;
    int cur = 2;
    info[1][0] = Info(1);
    vector<tuple<int, int, int>> q;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "+") {
            int v, val;
            cin >> v >> val;
            info[cur][0] = Info(val);
            add(v, cur++);
        } else {
            int u, v, k;
            cin >> u >> v >> k;
            q.emplace_back(u, v, k);
        }
    }
    dfs(1, 0);
    for (auto [u, v, k] : q) {
        auto rt = lca(u, v);
        if (rt.min_seg <= k && k <= rt.max_seg) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    for (int i = 0; i < cur; i++) {
        g[i].clear();
    }
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