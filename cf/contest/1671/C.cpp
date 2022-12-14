#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

ll a[N];
ll b[N];
void sol() {
	int n; ll x;
	cin >> n >> x;
	for (int i=1; i<=n; i++) cin >> a[i];
	sort(a+1, a+n+1);

	for (int i=1; i<=n; i++) {
		a[i] += a[i-1];
	}
	for (int i=n; i>0; i--) {
		if (a[i] > x) {
			n--;
			continue;
		}
		b[i] = (x-a[i])/i+1;
	}
	// for (int i=1; i<=n; i++) {
	// 	cout << a[i] << " ";
	// } cout << endl;
	// for (int i=1; i<=n; i++) {
	// 	cout << b[i] << " ";
	// } cout << endl;
	for (int i=1; i<n; i++) {
		b[i] -= b[i+1];
	}
	// for (int i=1; i<=n; i++) {
	// 	cout << b[i] << " ";
	// } cout << endl;
	ll ans = 0;
	for (int i=1; i<=n; i++) {
		ans += i*b[i];
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