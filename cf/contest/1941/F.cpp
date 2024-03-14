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
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m), c(k);
    for (auto& i : a)
        cin >> i;
    for (auto& i : b)
        cin >> i;
    for (auto& i : c)
        cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    ll x = 0, y = 0;
    ll sp1 = 0, sp2 = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] >= sp1) {
            sp2 = sp1;
            sp1 = a[i] - a[i - 1];
            x = a[i - 1], y = a[i];
        } else if (a[i] - a[i - 1] > sp2) {
            sp2 = a[i] - a[i - 1];
        }
    }
    if (sp1 == sp2) {
        cout << sp1 << "\n";
        return;
    }
    ll ans = sp1;
    for (ll i : b) {
        ll u = upper_bound(c.begin(), c.end(), (x + y) / 2 - i) - c.begin();
        if (u != k) {
            ll v = c[u] + i;
            if (x < v && v < y)
                ans = min(ans, max({sp2, y - v, v - x}));
        }
        if (u != 0) {
            ll v = c[u - 1] + i;
            if (x < v && v < y)
                ans = min(ans, max({sp2, y - v, v - x}));
        }
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