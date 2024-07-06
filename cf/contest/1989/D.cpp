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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n), c(m);
    for (auto& i:a) cin >> i;
    for (auto& i:b) cin >> i;
    for (auto& i:c) cin >> i;
    int mx = *max_element(a.begin(), a.end());
    vector<ll> f(mx+1, 1e9), v(mx+1);
    for (int i=0; i<n; i++) {
        f[a[i]] = min(f[a[i]], a[i]-b[i]);
    }
    for (int i=1; i<=mx; i++) {
        f[i] = min(f[i], f[i-1]);
    }
    for (int i=1; i<=mx; i++) {
        if (i>=f[i])
        v[i] = v[i-f[i]]+2;
    }
    // cout << a << b << c << f << v << endl;
    ll ans = 0;
    for (int i:c) {
        if (i > mx) {
            // i - k*f[mx] <= mx
            // ceil( (i-mx)/f[mx] ) <=k
            ll k = (i-mx+f[mx]-1)/f[mx];
            ans += 2*k;
            i -= k*f[mx];
        }
        ans += v[i];
    }
    cout << ans << '\n';
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