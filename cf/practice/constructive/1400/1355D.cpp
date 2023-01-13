#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n, s;
	cin >> n >> s;
	if (s/n==1) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for (int i=0; i<n; i++) {
			cout << s/n + (i<s%n ? 1:0) << " ";
		}
		cout << endl;
		cout << s/n-1 << endl;
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