#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
using namespace std;

vector<int> g[N];
int vis[N];
int deg[N];
int ans[N];

void sol() {
	int n;
	cin >> n;
	std::vector<pair<int,int>> v(n+1);
	map<pair<int,int>, int> mp;
	for (int i=1; i<=n-1; i++) {
		int x, y;
		cin >> x >> y;
		v[i] = {x, y};
		g[x].push_back(y);
		g[y].push_back(x);
		deg[x]++;
		deg[y]++;
		mp[{x,y}] = mp[{y,x}] = i;
	}
	if (n==2) {
		cout << "0\n";
		return ;
	}
	int start = 0, p = 0;
	for (int i=1; i<=n; i++) {
		if (deg[i] == 1) {
			if (start == 0) start = i;
			ans[mp[{g[i][0], i}]] = p++;
			vis[i] = 1;
		}
	}
	int k = n-1;
	queue<int> que;
	que.push(start);
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (int i:g[u]) {
			if (vis[i]) continue;
			vis[i] = 1;
			ans[mp[{u,i}]] = k%(n-1);
			k--;
			que.push(i);
		}
	}
	for (int i=1; i<=n-1; i++) {
		cout << ans[mp[v[i]]] << "\n";
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