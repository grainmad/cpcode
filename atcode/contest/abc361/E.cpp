#include <bits/stdc++.h>
#define SINGLE_INPUT
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
    int n;
    cin >> n;
    ll s = 0;
    vector<vector<pair<int,int>>> g(n+1);
    vector<vector<ll>> d(3, vector<ll>(n+1));
    for (int i=1; i<n; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        s += x;
        g[u].emplace_back(v, x);
        g[v].emplace_back(u, x);
    }
    int c = 0;
    function<void(int,int,int)> dfs = [&](int u, int fa, int o) {
        for (auto [v, x] : g[u]) {
            if (v == fa) continue;
            d[o][v] = d[o][u] + x;
            if (d[o][v] > d[o][c]) c = v;
            dfs(v, u, o);
        }
    };
    dfs(1, 0, 0);
    dfs(c, 0, 1);
    dfs(c, 0, 2);
    // cout << d << endl;
    // d[2][c] 直径
    cout << s*2 - d[2][c] << "\n";

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