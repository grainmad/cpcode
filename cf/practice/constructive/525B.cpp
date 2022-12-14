#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[N];


void sol() {
	string s; cin >> s;
	int n; cin >> n;
	for (int i=0; i<n; i++) {
		int x; cin >> x;
		a[x]++;
	}
	int sz = s.size();
	for (int i=1; i<=sz; i++) {
		a[i] += a[i-1];
		// cout << a[i] << " ";
	}
	// cout << endl;
	for (int i=1; i<=sz/2; i++) {
		if (a[i]%2) swap(s[i-1], s[sz-i]);
	}
	cout << s << endl;
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