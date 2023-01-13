#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n, k;
	cin >> n >> k;
	if ((n*n+1)/2 < k) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if ((i+j)%2==0 && k>0) {
					cout << "L";
					k--;
				} else cout << "S";
			}
			cout << endl;
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