#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n, k, l, r, sa, sk;
	cin >> n >> k >> l >> r >> sa >> sk;
	if (k!=n)
	for (int i=0, m = (sa-sk)%(n-k), t = (sa-sk)/(n-k); i<n-k; i++) {
		if (i<m) cout << t+1 << " ";
		else cout << t << " ";
	}
	for (int i=0, m=sk%k, t = sk/k; i<k; i++) {
		if (i<m) cout << t+1 << " ";
		else cout << t << " ";
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