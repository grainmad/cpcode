#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	vector<ll> p(n+1,0);
	for (int i=1; i<=n; i++) p[i] = p[i-1]+a[i-1];

	for (int i=1; i<n; i++) {
		a[i] = max(a[i], a[i-1]);
	}
	for (int i=0; i<q; i++) {
		int x; cin >> x;
		int pos = upper_bound(a.begin(), a.end(), x)-a.begin();
		cout << p[pos] << " ";
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