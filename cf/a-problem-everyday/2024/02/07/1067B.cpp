
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

void sol() {
    int n, k;
    cin >> n >> k;
    if (n<4) {
        cout << "No\n";
        return ;
    }
    vector<vector<int>> g(n+1);
    for (int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int s = -1;
    for (int i=1; i<=n; i++) {
        if (g[i].size() == 1) s = i;
    }
    vector<vector<int>> dis(2, vector<int>(n+1, -1));
    function<void(int,int,int)> dfs = [&](int x, int v, int o) {
        dis[o][x] = v;
        for (int y:g[x]) {
            if (dis[o][y] == -1) {
                dfs(y, v+1, o);
            }
        }
    };
    dfs(s, 0, 0);
    int d = 1;
    for (int i=1; i<=n; i++) {
        if (dis[0][i] > dis[0][d]) d = i;
    }
    dfs(d, 0, 1);

    vector<int> t;
    for (int i=1; i<=n; i++) {
        if (dis[0][i] == k && dis[1][i] == k) t.push_back(i);
    }
    // cout << t << endl;
    if (t.size() != 1) {
        cout << "No\n";
        return ;
    }
    function<bool(int,int,int)> check = [&](int x, int fa, int lev) {
        if (lev == k) {
            return g[x].size() == 1;
        }
        if (g[x].size() == 1) {
            return lev == k;
        }
        if (!lev && g[x].size() < 3) return false;
        if (lev && g[x].size() < 4) return false;
        for (auto y:g[x]) {
            if (y == fa) continue;
            if (!check(y, x, lev+1)) return false;
        }
        return true;
    };
    cout << (check(t[0], -1, 0)?"Yes\n":"No\n");
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
