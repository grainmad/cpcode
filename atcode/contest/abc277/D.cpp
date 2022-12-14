#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998224353
using namespace std;


void sol() {
	int n, m;
	cin >> n >> m;
	map<ll,ll> mp;
	ll sum = 0;
	for (int i=0; i<n; i++) {
		ll x; cin >> x;
		sum += x;
		mp[x]++;
	}
	vector<pair<ll,ll>> v(mp.begin(), mp.end());
	int sz = v.size();
	ll mx = 0, p = 0;
	for (int i=0; i<2*sz; i++) {
		int idx = i%sz;
		if ((v[idx].first-v[(idx-1+sz)%sz].first+m)%m>1) p = 0;
		p += v[idx].second*v[idx].first;
		mx = max(mx, p);
	}
	cout << max(sum - mx, 0LL) << endl;
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