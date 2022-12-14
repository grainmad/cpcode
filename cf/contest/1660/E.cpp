#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 2005
using namespace std;

int n;
string g[N];

void sol() {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> g[i];
	}
	int cnt0 = 0, cnt1 = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (g[i][j] == '0') cnt0++;
			else cnt1++;
		}
	}
	int ans = n*n;
	for (int i=0; i<n; i++) {
		int d1 = 0;
		for (int j=0; j<n; j++) {
			if (g[j][(i+j+n)%n] == '1') d1++;
		}
		ans = min(ans, n-d1+cnt1-d1);
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