#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 200005
#define MOD 998224353
using namespace std;

vector<int> g[2][N];



void sol() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i=0; i<m; i++) {
		int x, y, a;
		cin >> x >> y >> a;
		g[a][x].push_back(y);
		g[a][y].push_back(x);
	}
	vector<int> sw(n+1, 0);
	for (int i=0; i<k; i++) {
		int x; cin >> x;
		sw[x] = 1;
	}
	queue<pair<int,int>> que;
	que.emplace(1, 1);
	set<pair<int,int>> st;
	st.insert({1,1});
	int stp = 0;
	while (que.size()) {
		int sz = que.size();
		for (int i=0; i<sz; i++) {
			auto [p, l] = que.front(); que.pop();
			if (p == n) {
				cout << stp << endl;
				return ;
			}
			for (int u:g[l][p]) {
				if (st.count({u, l})) continue;
				st.insert({u, l});
				que.emplace(u, l);
			}
			if (sw[p])
			for (int u:g[1-l][p]) {
				if (st.count({u, 1-l})) continue;
				st.insert({u, 1-l});
				que.emplace(u, 1-l);
			}
		}
		stp++;
	}
	cout << "-1" << endl;
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