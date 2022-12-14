#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n, q;
	cin >> n >> q;
	std::vector<ll> a(n);
	for (int i=0; i<n; i++) cin >> a[i];
	sort(a.rbegin(), a.rend());
	for (int i=1; i<n; i++) {
		a[i] += a[i-1];
	}
	for (int i=0; i<q; i++) {
		ll x;
		cin >> x;
		int p = lower_bound(a.begin(), a.end(), x) - a.begin();
		if (p == n) cout << "-1" << endl;
		else cout << p+1 << endl;
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