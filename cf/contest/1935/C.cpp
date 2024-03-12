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
    ll n, l;
    cin >> n >> l;
    vector<pair<ll, ll>> a(n);
    for (auto& [i,j]:a) cin >> i >> j;
    sort(a.begin(), a.end(), [](auto& x, auto& y) {
        if (x.second == y.second) return x.first < y.first;
        return x.second < y.second;
    });
    // cout << a << endl;
    vector<vector<ll>> f(n+1, vector<ll>(n, 1e18)); // f[i][j] 选了i个，且j一定选的最少时间
    for (int i=0; i<n; i++) f[1][i] = a[i].first;
    for (int i=2; i<=n; i++) {
        ll mn = f[i-1][i-2] - a[i-2].second;
        for (int j=i-1; j<n; j++) {
            f[i][j] = mn + a[j].first + a[j].second;
            mn = min(mn, f[i-1][j]-a[j].second);
        }
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<n; j++) {
            if (f[i][j] <= l) ans = max(ans, i);
        }
    }
    // cout << f << endl;
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