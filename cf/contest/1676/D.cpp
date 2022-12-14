#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

ll a[205][205];
ll l[405];
ll r[405];
void sol() {
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n+m; i++) {
		l[i] = r[i] = 0;
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> a[i][j];
			l[j-i+n-1] += a[i][j];
			r[i+j] += a[i][j];
		}
	}
	// for (int i=0; i<n+m-1; i++) {
	// 	cout << l[i] << " ";
	// } cout << endl;
	// for (int i=0; i<n+m-1; i++) {
	// 	cout << r[i] << " ";
	// } cout << endl;
	ll ans = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			ans = max(ans, l[j-i+n-1]+r[i+j]-a[i][j]);
		}
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