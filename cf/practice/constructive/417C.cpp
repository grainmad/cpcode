#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n, k; cin >> n >> k;
	int m = (n-1)/2;
	if (k>m) {
		cout << "-1" << endl;
		return ;
	}
	cout << n*k << endl;
	for (int i=0; i<n; i++) {
		for (int j=1; j<=k; j++) {
			cout << i+1 << " " << (i+j)%n+1 << "\n"; // endl time limit exceeded
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