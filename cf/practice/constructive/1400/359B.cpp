#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n, k;
	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		if (i<=k) cout << (2*i-1) << " " << (2*i) << " ";
		else cout << (2*i) << " " << (2*i-1) << " ";
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