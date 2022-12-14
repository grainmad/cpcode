#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[(1<<17)+5];

void sol() {
	int l, r;
	cin >> l >> r;
	for (int i=0; i<=r; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i=0; i<=16; i++) {
		int p = 0, q = 0;
		for (int j=0; j<=r; j++) {
			if (j>>i&1) p++;
			if (a[j]>>i&1) q++;
		}
		if (p != q) ans |= (1<<i);
	}
	cout << ans << endl;
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