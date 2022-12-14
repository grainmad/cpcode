#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	ll n, a, b;
	cin >> n >> a >> b;
	if (a == 1) {
		cout << ((n-1)%b==0?"YES\n":"NO\n");
		return ;
	}
	ll p = 1;
	while (p<=n) {
		if ((n-p)%b == 0) {
			cout << "YES\n";
			return ;
		}
		p*=a;
	}
	cout << "NO\n";
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