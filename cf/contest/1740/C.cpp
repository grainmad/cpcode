#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 200005
using namespace std;

ll a[N];

void sol() {
	int n;
	cin >> n;
	set<ll> st;
	for (int i=0; i<n; i++) {
		ll x;
		cin >> x;
		st.insert(x);
	}
	std::vector<ll> v(st.begin(), st.end());
	int sz = v.size();
	if (sz == 1) cout << 0 << endl;
	else if (sz == 2) cout << 2*(v[1]-v[0]) << endl;
	else {
		ll ans = 0;
		for (int i=2; i<sz; i++) {
			ans = max(ans, v[i]-v[0]+v[i]-v[i-1]);
		}
		for (int i=sz-3; i>=0; i--) {
			ans = max(ans, v[i+1]-v[i]+v[sz-1]-v[i]);
		}
		cout << ans << endl;
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