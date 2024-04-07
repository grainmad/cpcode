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
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<ll> C(n), sC(n);
    for (auto& i : C)
        cin >> i;
    ll f0 = 0;
    function<void(int, int, int)> dfs1 = [&](int x, int fa, int stp) {
        sC[x] += C[x];
        for (int y : g[x]) {
            if (y == fa)
                continue;
            dfs1(y, x, stp + 1);
            sC[x] += sC[y];
        }
        f0 += C[x] * stp;
    };
    dfs1(0, -1, 0);
    // cout << f0 << endl;
    // cout << sC << endl;
    ll ans = f0;
    function<void(int, int, ll)> dfs2 = [&](int x, int fa, ll cur) {
        // cout << x << " " << cur << endl;
        ans = min(ans, cur);
        for (int y : g[x]) {
            if (y == fa)
                continue;
            dfs2(y, x, cur + sC[0] - sC[y] - sC[y]);
        }
    };
    dfs2(0, -1, f0);
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