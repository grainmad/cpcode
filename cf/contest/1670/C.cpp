#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 100005
using namespace std;

int a[N], b[N], c[N];
int ma[N], mb[N];

int st[N];

int u_find(int x) {
	if (st[x] < 0) return x;
	return st[x] = u_find(st[x]);
}

void sol() {
	int n;
	cin >> n;
	std::vector<int> v(n+1, 0);
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=1; i<=n; i++) cin >> b[i];
	for (int i=1; i<=n; i++) cin >> c[i];
	for (int i=1; i<=n; i++) {
		ma[a[i]] = i;
		mb[b[i]] = i;
	}
	for (int i=1; i<=n; i++) {
		if (c[i] == 0) continue;
		// if (c[i] == a[i]) {
		// 	c[ma[b[i]]] = b[i];
		// } else {
		// 	c[mb[a[i]]] = a[i];
		// }
		int u = i;
		while (!v[u]) {
			v[u] = 1;
			if (c[u] == a[u]) {
				c[ma[b[u]]] = b[u];
				u = ma[b[u]];
			} else {
				c[mb[a[u]]] = a[u];
				u = mb[a[u]];
			}
		} 
	}
	// for (int i=1; i<=n; i++) cout << a[i] << " ";cout << endl;
	// for (int i=1; i<=n; i++) cout << b[i] << " ";cout << endl;
	// for (int i=1; i<=n; i++) cout << c[i] << " ";cout << endl;
	for (int i=1; i<=n; i++) {
		v[i] = 0;
		st[i] = -1;
	}
	for (int i=1; i<=n; i++) {
		if (c[i] != 0) v[c[i]] = 1;
	}
	for (int i=1; i<=n; i++) {
		if (c[i] != 0) continue;
		int x = u_find(a[i]), y = u_find(b[i]);
		if (x != y) {
			int t = st[x];
			st[x] = y;
			st[y] += t;
		}
	}
	// for (int i=1; i<=n; i++) {
	// 	if (v[i]) cout << "N ";
	// 	else cout << st[i] << " ";
	// } cout << endl;
	ll ans = 1, M = 1e9+7;
	for (int i=1; i<=n; i++) {
		if (v[i] || st[i] >= -1) continue;
		ans *= 2;
		ans %= M;
	}
	cout << ans << endl;
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