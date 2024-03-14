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
    ll n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<vector<ll>> a(n, vector<ll>(m));
    vector<vector<ll>> dp(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
        dp[i][0] = 1;
    }
    vector<ll> f(n);
    for (int i = 0; i < n; i++) {
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
        pq.emplace(1, 0);
        for (int j = 1; j < m; j++) {
            while (pq.top().second + d + 1 < j)
                pq.pop();
            ll mn = pq.top().first;
            dp[i][j] = mn + a[i][j] + 1;
            pq.emplace(dp[i][j], j);
        }
        f[i] = dp[i][m - 1];
    }
    // cout << dp << endl;
    // cout << f << endl;
    ll s = 0, mn = 1e18;
    for (int i = 0; i < n; i++) {
        s += f[i];
        if (i >= k)
            s -= f[i - k];
        if (i >= k - 1)
            mn = min(mn, s);
    }
    cout << mn << "\n";
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