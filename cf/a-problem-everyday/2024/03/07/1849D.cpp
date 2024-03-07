
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
    vector<int> a(n);
    for (auto& i:a) cin >> i;
    vector<int> b;
    for (int i=0,j; i<n; i=max(i+1, j)) {
        j = i;
        int mx = 0;
        while (j<n && a[j] != 0) mx = max(a[j], mx), j++;
        b.push_back(mx);
    }
    // cout << a << endl;
    // cout << b << endl;
    int sz = b.size();
    vector<int> f(sz, -1);
    function<int(int)> dfs = [&](int x) {
        if (x < 0) return 0;
        if (x == 0) return 1;
        if (f[x] != -1) return f[x];
        int res = dfs(x-1)+1;
        if (b[x-1] == 1) res = min(res, dfs(x-2)+1);
        if (b[x-1] == 2) res = min(res, dfs(x-3)+1);
        if (b[x-1] == 0) {
            if (b[x]) res = min(res, dfs(x-2)+1);
            else res = min(res, dfs(x-1)+1);
        }
        return f[x] = res;
    };
    cout << dfs(sz-1) << "\n";
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
