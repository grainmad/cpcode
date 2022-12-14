#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	ll a, b;
	cin >> a >> b;
	if (b>a) swap(a, b);
	if (b == 1) {
		if (a == 1) cout << 0 << endl;
		if (a == 2) cout << 1 << endl;
		if (a>2) cout << -1 << endl;
		return;
	}
	if((a-b)%2) cout << (b-1)*2+ (a-b)*2-1 << endl;
	else cout << (b-1)*2 + (a-b)*2 << endl;
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