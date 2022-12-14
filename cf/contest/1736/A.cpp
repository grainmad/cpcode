#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 105
using namespace std;

int a[N], b[N];

void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n; i++) cin >> b[i];
	int x = abs(count(a, a+n, 1)-count(b, b+n, 1))+1;
	int y = 0;
	for (int i=0; i<n; i++) {
		y += a[i] != b[i];
	}
	cout << min(x, y) << endl;
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