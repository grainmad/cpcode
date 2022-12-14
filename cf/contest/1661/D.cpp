#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

ll b[N];

void sol() {
	int n, k;
	cin >> n >> k;
	for (int i=1; i<=n; i++) cin >> b[i];
	ll l = 0, r = 1e12+7;
	while (l < r) {
		ll m = (r-l)/2+l;
		bool flag = true;
		for (int i=1; i<=k; i++) {
			if (m*i<b[i]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			r = m;
		} else {
			l = m+1;
		}
	}
	ll ans = r;
	for (int i=k+1; i<=n; i++) {
		ans += b[i]/k;
		if (b[i]%k) ans++;
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