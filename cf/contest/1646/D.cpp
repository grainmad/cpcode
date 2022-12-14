#include <bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;

std::vector<int> g[N];//无向图
int fa[N];
bool vis[N];
pair<int,int> dp[N][2];
int w[N];
//dp[i][0] i的子树在不包含i节点的情况下的最多好节点与最少权值（最大的负权值）
//dp[i][1] i的子树在包含i节点的情况下的最多好节点与最少权值

void dfs(int x) {
	vis[x] = true;
	for (int i:g[x]) {
		if (!vis[i]) {
			fa[i] = x;
			dfs(i);
		}
	}
}

pair<int,int> f(int x, int t) {
	if (dp[x][t].first >= 0) return dp[x][t];
	if (t) {
		dp[x][1] = {1, 1-(int)g[x].size()};
		for (int i:g[x]) {
			if (i != fa[x]) {
				auto p= f(i, 0);
				dp[x][1].first += p.first;
				dp[x][1].second += p.second;
			}
		}
	} else {
		dp[x][0] = {0, -1};
		for (int i:g[x]) {
			if (i != fa[x]) {
				auto p = max(f(i, 1), f(i, 0));
				dp[x][0].first += p.first;
				dp[x][0].second += p.second;
			}
		}
	}
	return dp[x][t];
}

void buildw(pair<int,int> val, int x) {
	if (dp[x][0] == val) {
		w[x] = 1;
		for (int i:g[x]) {
			if (i!= fa[x]) {
				buildw(max(f(i,0), f(i,1)), i);
			}
		}
	} else {
		w[x] = g[x].size();
		for (int i:g[x]) {
			if (i!=fa[x]) {
				buildw(f(i,0), i);
			}
		}
	}
}

void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n-1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if (n == 2) {
		cout << "2 2\n1 1\n";
		return;
	}
	fa[1] = -1;
	dfs(1);
	for (int i=1; i<=n; i++) {
		dp[i][0] = dp[i][1] = {-1, -1};
	}
	auto best = max(f(1, 0), f(1, 1));
	buildw(best, 1);
	ll sw = 0;
	for (int i=1; i<=n; i++) sw += w[i];
	cout << best.first << " " << sw << "\n";
	for (int i=1; i<=n; i++) {
		cout << w[i] << " ";
	}
	cout << "\n";

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// int t;
	// cin >> t;
	// while (t--) {
	// 	sol();
	// }
	sol();
}