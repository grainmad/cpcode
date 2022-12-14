#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	string s;
	cin >> s;
	int n = s.size();
	int l = 0, r = n-1;
	for (int i=0; i<n; i++) {
		if (s[i] == '1') l = i;
	}
	for (int i=n-1; i>=0; i--) {
		if (s[i] == '0') r = i;
	}
	cout << r - l + 1 << endl;
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