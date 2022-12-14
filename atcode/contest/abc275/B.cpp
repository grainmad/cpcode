#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define M 998244353
using namespace std;


void sol() {
	ll a[6];
	for (int i=0; i<6; i++) {
		cin >> a[i];
		a[i] %= M;
	}
	cout << (a[0]%M*a[1]%M*a[2]%M-a[3]%M*a[4]%M*a[5]%M+M)%M << endl;
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