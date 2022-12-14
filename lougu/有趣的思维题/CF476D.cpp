#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
using namespace std;


void sol() {
	ll n, k, mx = 0;
	cin >> n >> k;
	vector<vector<ll>> v;
	for (int i=0; i<n; i++) {
		ll e = i*6+2;
		v.push_back({(e-1)*k, e*k, (e+1)*k, (e+3)*k});
		mx = max({mx, (e-1)*k, e*k, (e+1)*k, (e+3)*k});
	}
	cout << mx << endl;
	for (auto& i:v) {
		for (int j:i) cout << j << " ";
		cout << endl;
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