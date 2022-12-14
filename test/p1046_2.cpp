#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
using namespace std;

ll pow_mod(ll a, ll b, ll n) {
	ll d = 1;
        while (b>0) {
        if (b%2 == 1) d = d * a % n;
        a = a*a%n;
        b >>= 1;
    }
	return d;
}

void sol() {
	ll b, p, k;
	bool flag = false;
	cin >> b >> p >> k;
	cout << b <<"^" << p << " mod " << k << "=";
	if (b < 0) {
		b = -b;
		flag = true;
	}
	if (p%2 == 0) {
		flag = false;
	}
	if (k < 0) {
		k = -k;
		flag = !flag;
	}
	if (flag) cout << "-";
	cout << pow_mod(b%k, p, k) << endl;
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