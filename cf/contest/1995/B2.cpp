#include <bits/stdc++.h>
// #define SINGLE_INPUT
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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), c(n), idx(n);
    for (auto& i:a) cin >> i;
    for (auto& i:c) cin >> i;
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int x, int y) {
        return a[x] < a[y];
    });
    // cout << a << endl;
    // cout << c << endl;
    // cout << idx << endl;
    ll ans = 0;
    for (int i=0; i<n; i++) {
        if (i+1<n && a[idx[i]] + 1 == a[idx[i+1]]) {
            ll x = a[idx[i]], cx = c[idx[i]];
            ll y = a[idx[i+1]], cy = c[idx[i+1]];
            ll k1 = min(m/x, cx)*x;
            ll k2 = min((m-k1)/y, cy)*y;
            ll r = m - k1 - k2;
            // 多余的y个数 cy - min((m-k1)/y, cy) 替换x
            // x使用的个数 min(m/x, cx)
            ans = max(ans, k1+k2 + min({min(m/x, cx), cy - min((m-k1)/y, cy), r}));

        } else {
            ll x = a[idx[i]], cx = c[idx[i]];
            ans = max(ans, min(cx, m/x)*x);
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