#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n;
	string s;
	cin >> n;
	cin >> s;
	s.push_back('W');
	// if (n == 1) {
	// 	cout << "NO" << endl;
	// 	return;
	// }
	bool ok = true;
	int r=0, b=0, p = -1;
	for (int i=0; i<=n; i++) {
		if (s[i] == 'B') b++;
		if (s[i] == 'R') r++;
		if (s[i] == 'W') {
			if (i-p == 1) {
				p = i;
			} else {
				if (r == 0 && b != 0 || r != 0 && b == 0) {
					ok = false;
				}
			}
			r = b = 0;
		}
		// cout << i << endl;
		// cout << r << " " << b << endl;
		if (!ok) break;
	}
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
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