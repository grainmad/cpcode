#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 200005
using namespace std;

ll a[N];

void add(int x) {
	for (int i=x; i<N; i+=i&-i) {
		a[i]++;
	}
}

ll ask(ll x) {
	ll rt = 0;
	for (int i=x; i>0; i-=i&-i) {
		rt += a[i];
	}
	return rt;
}


void sol() {
	int n; cin >> n;
	for (int i=1; i<=n; i++) a[i] = 0;
	ll ans = 0;
	for (int i=1; i<=n; i++) {
		ll x; cin >> x;
		ans += i-ask(x-1)-1;
		add(x);
	}
	// cout << ans/2 << endl;
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