#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

void sol() {
	int n, q; cin >> n >> q;
	ll s = 0, e = 0, o = 0;
	for (int i=0; i<n; i++) {
		ll x; cin >> x;
		if (x%2) o++;
		else e++;
		s += x;
	}

	for (int i=0; i<q; i++) {
		int tp, x;
		cin >> tp >> x;
		if(tp) {
			s += o*x;
			if (x%2) e = n, o = 0;
		} else {
			s += e*x;
			if (x%2) e = 0, o = n; 
		}
		cout << s << endl;
	}
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