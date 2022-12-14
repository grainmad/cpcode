#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

ll x[N];

void sol() {
	int n;
	ll a, b;
	cin >> n >> a >> b;
	for (int i=1; i<=n; i++) cin >> x[i];
	ll ans = x[n]*(a+b);
	ll cnt = 0;
	for (int i=n-1; i>=0; i--) {
		cnt += (x[i+1]-x[i])*(n-i)*b;
		ans = min(ans, cnt+x[i]*(a+b));
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