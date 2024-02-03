#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 1000000007
using namespace std;


ll fpow(ll x, ll p, ll m) {
	ll rt = 1;
	while (p) {
		if (p&1) rt *= x, rt %= m;
		x *= x; x %= m;
		p >>= 1;
	}
	return rt;
}
// fpow(x, p-2, p); // inv(x)

void sol() {
    ll n, m, k, f = 0;
    cin >> n >> m >> k;
    for (int i=0; i<m; i++) {
        ll a, b, x;
        cin >> a >> b >> x;
        f += x;
        f %= MOD;
    }
    ll d = fpow(n*(n-1)/2%MOD, MOD-2, MOD);
    ll p = d*m%MOD;
    ll ans = 0;
    for (int i=0; i<k; i++) {
        ans += f*d%MOD;
        ans %= MOD;
        f += p;
        f %= MOD;
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