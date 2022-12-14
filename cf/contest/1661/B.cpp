#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


ll lowpos(ll num) {
	ll rt = 0;
	while ((num&1) == 0) {
		num >>= 1;
		rt++;
	}
	return rt;
}

ll lowbit(ll x) {
	return x&-x;
}

void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		ll x;
		ll add = 0;
		cin >> x;
		if (x == 0) {
			cout << "0 ";
			continue;
		}
		ll ans = N;
		while (x <= (1<<15)) {
			ans = min(15-lowpos(x)+add, ans);
			ll lb = lowbit(x);
			add += lb;
			x = x+lb;
		}
		cout << ans << " ";
	}
	cout << endl;
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