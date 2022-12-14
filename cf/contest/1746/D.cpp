#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 200005
using namespace std;


vector<int> g[N];
vector<pair<int,ll>> ans[N];
ll s[N];

ll dfs(int x, int k) { 
	// if (k == 0) return 0;
	for (auto [i,j]:ans[x]) {
		if (i == k) return j;
	}
	ll res = k*s[x];
	int sz = g[x].size();
	if (sz == 0) {
		ans[x].emplace_back(k, res);
		return res;
	}
	if (k%sz == 0) {
		for (int i:g[x]) {
			res += dfs(i, k/sz);		
		}
	} else {
		ll dp1[sz], dp2[sz], dif[sz];
		for (int i=0; i<sz; i++) {
			dp1[i] = dfs(g[x][i], k/sz);
			dp2[i] = dfs(g[x][i], k/sz+1);
			dif[i] = dp2[i]-dp1[i];
		}
		sort(dif, dif+sz, greater<ll>());
		for (int i=0; i<sz; i++) {
			res += dp1[i];
			if (i<k%sz) res += dif[i];
		}
	}
	ans[x].emplace_back(k, res);
	return res;
}

void sol() {
	int n, k;
	cin >> n >> k;
	for (int i=0; i<=n; i++) g[i].clear(), ans[i].clear();
	for (int i=2; i<=n; i++) {
		int x; cin >> x;
		g[x].push_back(i);
	}
	for (int i=1; i<=n; i++) cin >> s[i];
	cout << dfs(1, k) << "\n";
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
