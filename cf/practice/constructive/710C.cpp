#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n, o = 1, e = 2;
	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (min(i, n-i-1)+min(j, n-j-1)<n/2) {
				cout << e << " ";
				e += 2;
			} else {
				cout << o << " ";
				o += 2;
			}
		}
		cout << "\n";
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