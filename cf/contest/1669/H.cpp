#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	std::vector<int> v(31, 0);
	int n, k;
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		ll x;
		cin >> x;
		for (int i=0; i<31; i++) {
			if ((x>>i)&1) {
				v[i]++;
				// cout << i << " ";
			}
		}
		// cout << endl;
	}
	for (int i=30; i>=0; i--) {
		if (k >= n-v[i]) {
			k -= n-v[i];
			v[i] = n;
		}
	}
	ll ans = 0;
	for (int i=0; i<31; i++) {
		// cout << v[i] << " ";
		if (v[i] == n) {
			ans |= 1<<i;
		}
	}
	// cout << endl;
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