#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

ll a[2][30];
ll b[2][30];

void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[0][i];
	}
	for (int i=0; i<n; i++) {
		cin >> a[1][i];
	}
	for (int i=0; i<n-1; i++) {
		if (abs(a[0][i+1]-a[0][i]) + abs(a[1][i+1]-a[1][i]) 
			> abs(a[0][i+1]-a[1][i]) + abs(a[1][i+1]-a[0][i])) {
			swap(a[0][i+1], a[1][i+1]);
		}
	}
	ll ans = 0;
	for (int i=0; i<n-1; i++) {
		ans += abs(a[0][i+1]-a[0][i])+abs(a[1][i+1]-a[1][i]);
	}
	// for (int i=0; i<n; i++) cout << a[0][i] << " "; cout << endl;
	// for (int i=0; i<n; i++) cout << a[1][i] << " "; cout << endl;
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