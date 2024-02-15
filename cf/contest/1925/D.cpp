#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 1000000007
using namespace std;

// solution 1
// ll fpow(ll x, ll p, ll m) {
// 	ll rt = 1;
// 	while (p) {
// 		if (p&1) rt *= x, rt %= m;
// 		x *= x; x %= m;
// 		p >>= 1;
// 	}
// 	return rt;
// }
// // fpow(x, p-2, p); // inv(x)

// void sol() {
//     ll n, m, k, f = 0;
//     cin >> n >> m >> k;
//     for (int i=0; i<m; i++) {
//         ll a, b, x;
//         cin >> a >> b >> x;
//         f += x;
//         f %= MOD;
//     }
//     ll d = fpow(n*(n-1)/2%MOD, MOD-2, MOD);
//     ll p = d*m%MOD;
//     ll ans = 0;
//     for (int i=0; i<k; i++) {
//         ans += f*d%MOD;
//         ans %= MOD;
//         f += p;
//         f %= MOD;
//     }
//     cout << ans << "\n";
// }

// solution 2

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


// O(mk)超时
// void sol() {
//     ll n, m, k;
//     cin >> n >> m >> k;
//     vector<ll> fi(m);
//     for (int i=0; i<m; i++) {
//         ll a, b, x;
//         cin >> a >> b >> x;
//         fi[i] = x;
//     }
//     ll d = n*(n-1)/2%MOD;
//     ll id = fpow(d, MOD-2, MOD);
//     ll dk = fpow(d, k, MOD);
//     ll idk = fpow(dk, MOD-2, MOD);
//     // 超时
//     for (int i=0; i<m; i++) {
//         for (int j=0; j<=k; j++) {
//             ll ctr = (j-1)*j/2%MOD;
//             ctr = (ctr + j*fi[i]%MOD) %MOD;
//             u += comb(k, j)*fpow(d-1, k-j, MOD)%MOD*ctr%MOD;
//             u %= MOD;
//         }
//     }
//     cout << (u*idk%MOD) << "\n";
// }

void sol() {
    ll n, m, k, f = 0;
    cin >> n >> m >> k;
    for (int i=0; i<m; i++) {
        ll a, b, x;
        cin >> a >> b >> x;
        f = (f + x) % MOD;
    }
    ll d = n*(n-1)/2%MOD;
    ll id = fpow(d, MOD-2, MOD);
    ll dk = fpow(d, k, MOD);
    ll idk = fpow(dk, MOD-2, MOD);
    ll u = 0;
    for (int j=0; j<=k; j++) {
        ll ctr = (j-1LL)*j/2%MOD;
        ctr = ctr*m%MOD;
        ctr = (ctr + j*f%MOD) %MOD;
        u += comb(k, j)*fpow(d-1, k-j, MOD)%MOD*ctr%MOD;
        u %= MOD;
    }
    cout << u*idk%MOD << "\n";
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