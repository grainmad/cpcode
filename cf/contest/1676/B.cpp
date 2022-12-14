#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 55
using namespace std;

ll a[N];

void sol() {
	int n; cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	int mn = *min_element(a, a+n);
	ll ans = 0;
	for (int i=0; i<n; i++) {
		ans += a[i] - mn;
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