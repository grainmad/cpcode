#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 100005
using namespace std;

int a[N], b[N];

void sol() {
	int n;
	cin >> n;
	std::vector<ll> x, y;
	
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<n; i++) {
		cin >> b[i];
	}
	for (int i=0; i<n; i++) {
		if (a[i]) {
			x.push_back(b[i]);
		} else y.push_back(b[i]);
	}
	int sz = min(x.size(), y.size());
	sort(x.rbegin(), x.rend());
	sort(y.rbegin(), y.rend());
	ll ans = 0;
	for (int i=0; i<x.size(); i++) {
		ans += x[i]*(i<sz?2:1);
	}
	for (int i=0; i<y.size(); i++) {
		ans += y[i]*(i<sz?2:1);
	}
	int sub = ((x.size() == y.size())?min(x[sz-1], y[sz-1]) : 0);
	cout << ans-sub<< endl;
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