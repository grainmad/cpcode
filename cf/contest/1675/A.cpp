#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	ll a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	if (max(0LL, x-a)+max(0LL, y-b)>c) cout << "NO" << endl;
	else cout << "YES" << endl;
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