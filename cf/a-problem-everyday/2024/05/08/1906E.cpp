
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
    int n;
    cin >> n;
    vector<int> c(2*n);
    for (auto& i:c) cin >> i;
    vector<vector<int>> g;
    for (int i=0; i<2*n;) {
        int j = i+1;
        while (j<2*n && c[i] > c[j]) j++;
        vector<int> t;
        while (i<j) {
            t.push_back(c[i]);
            i++;
        }
        g.emplace_back(t);
    }
    // cout << g << endl;
    int sz = g.size();
    vector<vector<int>> f(sz, vector<int>(n+1, -1));
    // f[i][j] = f[i-1][j] or f[i-1][j-g[i].size()]
    function<int(int,int)> dfs = [&](int i, int j)->int {
        if (i == -1) return j == 0;
        if (f[i][j] != -1) return f[i][j];
        f[i][j] = dfs(i-1, j);
        if (j>=g[i].size()) f[i][j] |= dfs(i-1, j-g[i].size());
        return f[i][j];
    };
    // for (int i=0; i<sz; i++) {
    //     for (int j=0; j<=n; j++) {
    //         cout << i << " " << j << " = " << dfs(i,j) << endl;
    //     }
    // }
    if (dfs(sz-1, n) == 0) {
        cout << "-1\n";
        return ;
    }
    vector<int> p;
    for (int i=sz-1, j=n; i>=0; i--) {
        if (dfs(i-1,j)) continue;
        j -= g[i].size();
        p.push_back(i);
    }
    reverse(p.begin(), p.end());
    // cout << p << endl;
    vector<int> a, b;
    int idx = 0;
    for (int i=0; i<sz; i++) {
        if (idx<p.size() && p[idx] == i) {
            for (int j:g[i]) a.push_back(j);
            idx++;
        } else {
            for (int j:g[i]) b.push_back(j);
        }
    }
    // cout << a << endl;
    // cout << b << endl;
    // if (a.size() != b.size()) {
    //     cout << a.size() << " " << b.size() << endl;
    //     assert(0);
    // }
    for (int i:a) cout << i << " "; cout << "\n";
    for (int i:b) cout << i << " "; cout << "\n";
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
