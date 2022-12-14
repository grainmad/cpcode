#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 200005
using namespace std;

int a[N], dp[N];

void sol() {
	int n; cin >> n;
	ll ans = 1;
	for (int i=0; i<n; i++) cin >> a[i];
	dp[0] = 1;
	for (int i=1; i<n; i++) {
		dp[i] = min(dp[i-1]+1, a[i]);
		ans += dp[i];
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