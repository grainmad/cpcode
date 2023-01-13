#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 105
using namespace std;

int a[N];

void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			int x; cin >> x;
			if (i == j) continue;
			a[i] |= x;
			a[j] |= x;
		}
	}
	for (int i=0; i<n; i++) cout << a[i] << " ";
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