#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 1005
#define M 998244353
using namespace std;

ll fpow(ll x, ll p, ll m) {
	ll rt = 1;
	while (p) {
		if (p&1) rt = rt*x%m;
		x = x*x%m;
		p >>= 1;
	}
	return rt;
}
// fpow(x, p-2, p); // inv(x)
int n, m, k;

ll dp[N][N];

void sol() {
	cin >> n >> m >> k;
	// for (int i=0; i<=n; i++) {
	// 	for (int j=0; j<=k; j++) {
	// 		dp[i][j] = {1, 0};
	// 	}
	// }
	ll invm = fpow(m, M-2, M);
	dp[0][0] = 1;
	for (int j=0; j<k; j++) {
		for (int i=0; i<n; i++) {
			for (int c=1; c<=m; c++) {
				dp[i+c<=n?i+c:n-(i+c-n)][j+1] = (dp[i+c<=n?i+c:n-(i+c-n)][j+1] + dp[i][j]*invm%M)%M;
			}
		}
	}
	ll prob = 0;
	for (int i=0; i<=k; i++) {
		prob += dp[n][i];
		prob %= M;
	}
	cout << prob << endl;
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