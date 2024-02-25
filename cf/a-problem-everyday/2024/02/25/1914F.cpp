
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
    for (int i=2; i<=n; i++) {
        int x;
        cin >> x;
        g[x].push_back(i);
    }
    vector<ll> son(n+1);
    function<ll(int)> dfs1 = [&](int x) {
        son[x] = 1;
        for (auto y:g[x]) {
            son[x] += dfs1(y);
        }
        return son[x];
    };
    dfs1(1);
    function<ll(int)> dfs2 = [&](int x)->ll { // x子树中匹配最多的个数。
        ll s = 0, mx = 0, u = 0;
        for (auto y:g[x]) {
            s += son[y];
            if (son[y] > mx) {
                mx = son[y];
                u = dfs2(y);
            } else if (son[y] == mx) {
                u = max(u, dfs2(y));
            }
        }
        ll ans = 0;
        // mx <= s - mx 可以全部匹配，奇数剩一个 
        if (2*mx <= s) {
            return (son[x]-1)/2; //下取整
        } else {
            return s - mx + min(u*2, 2*mx-s)/2; // mx - (s - mx) 不能被其他子树匹配的点，内部消化。
        }
    };
    cout << dfs2(1) << "\n";
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
