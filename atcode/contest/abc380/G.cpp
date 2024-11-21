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

ll fpow(ll x, ll p) {
    ll rt = 1;
    while (p) {
        if (p&1) rt = rt*x%MOD;
        p >>= 1;
        x = x*x%MOD;
    }
    return rt;
}

void sol() {
    ll n, k;
    cin >> n >> k;
    ll sz = n+5;
    vector<ll> a(n), BIT(sz);
    for (auto& i:a) cin >> i;
    auto add = [&](int x, int val) {
        for (int i=x; i<sz; i+=i&-i) {
            BIT[i]+=val;
        }
    };
    auto ask = [&](int x) {
        ll rt = 0;
        for (int i=x; i; i&=(i-1)) {
            rt += BIT[i];
        }
        return rt;
    };
    ll s = 0;
    for (int i=0; i<n; i++) {
        s += ask(sz-1) - ask(a[i]-1);
        add(a[i], 1);
    }
    for (int i=0; i<sz; i++) BIT[i] = 0;
    ll ans = 0;
    ll now = 0;
    ll kinv = k*(k-1)%MOD*fpow(4, MOD-2)%MOD;
    for (int i=0; i<k; i++) {
        now += ask(sz-1) - ask(a[i]-1);
        add(a[i], 1);
    }
    ans = s - now + kinv;
    for (int i=k; i<n; i++) {
        add(a[i-k], -1);
        now -= ask(a[i-k]);
        now += ask(sz-1) - ask(a[i]);
        add(a[i], 1);
        ans += s - now + kinv;
        ans = (ans%MOD+MOD)%MOD;
    }
    cout << ans*fpow(n-k+1, MOD-2)%MOD << "\n";
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
