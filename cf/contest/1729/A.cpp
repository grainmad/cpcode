#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	ll a, b, c;
	cin >> a >> b >> c;
	if (a < abs(c-b)+c) cout << 1 << endl;
	else if (a > abs(c-b)+c) cout << 2 << endl;
	else cout << 3 << endl;

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