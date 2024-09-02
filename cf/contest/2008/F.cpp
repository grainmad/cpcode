#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005

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

const ll MOD = 1e9+7;

ll fpow(ll u, ll p) {
    ll rt = 1;
    while (p) {
        if (p&1) rt = rt*u%MOD;
        u = u*u%MOD;
        p >>= 1;
    }
    return rt;
}

void sol() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& i:a) cin >> i;
    ll d = fpow(n*(n-1)/2%MOD, MOD-2);
    ll u = 0;
    ll ps = 0;
    for (int i=0; i<n; i++) {
        u += ps*a[i]%MOD;
        u %= MOD;
        ps += a[i];
        ps %= MOD;
    }
    cout << u*d%MOD << "\n";
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