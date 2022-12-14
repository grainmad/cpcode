#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i=0; i<n; i++) {
		if (s[i] == '0') {
			if (i<n/2) {
				cout << i+1 << " " << n << " " << i+2 << " " << n << "\n";
			} else {
				cout << 1 << " " << i+1 << " " << 1 << " " << i << "\n";
			}
			return ;
		}
	}
	cout << 1 << " " << n-1 << " " << 2 << " " << n << "\n";
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