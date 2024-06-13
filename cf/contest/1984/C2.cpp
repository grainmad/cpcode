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

void sol() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& i:a) cin >> i;
    ll mn = 0;
    vector<ll> ps(1, 0);
    for (int i=0; i<n; i++) {
        ps.push_back(ps.back()+a[i]);
        mn = min(mn, ps.back());
    }
    // cout << ps << endl;
    if (mn == 0) {
        cout << fpow(2, n) << "\n";
        return ;
    }
    ll ans = 0, pos = 0;
    for (int i=0; i<n+1; i++) {
        if (ps[i] >= 0) pos++;
        if (ps[i] == mn) {
            ans += fpow(2, pos+n-i);
            ans %= MOD;
        }
    }
    cout << ans*fpow(2, MOD-2)%MOD << "\n";
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