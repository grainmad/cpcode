#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 505
using namespace std;

ll MOD = 1e9+7;
ll dp[N], cnt[N];
int ok[N];

void sol() {
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	for (int i=0; i<=n; i++) {
		cnt[i] = dp[i] = ok[i] = 0;
	}
	for (int i=0; i<n-m+1; i++) {
		bool yes = true;
		for (int j=0; j<m; j++) {
			if (s[i+j] != t[j]) yes = false;
		}
		if (yes) ok[i+m-1] = 1;
	}
	// for (int i=0; i<n; i++) {
	// 	cout << ok[i] << " ";
	// } cout << endl;
	cnt[0] = 1;
	for (int i=1; i<=n; i++) {
		if (ok[i-1]) {
			dp[i] = (dp[i-m]+1)%MOD; cnt[i] = cnt[i-m];
			for (int j=i-m+1; j<i; j++) {
				if (ok[j-1]) {
					if (dp[j-m]+1 == dp[i]) cnt[i] = (cnt[i]+cnt[j-m])%MOD;
					else if (dp[j-m]+1 < dp[i]) dp[i] = (dp[j-m]+1)%MOD, cnt[i] = cnt[j-m];
				}
			}
		} else {
			dp[i] = dp[i-1]; 
			cnt[i] = cnt[i-1];
		}
	}
	// for (int i=1; i<=n; i++) {
	// 	cout << dp[i] << " ";
	// } cout << endl;
	// for (int i=1; i<=n; i++) {
	// 	cout << cnt[i] << " ";
	// } cout << endl;
	cout << dp[n] << " " << cnt[n] << "\n";
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