#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

ll a[N];

void sol() {
	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i=1; i<=n; i++) {
		// for (int j=i+1; j<=n; j++) {
		// 	if (a[j] <= a[i]) ans++;
		// }
		for (int j=i-1; j>=0; j--) {
			if (a[j] >= a[i]) ans++;
		}
	}
	// cout << ans/2 << endl;
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