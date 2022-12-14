#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int dp[N];

void sol() {
	string s;
	unordered_map<char,int> mp;
	cin >> s;
	int n = s.size();
	s = '0'+s;
	for (int i=1; i<=n; i++) {
		if (mp.count(s[i]) == 0) dp[i] = dp[i-1]+1;
		else {
			dp[i] = min(dp[i-1]+1, dp[mp[s[i]]-1]+i-mp[s[i]]-1);
		}
		mp[s[i]] = i;
	}
	// for (int i=1; i<=n; i++) {
	// 	cout << dp[i] << " ";
	// } cout << endl;
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