
#include <bits/stdc++.h>
// #define SINGLE_INPUT
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
    vector<int> son(n+1), w(n+1);
    function<int(int,int)> getson = [&](int x, int fa) {
        son[x] = 1;
        for (auto y:g[x]) {
            if (y == fa) continue;
            son[x] += getson(y, x);
        }
        return son[x];
    };  
    getson(1, -1);
    function<void(int,int)> dfs = [&](int x, int fa) {
        w[x] = n-son[x];
        for (auto y:g[x]) {
            if (y == fa) continue;
            dfs(y, x);
            w[x] = max(w[x], son[y]);
        }
    };
    dfs(1, -1);
    // cout << w << endl;
    int mn = 1;
    for (int i=1; i<=n; i++) if (w[i] < w[mn]) mn = i;
    vector<int> mv;
    for (int i=1; i<=n; i++) {
        if (w[mn] == w[i]) mv.push_back(i);
    }
    // cout << mv << "\n";
    if (mv.size() == 1) {
        cout << 1 << " " << g[1][0] << "\n";
        cout << 1 << " " << g[1][0] << "\n";
    } else {
        if (g[mv[0]][0] == mv[1]) swap(g[mv[0]][0], g[mv[0]][1]);
        cout << mv[0] << " " << g[mv[0]][0] << "\n";
        cout << mv[1] << " " << g[mv[0]][0] << "\n";
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
