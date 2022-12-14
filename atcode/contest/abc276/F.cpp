#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 200005
#define M 998244353
using namespace std;

ll BIT[2][N];
// ll xBIT[N];

void bit_add(int x, ll val, int p) {
    for (int i=x; i<N; i+=i&-i) {
        BIT[p][i] += val;       
        // xBIT[i] += x*val;
        // 区间查询时 BIT[i] += val; xBIT[i] += x*val;
        BIT[p][i] %= M;
    }
}

ll bit_ps(int x, int p) {
    ll rt = 0;
    for (int i=x; i>0; i-=i&-i) {
        rt += BIT[p][i];
        // rt += x*BIT[i]-xBIT[i];
        // 区间查询时 rt += (x+1)*BIT[i]-xBIT[i];
        rt %= M;
    }
    return rt;
}


ll a[N];

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
	int n; cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	// sort(a, a+n);
	ll sum = 0, pre = 0;
	for (int i=0; i<n; i++) {
		pre += a[i];
		bit_add(a[i], 1, 0);
		bit_add(a[i], a[i], 1);
		ll u = pre - bit_ps(a[i], 1);
		sum += (u*2%M+M)%M + ((bit_ps(a[i], 0)*2LL-1)*a[i]%M+M)%M;
		sum %= M;
		cout << sum*fpow((i+1LL)*(i+1LL)%M, M-2, M)%M << endl;
	}
}

int main() {
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