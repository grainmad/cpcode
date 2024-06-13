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
    int n;
    cin >> n;
    vector g(n+1, vector<int>());
    for (int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    map<pair<int,int>, int> f; //f {0/1, i} 不含/含i的子树最大叶子数 
    map<pair<int,int>, int> h; //h {0/1, i} 整棵树不含/含i的最大叶子数
    function<int(int,int,int)> dfs1 = [&](int c, int u, int fa) {
        if (f.count({c, u})) return f[{c, u}];
        int rt = c;
        for (auto v:g[u]) {
            if (v == fa) continue;
            if (c) rt += dfs1(0, v, u);
            else rt += max(dfs1(0, v, u), dfs1(1, v, u));
        }
        return f[{c, u}] = rt;
    };
    h[{0, 1}] = dfs1(0, 1, 0);
    h[{1, 1}] = dfs1(1, 1, 0);
    int ans = h[{0, 1}]+(g[1].size()==1);
    function<void(int, int)> dfs2 = [&](int u, int fa) {
        int bro = h[{0, fa}] - max(dfs1(0, u, fa), dfs1(1, u, fa));
        h[{0, u}] = max(h[{1, fa}], dfs1(0, u, fa)+bro);
        h[{1, u}] = dfs1(1, u, fa) + bro;
        ans = max(ans, h[{0, u}]+(g[u].size() == 1));
        for (auto v:g[u]) {
            if (v == fa) continue;
            dfs2(v, u);
        }
    };
    for (int v:g[1]) {
        dfs2(v, 1);
    }
    // cout << f << endl;
    // cout << h << endl;
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