#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998224353
using namespace std;


void sol() {
	ll n, m, r;
	cin >> n >> m;
	r = n;
	int q=0, p=0;
	while (r%2==0) {
		r/=2;
		q++;
	}
	while (r%5==0) {
		r/=5;
		p++;
	}
	int mn = min(p, q);
	p -= mn;
	q -= mn;
	ll ans = 1;
	while (p>0 && ans*2<=m) {
		ans *= 2;
		p--;
	}
	while (q>0 && ans*5<=m) {
		ans *= 5;
		q--;
	}
	while (ans*10<=m) {
		ans*=10;
	}
	// cout << ans << " o" << endl;
	cout << m/ans*ans*n << endl;
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