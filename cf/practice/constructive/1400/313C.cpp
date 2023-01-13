#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n;
	cin >> n;
	std::vector<ll> v(n, 0);
	for (int i=0; i<n; i++) {
		cin >> v[i];
	}
	sort(v.rbegin(), v.rend());
	for (int i=1; i<n; i++) {
		v[i] += v[i-1];
	}
	int u = 1;
	ll ans = 0;
	while (u<=n) {
		ans += v[u-1];
		u <<= 2;
	}
	cout << ans << "\n";
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