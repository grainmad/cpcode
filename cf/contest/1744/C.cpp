#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n; string c, s;
	cin >> n >> c >> s;
	if (c[0] == 'g') {
		cout << "0\n";
		return ;
	}
	s += s;
	int p = -1, ans = 0;
	for (int i=0; i<2*n; i++) {
		if (p == -1 && s[i] == c[0]) {
			p = i;
		}
		if (p != -1 && s[i] == 'g') {
			ans = max(ans, i-p);
			p = -1;
		}
	}
	cout << ans << "\n";
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