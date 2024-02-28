#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
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


void sol() {
    int n;
    cin >> n;
    vector<int> c(n+1);
    for (int i=1; i<=n; i++) {
        cin >> c[i];
    }
    vector<vector<int>> g(n+1);
    for (int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ll ans = 0;
    vector<map<int,ll>> p(n+1); // p[i][j] 第i个点为根的子树内“j颜色的个数”，根到j颜色节点间不含其他j颜色节点。
    function<void(int,int)> dfs = [&](int x, int fa) {
        // 寻找最大集合
        int mx = x;
        for (int y:g[x]) {
            if (y == fa) continue;
            dfs(y, x);
            if (p[mx].size() < p[y].size()) mx = y;
        }
        // 其他集合合并到最大集合，并统计贡献，所有集合内所有点均摊只合并logn次
        for (int y:g[x]) {
            if (y == fa || y == mx) continue;
            for (auto [clr,cnt]:p[y]) { 
                if (clr != c[x]) { // clr与根节点颜色不同
                    // 当前p[y]集合中clr颜色可以作为路径一端，而mx集合中的clr可以作为路径另一段
                    ans += p[mx][clr]*cnt;
                }
                p[mx][clr]+=cnt; // 合并一种颜色到mx
            }
        }
        if (mx != x) swap(p[mx], p[x]);
        ans += p[x][c[x]];
        p[x][c[x]] = 1;
        // cout << x << " " << p[x] << endl;
    };
    dfs(1, 0);
    cout << ans << "\n";
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
/*
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define MOD 998244353
using namespace std;

template <class t, class u>
ostream& operator<<(ostream& os, const pair<t, u>& p) {
    return os << '[' << p.first << ", " << p.second << ']';
}
template <class t>
ostream& operator<<(ostream& os, const vector<t>& v) {
    os << '[';
    int s = 1;
    for (auto e : v) {
        if (s)
            s = 0;
        else
            os << ", ";
        os << e;
    }
    return os << ']';
}
template <class t, class u>
ostream& operator<<(ostream& os, const map<t, u>& mp) {
    os << '{';
    int s = 1;
    for (auto [x, y] : mp) {
        if (s)
            s = 0;
        else
            os << ", ";
        os << x << ": " << y;
    }
    return os << '}';
}

const int N = 200005, M = N * 2;
int h[N], to[M], ne[M], tot;
void add(int x, int y) {  // 连边
    to[++tot] = y;
    ne[tot] = h[x];
    h[x] = tot;
}

// 遍历x所连的点
vector<int> radiate(int x) {
    vector<int> rt;
    for (int i = h[x]; i; i = ne[i])
        rt.push_back(to[i]);
    return rt;
}

void clearTree() {
    // for (int i = 1; i <= n; i++) {
    //     h[i] = 0;
    // }
    function<void(int, int)> cls = [&](int x, int fa) {
        for (int i = h[x]; i; i = ne[i]) {
            int y = to[i];
            if (y == fa)
                continue;
            cls(y, x);
        }
        h[x] = 0;
    };
    cls(1, 0);  // 含1连通块清空
    tot = 0;
}

int dep[N], fa[N][20];
int dfn[N], cnt;  // dfs序
int s[N], top;    // 栈

// 初始的树是双向边, dfs(1, 0),  dep, fa, dfn
void dfs(int x, int f) {  // 树上倍增
    dfn[x] = ++cnt;
    dep[x] = dep[f] + 1;
    fa[x][0] = f;
    for (int i = 1; i <= 19; i++)
        fa[x][i] = fa[fa[x][i - 1]][i - 1];

    for (int i = h[x]; i; i = ne[i]) {
        int y = to[i];
        if (y == f)
            continue;
        dfs(y, x);
    }
}
int lca(int x, int y) {  // 求lca
    if (dep[x] < dep[y])
        swap(x, y);
    for (int i = 19; ~i; i--)
        if (dep[fa[x][i]] >= dep[y])
            x = fa[x][i];
    if (x == y)
        return y;

    for (int i = 19; ~i; i--)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}
int cmp(int a, int b) {
    return dfn[a] < dfn[b];
}

// 构建的虚树是单向边
void build(vector<int>& a) {  // 建虚树
    int k = a.size();
    sort(a.begin(), a.end(), cmp);  // 按dfs序排序
    tot = 0;         // 清空前一颗树，注意各树节点x h[x]=0
    s[top = 1] = 1;  // 根节点入栈
    if (k && a[0] != 1)
        s[++top] = a[0];
    for (int i = 1; i < k; i++) {  // 枚举查询点
        int l = lca(s[top], a[i]);
        // 对当前链连边,top出栈
        while (top > 1 && dep[s[top - 1]] >= dep[l])
            add(s[top - 1], s[top]), top--;
        // 对lca和top连边,top出栈,lca入栈
        if (l != s[top])
            add(l, s[top]), s[top] = l;
        // 查询点入栈
        s[++top] = a[i];
    }
    while (top)  // 对最后一条链连边,top出栈
        add(s[top - 1], s[top]), top--;
}

void printVtree(int x, int fa) {
    cout << x << ":";
    for (int i = h[x]; i; i = ne[i]) {
        if (to[i] == fa)
            continue;
        cout << to[i] << " ";
    }
    cout << endl;
    for (int i = h[x]; i; i = ne[i]) {
        int y = to[i];
        if (y == fa)
            continue;
        printVtree(y, x);
    }
}

void sol() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> c(n + 1);
    clearTree();
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        c[i] = x;
        g[x].push_back(i);
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs(1, 0);
    clearTree();
    ll ans = 0;
    function<ll(int, int)> Dp = [&](int x, int color) {
        ll s1 = 0, s2 = 0;
        for (int i = h[x]; i; i = ne[i]) {
            int y = to[i];
            ll rt = Dp(y, color);
            s2 += s1 * rt;
            s1 += rt;
        }
        // h[x] = 0;  // 重要
        if (c[x] == color) {
            ans += s1;
            return 1LL;
        } else {
            ans += s2;
            return s1;
        }
    };
    for (int i = 1; i <= n; i++) {
        if (g[i].size()) {
            build(g[i]);
            Dp(1, i);
            clearTree();
        }
    }
    cout << ans << "\n";
}

int main() {
    cout << setprecision(15) << fixed;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef SINGLE_INPUT
    int t;
    cin >> t;
    // T = t;
    while (t--) {
        sol();
    }
#else
    sol();
#endif
    return 0;
}

*/