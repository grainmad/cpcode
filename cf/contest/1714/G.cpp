#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 200005
using namespace std;

struct Node{
	int v, a, b;
};
std::vector<Node> g[N];
std::vector<ll> st = {0};
int r[200005];

void dfs(int u, ll val) {
	r[u] = upper_bound(st.begin(), st.end(), val)-st.begin()-1;
	for (auto i:g[u]) {
		st.push_back(st.back()+i.b);
		dfs(i.v, val+i.a);
		st.pop_back();
	}

}

void sol() {
	int n;
	cin >> n;
	for (int i=0; i<=n; i++) g[i].clear();
	for (int i=2; i<=n; i++) {
		int v, a, b;
		cin >> v >> a >> b;
		g[v].push_back({i, a, b});
	}
	dfs(1, 0);
	for (int i=2; i<=n; i++) {
		cout << r[i] << " ";
	}
	cout << "\n";
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