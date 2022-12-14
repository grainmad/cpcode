#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 3005
#define INF 0x3f3f3f3f
using namespace std;

// dp[i][j] 前i个选出和为j的最少步数
int dp[N][N];// dp[i][j] = min(dp[0...i-1][j]+1, dp[i-1][j-A[i]]);
int p[N][N]; // p[i][j] = dp[0...i][j]
int a[N];

void sol() {
	int n, m;
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	memset(dp, 0x3f, sizeof(dp));
	memset(p, 0x3f, sizeof(p));
	dp[0][0] = 0;
	p[0][0] = 0;
	for (int i=1; i<=n; i++) {
		for (int j=0; j<=m; j++) {
			if (j>=a[i]) dp[i][j] = min(dp[i][j], dp[i-1][j-a[i]]);
			dp[i][j] = min(dp[i][j], p[i-1][j]+1);
			p[i][j] = min(p[i-1][j], dp[i][j]);
		}
	}
	for (int i=1; i<=m; i++) {
		cout << (dp[n][i]==INF?-1:dp[n][i]) << "\n";
	}
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