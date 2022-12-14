#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 200005
using namespace std;

struct Node {
	int to, x, y;
};

int n;
std::vector<Node> v[N];
pair<int,int> r[N];
void bfs() {
	std::vector<bool> vis(n+1, false);
	vis[1] = true;
	queue<int> que;
	que.push(1);
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (auto i:v[u]) {
			if (vis[i.to]) continue;
			vis[i.to] = true;
			r[i.to] = {r[u].}
		}
	}

}

void sol() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		v[i].clear();
	}
	for (int i=1; i<=n; i++) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		v[a].push_back({b, x, y});
		v[b].push_back({a, y, x});
	}
	fa[1] = -1;
	getfa(1);
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