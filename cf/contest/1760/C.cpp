#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

ll a[N], b[N];

void sol() {
	int n; 
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b+n);
	for (int i=0; i<n; i++) {
		if (a[i] == b[n-1]) {
			cout << a[i] - b[n-2] << " ";
		} else {
			cout << a[i] - b[n-1] << " ";
		}
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