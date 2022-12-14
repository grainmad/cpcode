#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n, m;
	cin >> n >> m;
	map<int,set<int>> mp;
	for (int i=1; i<=n; i++) mp[i];
	for (int i=0; i<m; i++) {
		int x, y; cin >> x >> y;
		mp[x].insert(y);
		mp[y].insert(x);
	}
	for (auto& [i, j]:mp) {
		cout << j.size();
		for (int k:j) {
			cout << " " << k;
		}
		cout << endl;
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