#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 105
using namespace std;

int a[N];

void sol() {
	int n;
	cin >> n;
	memset(a, 0, sizeof(a));
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		a[x]++;
	}
	if (a[0] > 0) {
		cout << n-a[0] << endl;
	} else {
		int d = false;
		for (int i=1; i<=100; i++) {
			if (a[i] > 1) d = true;
		}
		if (d) cout << n << endl;
		else cout << n+1 << endl;
	}
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