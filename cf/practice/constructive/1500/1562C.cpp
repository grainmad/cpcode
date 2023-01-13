#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n;
	string s;
	cin >> n >> s;
	for (int i=0; i<n/2; i++) {
		if (s[i] == '0') {
			cout << i+1 << " " << n << endl;
			cout << i+2 << " " << n << endl;
			return ;
		}
	}
	for (int i=n/2; i<n; i++) {
		if (s[i] == '0') {
			cout << 1 << " " << i+1 << endl;
			cout << 1 << " " << i << endl;
			return ;
		}
	}
	cout << 1 << " " << n-1 << endl;
	cout << 2 << " " << n << endl;
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