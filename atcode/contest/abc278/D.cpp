#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998224353
using namespace std;

ll n, q;
ll a[N];
ll v[N];
ll val, u;

void sol() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		v[i] = 0;
	}
	val = u = -1;
	cin >> q;
	for (int i=1; i<=q; i++) {
		ll opt; cin >> opt;
		if (opt == 1) {
			int x; cin >> val;
			u = i;
		}
		if (opt == 2) {
			ll idx, x; cin >> idx >> x;
			if (v[idx] < u) a[idx] = val;
			a[idx] += x;
			v[idx] = i;
		}
		if (opt == 3) {
			ll idx; cin >> idx;
			if (v[idx] < u) a[idx] = val;
			cout << a[idx] << "\n";
			v[idx] = i;
		}
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