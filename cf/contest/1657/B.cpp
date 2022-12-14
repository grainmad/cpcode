#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	ll n, b, x, y, sum = 0, cur = 0;
	cin >> n >> b >> x >> y;
	for (int i=0; i<n; i++) {
		if (cur + x > b) {
			cur -= y;
			sum += cur;
		} else {
			cur += x;
			sum += cur;
		}
	}
	cout << sum << endl;
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