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

ll fpow(ll x, ll p) {
    ll rt = 1;
    while (p) {
        if (p&1) rt *= x, rt %= MOD;
        x *= x;
        x %= MOD;
        p >>= 1;
    }
    return rt;
}

// n!/(m!(n-m)!)
ll comb(ll n, ll m) {
    ll u = 1, d = 1;
    for (ll i = n; i>n-m; i--) {
        u = u*i%MOD;
        d = d*(i-n+m)%MOD;
    }
    return u*fpow(d, MOD-2)%MOD;
}

void sol() {
    ll n, c;
    cin >> n >> c;
    vector<ll> l(n+1), r(n+1), v(n+1);
    for (int i=1; i<=n; i++) {
        cin >> l[i] >> r[i] >> v[i];
    }
    ll ans = 1;
    ll L = 1, cnt = 0;
    function<void(int)> dfs = [&](int u) {
        if (l[u] != -1) {
            dfs(l[u]);
        }
        if (v[u] == -1) cnt++;
        else {
            ans = ans*comb(v[u]-L+cnt, cnt)%MOD;
            cnt = 0;
            L = v[u];
        }
        if (r[u] != -1) {
            dfs(r[u]);
        }
    };
    dfs(1);
    cout << ans*comb(c-L+cnt, cnt)%MOD << "\n";
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
