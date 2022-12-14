#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 505
using namespace std;

int dp[N][6005];
int v[N], w[N], s[N];

void sol() {
	int n, m;
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> v[i] >> w[i] >> s[i];
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			for (int k=0; k<=s[i]; k++) {
				if (k*v[i]<=j)
				dp[i][j] = max(dp[i][j], dp[i-1][j-k*v[i]]+k*w[i]);
			}
		}
	}
	cout << dp[n][m] << endl;
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