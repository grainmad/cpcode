#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 105
using namespace std;

string g[N];
int r[N], c[N];

void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> g[i];
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (g[i][j] == 'E') r[i]++, c[j]++;
		}
	}
	int all_row = count(r, r+n, n), all_clo = count(c, c+n, n);
	if (all_row && all_clo) {
		cout << "-1\n";
	} else if (all_row) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (g[j][i] == '.') {
					cout << j+1 << " " << i+1 << "\n";
					break;
				}
			}
		}
	} else {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (g[i][j] == '.') {
					cout << i+1 << " " << j+1 << "\n";
					break;
				}
			}
		}
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