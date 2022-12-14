#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
	ll n, c, d;
	cin >> n >> c >> d;
	std::vector<ll> a(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	if (a[0]*d < c) {
		cout << "Impossible\n";
		return ;
	}
	if (accumulate(a.begin(), a.begin()+min(n,d), 0LL) >= c) {
		cout << "Infinity\n";
		return ;
	}
	ll l = 0, r = 1e18;
	while (l < r) {
		ll m = (r-l)/2+l;
		ll co = 0, ok = 0;
		for (int i=0; i<d; i++) {
			if (i%(m+1) < n) co += a[i%(m+1)];
			if (co>=c) {
				ok = 1;
				break;
			}
		}
		if (ok) {
			l = m+1;
		} else {
			r = m;
		}
	}
	cout << r-1 << "\n";
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