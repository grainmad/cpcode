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
    int cnt = 0;
    vector g(n+1, vector<int>(n+1, -1));
    vector vis(n+1, vector<int>(n+1, 0));
    auto ask = [&](int x, int y) {
        if (g[x][y] != -1) return g[x][y];
        cout << "? " << x << " " << y << endl;
        cnt++;
        int rt;
        cin >> rt;
        return g[x][y] = rt;
    };
    vector<int> v(n+1);
    auto dfs = [&](auto&& self, int x, int y) {
        v[x] = v[y] = 1;
        if (g[x][y] != -1) return ;
        int mid = ask(x, y);
        if (mid == x) return ;
        self(self, x, mid);
        self(self, mid, y);
    };
    for (int i=2; i<=n; i++) {
        if (v[i]) continue;
        dfs(dfs, 1, i);
    }
    cout << "!";
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i == j || vis[i][j]) continue;
            if (g[i][j] == i) {
                cout << " " << i << " " << j;
                vis[j][i] = 1;
            }
        }
    }
    cout << endl;
    // cout << "ask cnt: " << cnt << endl;
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