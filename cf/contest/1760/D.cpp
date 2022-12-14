#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
	int n; cin >> n;
	vector<ll> a;
	for (int i=0; i<n; i++) {
		ll x; cin >> x;
		if (a.size() && a.back()==x) continue;
		a.push_back(x);
	}
	int sz = a.size();
	for (int i=1; i<sz-1; i++) {
		if (a[i-1]<a[i] && a[i]>a[i+1]) {
			cout << "NO\n";
			return ;
		}
	}
	cout << "YES\n";
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