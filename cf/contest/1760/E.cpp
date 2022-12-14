#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

ll p[N], s[N];
ll a[N];

void sol() {
	int n; cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	p[0] = a[0]==1;
	for (int i=1; i<n; i++) {
		p[i] = p[i-1] + (a[i] == 1);
	}
	s[n-1] = a[n-1]==0;
	for (int i=n-2; i>=0; i--) {
		s[i] = s[i+1] + (a[i] == 0);
	}
	ll res = 0;
	for (int i=0; i<n; i++) {
		if (a[i]) {
			res += s[i];
		}
	}
	ll ans = 0;
	for (int i=0; i<n; i++) {
		if (a[i]) {
			ans = max(ans, res+p[i]-1-s[i]);
		} else {
			ans = max(ans, res-p[i]+s[i]-1);
		}
	}
	cout << max(ans, res) << "\n";
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