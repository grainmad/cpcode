#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	ll a, b;
	cin >> a >> b;
	if (a == 0) {
		cout << 1 << endl;
		return ;
	}
	if (b == 0) {
		cout << a+1 << endl;
		return ;
	}
	cout << 2*b+a+1 << endl;
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