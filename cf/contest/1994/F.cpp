#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

random_device seed;
ranlux48 engine(seed());
int random(int l, int r) {
    uniform_int_distribution<> distrib(l, r);
    return distrib(engine);
}
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
    int n, m;
    cin >> n >> m;
    vector<int> deg(n);
    vector<vector<pair<int,int>>> g(n), ng(n);
    for (int i=0; i<m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--; y--;
        deg[x] ^= 1;
        deg[y] ^= 1;
        g[x].emplace_back(y, i);
        g[y].emplace_back(x, i);
        if (!c) {
            ng[x].emplace_back(y, i);
            ng[y].emplace_back(x, i);
        }
    }
    vector<int> usd(n), del(m);
    function<void(int)> dfs = [&](int u) {
        usd[u] = 1;
        for (auto [v, e]:ng[u]) {
            if (usd[v]) continue;
            dfs(v);
            if (deg[v]) {
                deg[v] ^= 1;
                deg[u] ^= 1;
                del[e] = 1;
            }
        }
    };
    for (int i=0; i<n; i++) {
        if (usd[i]) continue; 
        dfs(i);
        if (deg[i]) {
            cout << "NO\n";
            return ;
        }
    }
    vector<int> ans;
    function<void(int)> euler = [&](int u) {
        while(g[u].size()) {
            auto [v, e] = g[u].back();
            g[u].pop_back();
            if (del[e]) continue;
            del[e] = 1;
            euler(v);
        }
        ans.push_back(u);
    };
    euler(0);
    cout << "YES\n";
    cout << ans.size()-1 << "\n";
    for (int i:ans) {
        cout << i + 1 << " ";
    }
    cout << "\n";
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