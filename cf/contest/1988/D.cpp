#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define M 23
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
    vector<ll> a(n);
    vector<vector<int>> g(n);
    for(auto& i:a) cin >> i;
    for (int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector f(n, vector<ll>(M, -1));
    function<ll(int,int,int)> dfs = [&](int x, int p, int fa) {
        if (f[x][p] != -1) return f[x][p];
        f[x][p] = p*a[x];
        for (int y:g[x]) {
            if (y == fa) continue;
            ll mn = 1e18;
            for (int i=1; i<M; i++) {
                if (i == p) continue;
                mn = min(mn, dfs(y, i, x));
            }
            f[x][p] += mn;
        }
        return f[x][p];
    };
    
    ll ans = 1e18;
    for (int i=1; i<M; i++) {
        ans = min(ans, dfs(0, i, -1));
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
    while (t--) {
        sol();
    }
#else
    sol();
#endif
    return 0;
}