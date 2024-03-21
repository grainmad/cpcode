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
    vector<vector<int>> g(n+1);
    vector<vector<int>> d(3, vector<int>(n+1));
    for (int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int c = 0;
    function<void(int,int,int)> dfs = [&](int u, int fa, int o) {
        for (int v : g[u]) {
            if (v == fa) continue;
            d[o][v] = d[o][u] + 1;
            if (d[o][v] > d[o][c]) c = v;
            dfs(v, u, o);
        }
    };
    dfs(1, 0, 0);
    dfs(c, 0, 1);
    dfs(c, 0, 2);
    // cout << d << endl;
    // d[2][c] 直径
    vector<int> h; // 某条直径上的中心点,直径奇数一个,偶数两个
    for (int i=1; i<=n; i++) {
        if (d[1][i]+d[2][i] == d[2][c] && abs(d[1][i]-d[2][i]) == d[2][c]%2) h.push_back(i);
    }
    if(h.size() == 1) {
        cout << d[2][c]/2+1 << "\n";
        for (int i=0; i<=d[2][c]/2; i++) {
            cout << h[0] << " " << i << "\n";
        }
    } else {
        vector<pair<int,int>> p;
        for (int i=d[2][c]/2; i>=0; i-=2) {
            p.emplace_back(h[0], i);
            p.emplace_back(h[1], i);
        }
        cout << p.size() << "\n";
        for (auto [x, y]:p) {
            cout << x << " " << y << "\n";
        }
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