#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353LL
using namespace std;


void sol() {
	int n;
	cin >> n;
	if (n%2) {
		cout << "0\n";
		return ;
	}
	ll ans = 1;
	for (int i=1; i<=n/2; i++) {
		ans = ans*i%MOD;
	}
	cout << ans*ans%MOD << endl;
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