#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 200005
using namespace std;

ll x[N], y[N], a[N];

void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> x[i];
	for (int i=0; i<n; i++) cin >> y[i];
	for (int i=0; i<n; i++) {
		a[i] = y[i]-x[i];
	}
	sort(a, a+n);
	int l = 0, r = n-1;
	int ans = 0;
	while (l<r) {
		if (a[l]+a[r]<0) l++;
		else {
			l++, r--;
			ans++;
		}
	}
	cout << ans << "\n";
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