#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998224353
using namespace std;


void sol() {
	ll l, r, x, a, b;
	cin >> l >> r >> x >> a >> b;
	if (a>b) swap(a, b);
	if (a == b) {
		cout << "0\n";
	} else if (b-a>=x) {
		cout << "1\n";
	} else if (a-l>=x || r-b>=x) {
		cout << "2\n";
	} else if (b-l >= x && r-a >= x) {
		cout << "3\n";
	} else {
		cout << "-1\n";
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