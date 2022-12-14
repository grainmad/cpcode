#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

ll a[N];
string s;
ll pa[N], pb[N];

void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	cin >> s;
	for (int i=0; i<n; i++) {
		if (s[i] == 'A') {
			pa[i+1] += pa[i]+a[i];
			pb[i+1] = pb[i];
		} else {
			pa[i+1] = pa[i];
			pb[i+1] += pb[i]+a[i];
		}
	}
	// for (int i=0; i<=n; i++) {
	// 	cout << pa[i] << " ";
	// } cout << endl;
	// for (int i=0; i<=n; i++) {
	// 	cout << pb[i] << " ";
	// } cout << endl;
	ll ans = 0;
	for (int i=0; i<=n; i++) {
		ans = max(ans, pa[i]+pb[n]-pb[i]);
		ans = max(ans, pa[n]-pa[i]+pb[i]);
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