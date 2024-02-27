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
    vector<int> c(n+1);
    for (int i=1; i<=n; i++) {
        cin >> c[i];
    }
    vector<vector<int>> g(n+1);
    for (int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ll ans = 0;
    vector<map<int,ll>> p(n+1); // p[i][j] 第i个点为根的子树内“j颜色的个数”，根到j颜色节点间不含其他j颜色节点。
    function<void(int,int)> dfs = [&](int x, int fa) {
        // 寻找最大集合
        int mx = x;
        for (int y:g[x]) {
            if (y == fa) continue;
            dfs(y, x);
            if (p[mx].size() < p[y].size()) mx = y;
        }
        // 其他集合合并到最大集合，并统计贡献，所有集合内所有点均摊只合并logn次
        for (int y:g[x]) {
            if (y == fa || y == mx) continue;
            for (auto [clr,cnt]:p[y]) { 
                if (clr != c[x]) { // clr与根节点颜色不同
                    // 当前p[y]集合中clr颜色可以作为路径一端，而mx集合中的clr可以作为路径另一段
                    ans += p[mx][clr]*cnt;
                }
                p[mx][clr]+=cnt; // 合并一种颜色到mx
            }
        }
        if (mx != x) swap(p[mx], p[x]);
        ans += p[x][c[x]];
        p[x][c[x]] = 1;
        // cout << x << " " << p[x] << endl;
    };
    dfs(1, 0);
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