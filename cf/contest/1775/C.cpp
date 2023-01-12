#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
	ll n, x;
	cin >> n >> x;
	int _10 = -1, _11 = 64;
	for (int i=0; i<63; i++) {
		int a = n>>i&1, b = x>>i&1;
		if (a == 1 && b == 1) _11 = i;
		if (a == 1 && b == 0) _10 = i;
		if (a == 0 && b == 1) {
			cout << "-1\n";
			return ;	
		}
	}
	for (int i=62; i>=0; i--) {
		int a = n>>i&1, b = x>>i&1;
		if (a == 1 && b == 1) _11 = i;
	}
	if (_10 == -1) {
		cout << n << "\n";
		return ;
	}
	if (_10 + 1 >= _11) {
		cout << "-1\n";
		return ;
	}
	cout << ((n>>_10+1)<<_10+1|1LL<<_10+1) << endl;
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