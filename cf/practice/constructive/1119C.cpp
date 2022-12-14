#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 505
using namespace std;

int a[N][N], b[N][N];

void sol() {
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> b[i][j];
		}
	}
	for (int i=0; i<n; i++) {
		int cnt = 0;
		for (int j=0; j<m; j++) cnt += a[i][j]^b[i][j];
		if (cnt&1) {
			cout << "NO\n";
			return ;
		}
	}
	for (int i=0; i<m; i++) {
		int cnt = 0;
		for (int j=0; j<n; j++) cnt += a[j][i]^b[j][i];
		if (cnt&1) {
			cout << "NO\n";
			return ;
		}
	}
	cout << "YES\n";
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