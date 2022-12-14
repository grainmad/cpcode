#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998224353
using namespace std;

ll dp[6][N];
ll a[N];

void sol() {
	ll n, h;
	cin >> n >> h;
	for (int i=0; i<=n; i++) {
		for (int j=0; j<6; j++) dp[j][i] = 0;
	}
	dp[0][0] = h;
	dp[1][0] = 2*h;
	dp[2][0] = 4*h;
	dp[3][0] = 3*h;
	dp[4][0] = 6*h;
	dp[5][0] = 12*h;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for (int i=1; i<=n; i++) {
		if (dp[0][i-1] > a[i]) dp[0][i] = max(dp[0][i], dp[0][i-1]+a[i]/2);
		if (dp[0][i-1]*2 > a[i]) dp[1][i] = max(dp[1][i], 2*dp[0][i-1]+a[i]/2);
		if (dp[0][i-1]*4 > a[i]) dp[2][i] = max(dp[2][i], 4*dp[0][i-1]+a[i]/2);
		if (dp[0][i-1]*3 > a[i]) dp[3][i] = max(dp[3][i], 3*dp[0][i-1]+a[i]/2);
		if (dp[0][i-1]*6 > a[i]) dp[4][i] = max(dp[4][i], 6*dp[0][i-1]+a[i]/2);
		if (dp[0][i-1]*12 > a[i]) dp[5][i] = max(dp[5][i], 12*dp[0][i-1]+a[i]/2);
		

		if (dp[1][i-1] > a[i]) dp[1][i] = max(dp[1][i], dp[1][i-1]+a[i]/2);
		if (dp[1][i-1]*2 > a[i]) dp[2][i] = max(dp[2][i], 2*dp[1][i-1]+a[i]/2);
		if (dp[1][i-1]*3 > a[i]) dp[4][i] = max(dp[4][i], 3*dp[1][i-1]+a[i]/2);
		if (dp[1][i-1]*6 > a[i]) dp[5][i] = max(dp[5][i], 6*dp[1][i-1]+a[i]/2);
		

		if (dp[2][i-1] > a[i]) dp[2][i] = max(dp[2][i], dp[2][i-1]+a[i]/2);
		if (dp[2][i-1]*3 > a[i]) dp[5][i] = max(dp[5][i], 3*dp[2][i-1]+a[i]/2);
		

		if (dp[3][i-1] > a[i]) dp[3][i] = max(dp[3][i], dp[3][i-1]+a[i]/2);
		if (dp[3][i-1]*2 > a[i]) dp[4][i] = max(dp[4][i], 2*dp[3][i-1]+a[i]/2);
		if (dp[3][i-1]*4 > a[i]) dp[5][i] = max(dp[5][i], 4*dp[3][i-1]+a[i]/2);
		

		if (dp[4][i-1] > a[i]) dp[4][i] = max(dp[4][i], dp[4][i-1]+a[i]/2);
		if (dp[4][i-1]*2 > a[i]) dp[5][i] = max(dp[5][i], 2*dp[4][i-1]+a[i]/2);
		

		if (dp[5][i-1] > a[i]) dp[5][i] = max(dp[5][i], dp[5][i-1]+a[i]/2);
		
	}
	int mx = 0;
	for (int i=1; i<=n; i++) {
		for (int j=0; j<6; j++) {
			if (dp[j][i] != 0) {
				mx = max(mx, i);
			}
		}
	}
	cout << mx << endl;
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