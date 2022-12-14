#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
using namespace std;

ll b[N], g[N];

void sol() {
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> b[i];
	}
	for (int i=0; i<m; i++) {
		cin >> g[i];
	}
	sort(b, b+n); sort(g, g+m);
	if (b[n-1] > g[0]) {
		cout << "-1\n";
		return ;
	}
	ll ans = 0, p = m-1;
	for (int i=n-1; i>=0; i--) {
		int rem = m;
		for (int j=0; p>=0 && j<m; j++) {
			if (g[p]>=b[i]) {
				ans+=g[p];
				p--;
				rem--;
			}
		}
		if (rem) {
			ans += rem*b[i];
		} else if (g[p+1] > b[i]) {
			p++;
			ans -= g[p];
			ans += b[i];
		}
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