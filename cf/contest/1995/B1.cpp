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
    vector<ll> a(n);
    map<ll,ll> mp;
    for (int i=0; i<n; i++) {
        ll x;
        cin >> x;
        mp[x]++;
    }
    vector<pair<ll,ll>> p(mp.begin(), mp.end());
    // cout << p << endl;
    int sz = p.size();
    ll ans = 0;
    for (int i=0; i<sz; i++) {
        if (i+1<sz && p[i].first+1 == p[i+1].first) {
            auto [x, cx] = p[i];
            auto [y, cy] = p[i+1];
            // x*j+y*k <= m j<=cx k<=cy
            for (ll j=0; j<=cx&&j*x<=m; j++) {
                ll k = (m-j*x)/y;
                ans = max(ans, x*j+y*min(k, cy));
            }

        } else {
            auto [x, cx] = p[i];
            ans = max(ans, min(m/x, cx)*x);
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