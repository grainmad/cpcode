#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n;
	ll x;
	cin >> n >> x;
	std::vector<ll> a(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	ll mx=a[0], mn=a[0];
	for (int i=0; i<a.size(); i++) {
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}
	// for (int i=0; i<a.size(); i++) {
	// 	cout << a[i] << " ";
	// } cout << endl;
	// a.insert(a.begin()+1, 1);
	// for (int i=0; i<a.size(); i++) {
	// 	cout << a[i] << " ";
	// } cout << endl;
	// cout << mx << " " << mn << endl;
	if (1 < mn) {
		int pos = 0;
		ll m = abs(a[0]-1);
		if (abs(a.back()-1) < m) {
			m = abs(a.back()-1);
			pos = a.size();
		}
		for (int i=1; i<a.size(); i++) {
			if (abs(a[i]-1)+abs(a[i-1]-1)-abs(a[i]-a[i-1]) < m) {
				m = abs(a[i]-1)+abs(a[i-1]-1)-abs(a[i]-a[i-1]);
				pos = i;
			}
		}
		a.insert(a.begin()+pos, 1);
	}
	if (x > 1 && x > mx) {
		int pos = 0;
		ll m = abs(a[0]-x);
		if (abs(a.back()-x) < m) {
			m = abs(a.back()-x);
			pos = a.size();
		}
		for (int i=1; i<a.size(); i++) {
			if (abs(a[i]-x)+abs(a[i-1]-x)-abs(a[i]-a[i-1]) < m) {
				m = abs(a[i]-x)+abs(a[i-1]-x)-abs(a[i]-a[i-1]);
				pos = i;
			}
		}
		a.insert(a.begin()+pos, x);
	}
	// for (int i=0; i<a.size(); i++) {
	// 	cout << a[i] << " ";
	// } cout << endl;
	ll ans = 0;
	for (int i=1; i<a.size(); i++) {
		ans += abs(a[i]-a[i-1]);
	}
	cout << ans << endl;
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