#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 14
using namespace std;

ll a[N];

void sol() {
	ll n, ans = 100;
	cin >> n;
	int sz = 1<<N;
	for (int i=0; i<sz; i++) {
		ll u = n, cnt = 0;
		for (int j=0; j<N; j++) {
			if (i>>j&1) {
				u-=a[j];
				cnt++;
				if (u<0) break;
			}
		}
		if (u>=0) {
			while (u) {
				if (u&1) cnt++;
				u>>=1;
			}
			ans = min(ans, cnt);
		}
	}
	cout << ans << "\n";
}

int main() {
	a[0] = 1;
	for (int i=1; i<N; i++) {
		a[i] = a[i-1]*(i+1);
		// cout << a[i] << endl;
	}
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