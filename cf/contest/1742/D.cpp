#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 1005
using namespace std;

int a[N];

int gcd(int x, int y) {
	return x == 0 ? y : gcd(y%x, x);
}

void sol() {
	int n;
	cin >> n;
	memset(a, 0, sizeof(a));
	for (int i=1; i<=n; i++) {
		int x; cin >> x;
		a[x] = i;
	}
	int mx = -1;
	for (int i=1000; i>0; i--) {
		if (a[i] == 0) continue;
		for (int j=i; j>0; j--) {
			if (a[j] && gcd(i, j) == 1) {
				// cout << i << " " << j << " " << a[i] << " " << a[j] << endl;
				mx = max(mx, a[i]+a[j]);
			}
		}
	}
	cout << mx << "\n";
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