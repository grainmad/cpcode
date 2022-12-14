#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
using namespace std;

int len[N], dp[N];
vector<int> g[N];

void dfs(int x) {
	for (int i:g[x]) {
		dfs(i);
		dp[x] += dp[i];
		len[x] = max(len[x], len[i]);
	}
	len[x]++;
	dp[x] = max(dp[x], len[x]);
}

void sol() {
	int n; cin >> n;
	for (int i=2; i<=n; i++) {
		int x; cin >> x;
		g[x].push_back(i);
	}
	dfs(1);
	cout << dp[1] << endl;
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