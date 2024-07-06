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

ll BIT[N];

ll ask(int x) {
    ll rt = 0;
    for (int i=x; i; i&=(i-1)) {
        rt += BIT[i];
    }
    return rt;
}

void add(int x, ll val) {
    for (int i=x; i<N; i+=i&-i) {
        BIT[i] += val;
    }
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

ll fac[N], inv[N];

void init() {
    fac[0] = 1;
    for (int i=1; i<N; i++) {
        fac[i] = fac[i-1]*i%MOD;
    }
    inv[N-1] = fpow(fac[N-1], MOD-2);
    for (int i=N-2; i>=0; i--) {
        inv[i] = inv[i+1]*(i+1)%MOD;
    }
}

void sol() {
    init();
    int n, m;
    cin >> n >> m;
    map<int,int> mp;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        mp[x]++;
        add(x, 1);
    }
    int tot = n;
    ll cur = fac[tot];
    for (auto& [i,j]:mp) cur = (cur*inv[j])%MOD;
    vector<int> t(m);
    for(auto& i:t) cin >> i;
    ll ans = 0;
    for (int x:t) {
        ans = (ans + cur*ask(x-1)%MOD*inv[tot]%MOD*fac[tot-1]%MOD)%MOD;
        if (mp.count(x) == 0) break;
        cur *= inv[tot]; cur %= MOD;
        cur *= fac[tot-1]; cur %= MOD;
        cur *= fac[mp[x]]; cur %= MOD;
        cur *= inv[mp[x]-1]; cur %= MOD;
        tot--;
        if (--mp[x] == 0) mp.erase(x);
        add(x, -1);
    }
    if (n < m && mp.empty()) ans = (ans+1)%MOD;
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