#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 105
using namespace std;

string g[N];

void sol() {
	int n; cin >> n;
	for (int i=0; i<n; i++) {
		cin >> g[i];
	}
	int ans = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			int cnt = g[i][j]+g[j][n-i-1]+g[n-i-1][n-j-1]+g[n-j-1][i]-4*'0';
			ans += min(cnt, 4-cnt);
		}
	}
	cout << ans/4 << endl;
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