#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[N];

void sol() {
	int n;
	cin >> n;
	std::vector<pair<ll,ll>> a(n);
	vector<ll> ans;
	for (int i=0; i<n; i++) {
		ll x;
		cin >> x;
		a[i] = {x, x};
	}
	for (int i=32; i>=0; i--) {
		sort(a.rbegin(), a.rend());
		int sl = 0;
		auto& [x, y] = a[0];
		if (y>=0 && (x>>i&1)) {
			ans.push_back(y);
			sl = y;
			y = -1;
		}
		for (int j=0; j<n; j++) {
			a[j].first &= ~sl;
		}
	}
	for (int i=0; i<n; i++) {
		if (a[i].second>0) ans.push_back(a[i].second);
	}
	for (int i=0; i<n; i++) {
		cout << ans[i] << " ";
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