#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 100005
using namespace std;


void sol() {
	int n, k; 
	cin >> n >> k;
	std::vector<ll> v(n, 0);
	for (int i=0; i<n; i++) {
		cin >> v[i];
	}
	
	ll mx = 0, pre = 0;
	for (int i=0; i<n; i++) {
		ll d = 2;
		ll cnt = 0;
		for (int j=i; j<n; j++) {
			if (v[j]/d == 0) break;
			cnt += v[j]/d;
			d*=2;
		}
		mx = max(mx, cnt+pre);
		pre += v[i]-k;
	}
	cout << max(mx, pre) << endl;
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