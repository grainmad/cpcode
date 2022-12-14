#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
using namespace std;

int D[N], X[N], vis[N];

void sol() {
	set<pair<int,int>> st;
	queue<int> que;
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> D[i] >> X[i];
		if (D[i] == 1) {
			que.push(i);
			vis[i] = 1;
		}
	}
	while (!que.empty()) {
		int u = que.front(); que.pop();
		if (st.count({X[u], u}) == 0) {
			st.insert({u, X[u]});
		}
		if (D[X[u]] > 1) {
			X[X[u]] ^= u;
			D[X[u]]--;
		}
		if (D[X[u]] == 1) {
			if (vis[X[u]]) continue;
			vis[X[u]] = 1;
			que.push(X[u]);
		}
	}
	cout << st.size() << "\n";
	for (auto& i:st) {
		cout << i.first << " " << i.second << "\n";
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