#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

ll a[N];

void sol() {
	int n, m;
	cin >> n >> m;
	ll s = n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	for (int i=0; i<n; i++) {
		s += max(a[i], a[(i+1)%n]);
	}
	if (s <= m) cout << "YES" << endl;
	else cout << "NO" << endl;
	// cout << (s<=m ? "YES":"NO") << endl;
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