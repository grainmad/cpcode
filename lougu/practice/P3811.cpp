#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 3000005
using namespace std;

ll inv[N];

ll fpow(ll x, ll p, ll m) {
	ll rt = 1;
	while (p) {
		if (p&1) rt *= x, rt %= m;
		x *= x; x %= m;
		p >>= 1;
	}
	return rt;
}

void sol1() {
	ll n, p;
	cin >> n >> p;
	for (int i=1; i<=n; i++) {
		cout << fpow(i, p-2, p) << "\n";
	}
}

void sol2() {
	ll n, p; cin >> n >> p;
	inv[1] = 1;
	for (int i=2; i<=n; i++) {
			inv[i] = (p-p/i)*inv[p%i]%p;
	}
	for (int i=1; i<=n; i++) {
		cout << inv[i] << "\n";
	}
}

void sol() {
	sol2();
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