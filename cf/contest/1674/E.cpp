#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[N];

void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	int c1 = 1e7;
	for (int i=1; i<n; i++) {
		int x = max(a[i-1], a[i]),  y = min(a[i-1], a[i]);
		if (x >= 2*y) c1 = min(c1, (x+1)/2);
		else c1 = min(c1, (a[i-1]+a[i]+2)/3);
	}
	int c2 = 1e7;
	for (int i=2; i<n; i++) {
		c2 = min(c2, (a[i]+a[i-2]+1)/2);
	}
	
	sort(a, a+n);
	int c3 = (a[0]+1)/2;
	if (n>1) c3 += (a[1]+1)/2;

	cout << min({c1, c2, c3}) << endl;
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