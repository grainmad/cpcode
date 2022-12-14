#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 200005
#define MOD 998244353
using namespace std;

vector<pair<ll,ll>> g[N];

map<ll,ll> mp;//x到b的异或值映射到x
ll n, a, b;

void dfsb(ll u, ll fa, ll x) {
	for (auto& [i,j]:g[u]) {
		if (i == fa) continue;
		mp[x^j] = i;
		dfsb(i, u, x^j);
	}
}

bool dfsa(ll u, ll fa, ll x) {
	for (auto& [i,j]:g[u]) {
		if (i == fa || i == b) continue;
		if (mp.count(j^x)) {
			return true;
		}
		if (dfsa(i, u, x^j)) return true;
	}
	return false;
}

void sol() {
	mp.clear();
	cin >> n >> a >> b;
	for (int i=1; i<=n; i++) {
		g[i].clear();
	}
	for (int i=1; i<=n-1; i++) {
		ll x, y, z;
		cin >> x >> y >> z;
		g[x].emplace_back(y,z);
		g[y].emplace_back(x,z);
	}
	dfsb(b, -1, 0);
	cout << ((mp.count(0) || dfsa(a, -1, 0))?"YES\n":"NO\n");
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