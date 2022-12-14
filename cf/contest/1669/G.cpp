#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 55
using namespace std;

string g[N];

void sol() {
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> g[i];
	}
	// for (int i=0; i<n; i++) {
	// 	cout << g[i] << endl;
	// }
	// cout << endl;
	for (int i=0; i<m; i++) {
		int p = n, cnt = 0;
		for (int j=n-1; j>=0; j--) {
			// cout << i << " " << j << endl;
			if (g[j][i] == 'o') {
				for (int k=p-1; k>j; k--) {
					if (cnt-- > 0) {
						g[k][i] = '*';
					} else g[k][i] = '.';
				}
				cnt = 0;
				p = j;
			} else if (g[j][i] == '*') {
				cnt++;
			}
		}
		for (int k=p-1; k>-1; k--) {
			if (cnt-- > 0) {
				g[k][i] = '*';
			} else g[k][i] = '.';
		}
	}
	for (int i=0; i<n; i++) {
		cout << g[i] << endl;
	}
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