#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 505
#define MOD 998244353
using namespace std;

ll dp[N];

void sol() {
	int n, k;
	cin >> n >> k;
	dp[2] = k;
	for (int i=3; i<=n; i++) {
		for (int j=1; j<=k; j++) {
			dp[i] = (dp[i] + (dp[i-1]*(i-2)*(k-j+1))%MOD)%MOD;
		}
	}
	cout << dp[n] << endl;
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