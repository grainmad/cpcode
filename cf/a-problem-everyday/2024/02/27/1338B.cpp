
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
    int n;
    cin >> n;
    vector<vector<int>> g(n+1);
    for (int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int even = 1;
    function<void(int, int, int)> dfs = [&](int u, int fa, int stp) {
        int c = 0;
        for (int v:g[u]) {
            if (v == fa) continue;
            c++;
            dfs(v, u, stp+1);
        }
        if (c == 0 && stp%2 == 1) even = 0;
    };
    for (int i=1; i<=n; i++) {
        if (g[i].size() == 1) {
            dfs(i, 0, 0);
            break;
        }
    }
    cout << (even?1:3) << " ";
    vector<int> cnt(n+1);
    for (int i=1; i<=n; i++) {
        if (g[i].size() == 1) cnt[g[i][0]]++;
    }
    int ans = n-1;
    for (int i=1; i<=n; i++) {
        ans -= max(0, cnt[i]-1);
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
