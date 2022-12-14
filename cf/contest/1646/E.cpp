#include <bits/stdc++.h>
#define ll long long
#define N 1000005
#define M 20
using namespace std;

bool vis[N*M];

void sol() {
	int n, m;
	cin >> n >> m;
	std::vector<ll> v(M+1);
	int cnt = 0;
	for (int i=1; i<=M; i++) {
		for (int j=1; j<=m; j++) {
			if (vis[i*j]) continue;
			vis[j*i] = true;
			cnt++;
		}
		v[i] = cnt;
		// cout << v[i] << ", ";
	}
	for (int i=0; i<=n*M; i++) vis[i] = false;

	ll ans = 1;
	for (int i=2; i<=n; i++) {
		// cout << i << ", ";
		if (vis[i]) continue;
		ll t = i;
		int k = 0;
		while (t<=n) {
			vis[t] = true;
			k++;
			t *= i;
		}
		ans += v[k];
	}
	cout << ans << endl;
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