#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 100005
using namespace std;


void sol() {
	ll a = 0, x = 0;
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		int u; cin >> u;
		a += u;
		x ^= u;
	}
	cout << 2 << endl;
	cout << x << " " << a+x << endl;

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