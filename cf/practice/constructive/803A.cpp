#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 105
using namespace std;

int g[N][N];

void sol() {
	int n, k; 
	cin >> n >> k;
	// memset(g, 0, sizeof(g));
	if (n*n < k) {
		cout << -1 << endl;
		return;
	}
	int cnt = 0;
	if (k != 0)
	for (int i=0; i<n; i++) {
		int ok = 0;
		for (int j=i; j<n; j++) {
			g[i][j] = g[j][i] = 1;
			cnt += 2;
			if (i == j) cnt--;
			if (cnt >= k) {
				if (cnt == k+1) g[i][j] = g[j][i] = 0, g[i+1][i+1] = 1;
				ok = 1;
				break;
			}
		}
		if (ok) break;
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout << g[i][j] << " ";
		}
		cout << endl;
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