#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 55
using namespace std;

ll a[N];

void sol() {
	int n; cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	ll S = accumulate(a, a+n, 0LL), od = 0;
	for (int i=0; i<n; i+=2) od += a[i];
	int ta = (od>=S-od?1:0);
	for (int i=0; i<n; i++) {
		if (i%2==ta) cout << 1 << " ";
		else cout << a[i] << " ";
	}
	cout << endl;
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