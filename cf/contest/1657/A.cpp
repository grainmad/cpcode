#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int x, y;
	cin >> x >> y;
	if (x == 0 && y == 0) {
		cout << 0 << endl;
		return;
	}
	int z = sqrt(x*x + y*y);
	if (z*z == x*x + y*y) {
		cout << 1 << endl;
		return ;
	}
	cout << 2 << endl;
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