//C
#include <bits/stdc++.h>
#define ll long long
#define P pair<int, int>
#define f first
#define s second
#define MAXN 200005
using namespace std;


//一个顶点所连接的边不超过2，度不超过2
int deg[MAXN];
int edge[MAXN];
std::vector<P> v[MAXN];

void dfs(int x, int prime) {
	deg[x] = 0;
	for (auto i : v[x]) {
		if (deg[i.f]) {
			edge[i.second] = prime;
			dfs(i.f, 5-prime);
		}
	}
}

void sol() {
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		v[i].clear();
		deg[i] = 0;
	}
	int a, b;
	bool flag = false;
	for (int i=1; i<n; i++) {
		cin >> a >> b;
		deg[a]++;
		deg[b]++;
		if (deg[a] > 2 || deg[b] > 2) flag = true;
		v[a].push_back({b, i});
		v[b].push_back({a, i});
	}
	if (flag) {
		cout << -1 << '\n';
		return;
	}
	for (int i=1; i<=n; i++) {
		// cout << deg[i] << " ";
		if (deg[i] == 1) {
			dfs(i, 2);
			break;
		}
	}
	for (int i=1; i<n-1; i++) {
		cout << edge[i] << " ";
	}
	cout << edge[n-1] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}