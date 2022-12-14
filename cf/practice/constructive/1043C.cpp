#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	string s;
	cin >> s;
	int n = s.size();
	for (int i=0; i<n; i++) {
		if (i<n-1 && s[i] != s[i+1]) cout << 1 << " ";
		else if (s[i] == 'a' && i == n-1) cout << 1 << " ";
		else cout << 0 << " ";
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