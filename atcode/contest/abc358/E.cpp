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

ll fac[N], inv_fac[N];
ll fpow(ll x, ll p, ll m) {
	ll rt = 1;
	while (p) {
		if (p&1) rt *= x, rt %= m;
		x *= x; x %= m;
		p >>= 1;
	}
	return rt;
}
void pre() {
    fac[0] = 1;
    for (int i=1; i<N; i++) {
        fac[i] = fac[i-1]*i%MOD;
    }
    inv_fac[N-1] = fpow(fac[N-1], MOD-2, MOD);
    for (int i=N-2; i>=0; i--) {
        inv_fac[i] = inv_fac[i+1]*(i+1)%MOD;
    }
}
// O(1)
int comb(int n, int m) {
	return fac[n]*inv_fac[m]%MOD*inv_fac[n-m]%MOD;
}


void sol() {
    ll k;
    cin >> k;
    vector<ll> a(27);
    for (int i=1; i<=26; i++) cin >> a[i];
    vector f(27, vector<ll>(k+1, 0));
    f[0][0] = 1;
    for (int i=1; i<=26; i++) {
        for (int j=0; j<=k; j++) {
            for (int c=max(0LL, j-a[i]); c<=j; c++) {
                f[i][j] += f[i-1][c]*comb(j, c)%MOD;
                f[i][j] %= MOD;
            }
        }
    }
    ll ans = 0;
    for (int i=1; i<=k; i++) {
        ans += f[26][i];
        ans %= MOD;
    }
    cout << ans << "\n";
    
}

int main() {
    pre();
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