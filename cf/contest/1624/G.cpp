//G
#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;
int inf = 1e9;
struct Node {
	int u, w;
};
vector<Node> mp[MAXN];
bool vis[MAXN];
int n, m;
int mask;


void dfs(int v) {
	vis[v] = true;
	for (int i=0; i<mp[v].size(); i++) {
		int u = mp[v][i].u, w = mp[v][i].w;
		if (!vis[u] && (mask|w) == mask) dfs(u);
	}
}

void lev(int t) {
	int b = 1<<t;
	mask -= b;
	memset(vis, 0, sizeof(vis));
	dfs(0);
	for (int i=0; i<n; i++) if (!vis[i]) {
		mask += b;
		break;
	}
//	cout << mask << endl;
	if (t>0) lev(t-1);
}

void sol() {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		mp[i].clear();
	}
	int u, v, w;
	for (int i=0; i<m; i++) {
		cin >> u >> v >> w;
		mp[u-1].push_back({v-1, w});
		mp[v-1].push_back({u-1, w});
	}
	mask = 0;
	int cnt = 0;
	while (mask < inf) {
		mask = mask*2+1;
		cnt++;
	}
//	cout << cnt << endl;
	lev(cnt-1);
	cout << mask << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		sol();
	} 
	return 0;
} 
