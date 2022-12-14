#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll m = a*b;
	for (ll x=a+1; x<=c; x++) {
		ll y = m/__gcd(m, x);
		// if (y<=b) y = (b/y+1)*y;
		y = d/y*y;
		if (b<y && y<=d) {
			cout << x << " " << y << endl;
			return ;
		}
	}
	cout << "-1 -1\n";
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