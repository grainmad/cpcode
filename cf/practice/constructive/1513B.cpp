#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 200005
using namespace std;
ll M = 1e9+7;
ll a[N];

void sol() {
	int n;
	cin >> n;
	ll m = 0;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<31; i++) {
		ll c = 1;
		for (int j=0; j<n; j++) {
			c &= a[j]>>i&1;
		}
		if (c) m += 1LL<<i;
	}
	// cout << m << endl;
	ll av = count(a, a+n, m);
	if (av < 2) {
		cout << "0" << endl;
		return ;
	}
	ll ans = av*(av-1)%M;
	for (int i=1; i<=n-2; i++) {
		ans*=i;
		ans%=M;
	}
	cout << ans << endl;
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