
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
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

struct Rode {
    int u, v, d;
    Rode(int u, int v, int d):u(u),v(v),d(d) {}
    bool operator<(const Rode& o) {
        return d > o.d;
    }
};

struct augment_path {
    vector<vector<int> > g;
    vector<int> pa;  // 匹配
    vector<int> pb;
    vector<int> vis;  // 访问
    int n, m;         // 两个点集中的顶点数量
    int dfn;          // 时间戳记
    int res;          // 匹配数

    augment_path(int _n, int _m) : n(_n), m(_m) {
        assert(0 <= n && 0 <= m);
        pa = vector<int>(n, -1);
        pb = vector<int>(m, -1);
        vis = vector<int>(n);
        g.resize(n);
        res = 0;
        dfn = 0;
    }

    void add(int from, int to) {
        assert(0 <= from && from < n && 0 <= to && to < m);
        g[from].push_back(to);
    }

    bool dfs(int v) {
        vis[v] = dfn;
        for (int u : g[v]) {
            if (pb[u] == -1) {
                pb[u] = v;
                pa[v] = u;
                return true;
            }
        }
        for (int u : g[v]) {
            if (vis[pb[u]] != dfn && dfs(pb[u])) {
                pa[v] = u;
                pb[u] = v;
                return true;
            }
        }
        return false;
    }

    int solve() {
        while (true) {
            dfn++;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (pa[i] == -1 && dfs(i)) {
                    cnt++;
                }
            }
            if (cnt == 0) {
                break;
            }
            res += cnt;
        }
        return res;
    }
};

void sol() {
    int n, m;
    cin >> n >> m;
    vector<Rode> rd;
    for (int i=0; i<m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        rd.emplace_back(--u, --v, d);
    }
    sort(rd.begin(), rd.end());
    // cout << deg << endl;
    ll l = 0, r = 1e9+7;
    while (l<r) {
        ll m = l+r>>1;
        // cout << l << " " << r << " " << m << endl;
        augment_path ap(n, n);
        for (auto [u,v,d]:rd) {
            if (d<=m) ap.add(u, v);
        }
        int ans = ap.solve();
        if (ans == n) {
            r = m;
        } else {
            l = m+1;
        }
    }
    if (r == 1e9+7) cout << "-1\n";
    else cout << r << "\n";


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
