#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	vector<ll> fa, fb;
	for (int i=1; i*i<=a; i++) {
		if (a%i==0) fa.push_back(i), fa.push_back(a/i);
	}
	for (int i=1; i*i<=b; i++) {
		if (b%i==0) fb.push_back(i), fb.push_back(b/i);
	}
	for (ll i:fa) {
		for (ll j:fb) {
			ll x = i*j, y = a*b/(i*j);
			if (x<=a) x = (a/x+1)*x;
			if (y<=b) y = (b/y+1)*y;
			if (x<=c && y<=d) {
				cout << x << " " << y << "\n";
				return ;
			}
		}
	}
	cout << "-1 -1\n";
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