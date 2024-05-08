
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
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
    int n, k;
    cin >> n >> k;
    vector<vector<pair<int,int>>> g(n);
    vector<int> d(n);
    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        d[x]++;
        d[y]++;
        g[x].emplace_back(y, i);
        g[y].emplace_back(x, i);
    }
    sort(d.rbegin(), d.rend());
    int c = d[k];
    vector<int> ans(n-1);
    function<void(int,int,int)> dfs = [&](int u, int fa, int val) {
        for (auto [v, p]:g[u]) {
            if (v == fa) continue;
            ans[p] = (++val)%c;
            dfs(v, u, val);
        }
    };
    dfs(0, -1, c-1);
    cout << c << "\n";
    for (auto i:ans) {
        cout << i+1 << " ";
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
