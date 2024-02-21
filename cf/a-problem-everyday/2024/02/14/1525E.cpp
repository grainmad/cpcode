
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
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

#define N 100005
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
int comb(int n, int m) {
	return fac[n]*inv_fac[m]%MOD*inv_fac[n-m]%MOD;
}

void sol() {
    pre();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (auto& i:g) {
        for (auto& j:i) {
            cin >> j;
        }
    }
    ll ans = 0;
    for (int i=0; i<m; i++) {
        vector<int> d(n+2);
        for (int j=0; j<n; j++) {
            d[g[j][i]-1]++;
        }
        // cout << d << endl;
        for (int j=n; j>=0; j--) {
            d[j] += d[j+1];
        }
        // cout << d << endl;
        ll sub = 1;
        for (int j=n; j>0; j--) {
            sub *= d[j]-n+j;
            sub %= MOD;
        }
        ans += ((fac[n]-sub)%MOD+MOD)%MOD;
        ans %= MOD;
    }
    cout << ans*inv_fac[n]%MOD << endl;
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
