#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 5005
using namespace std;

vector<int> g[N];
string s;
int ans = 0;

pair<int,int> dfs(int u) {
	pair<int,int> rt = {0, 0};
	if (s[u-1] == 'W') rt.first++;
	else rt.second++;
	for (int i:g[u]) {
		auto r = dfs(i);
		rt.first += r.first;
		rt.second += r.second;
	}
	if (rt.first == rt.second && rt.first != 0) ans++;
	// cout << u << " " << rt.first << " " << rt.second << endl;
	return rt;
}

void sol() {
	ans = 0;
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		g[i].clear();
	}
	for (int i=2; i<=n; i++) {
		int x;
		cin >> x;
		g[x].push_back(i);
	}
	cin >> s;
	auto r = dfs(1);
	
	cout << ans << endl;
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