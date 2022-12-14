#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n;
	cin >> n;
	if (n < 4) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		if (n%2) {
			cout << "1 + 5 = 6\n";
			cout << "6 * 4 = 24\n";
			cout << "3 - 2 = 1\n";
			cout << "24 * 1 = 24\n";
			for (int i=6; i<=n; i+=2) {
				cout << i+1 << " - " << i << " = 1\n"; 
				cout << "24 * 1 = 24\n";
			}
		} else {
			cout << "2 * 3 = 6\n";
			cout << "6 * 4 = 24\n";
			cout << "24 * 1 = 24\n";
			for (int i=5; i<=n; i+=2) {
				cout << i+1 << " - " << i << " = 1\n";
				cout << "24 * 1 = 24\n";
			} 
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