#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n;
	cin >> n;
	int l = 1, r = n;
	while (l < r) {
		int m = l+r>>1;
		cout << "? " << l << " " << m << endl;
		int cnt = 0;
		for (int i=l; i<=m; i++) {
			int x; cin >> x;
			if (l <= x && x <= m) cnt++;
		}
		if (cnt%2) {
			r = m;
		} else {
			l = m+1;
		}
	}
	cout << "! " <<  l << endl;
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