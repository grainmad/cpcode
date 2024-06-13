#include <bits/stdc++.h>
#define SINGLE_INPUT
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
    vector g(n+1, vector<int>());
    for (int i=2; i<=n; i++) {
        int x;
        cin >> x;
        g[i].push_back(x);
        g[x].push_back(i);
    }
    vector<int> deep(n+1);
    function<int(int,int)> dfs1 = [&](int u, int fa) {
        int rt = 1;
        for (int v:g[u]) {
            if (fa == v) continue;
            rt = max(rt, dfs1(v, u)+1);
        }
        return deep[u] = rt;
    };
    dfs1(1, 0);
    function<int(int,int)> dfs2 = [&](int u, int fa) {
        int rt = 0;
        for (int v:g[u]) {
            if (fa == v) continue;
            rt += dfs2(v, u);
        }
        return max(rt, deep[u]);
    };
    cout << dfs2(1, 0) << "\n";
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