#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n;
	cin >> n;
	std::vector<int> v(n);
	int mx = 0;
	for (int i=0; i<n; i++) {
		cin >> v[i];
		mx = max(mx, v[i]);
	}
	for (int i=0; i<n; i++) {
		if (mx == v[i]) {
			cout << i+1 << endl;
			break;
		}
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