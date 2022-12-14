#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 200005
using namespace std;

int b[N], dp[N];

void sol() {
	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> b[i];
		dp[i] = 0;
	}
	dp[0] = 1;
	for (int i=0; i<=n; i++) {
		if (i-b[i]-1>=0 && dp[i-b[i]-1]) {
			dp[i] = 1;
		}
		if (dp[i] && i+1<=n && i+b[i+1]+1<=n) {
			dp[i+b[i+1]+1] = 1;
		}
	}
	// for (int i=0; i<=n; i++) cout << dp[i] << " ";
	cout << (dp[n]?"YES\n":"NO\n");
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