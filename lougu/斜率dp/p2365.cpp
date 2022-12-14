#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define N 500005
using namespace std;


void sol() {
	int n, s;
	cin >> n >> s;
	std::vector<ll> t(n+1), f(n+1), dp(n+1, INF);
	for (int i=1; i<=n; i++) {
		int x, y;
		cin >> x >> y;
		t[i] = t[i-1] + x;
		f[i] = f[i-1] + y;
	}
	dp[0] = 0;
	for (int i=1; i<=n; i++) {
		for (int j=0; j<i; j++) {
			dp[i] = min(dp[i], dp[j]+t[i]*(f[i]-f[j])+s*(f[n]-f[j]));
		}
	}
	cout << dp[n] << "\n";
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