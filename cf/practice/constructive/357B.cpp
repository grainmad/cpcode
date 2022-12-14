#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[N];

void sol() {
	int n, m;
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int d[3], c[3] = {0};
		for (int j=0; j<3; j++) cin >> d[j];
		for (int j=0; j<3; j++) {
			if (a[d[j]] != 0) c[a[d[j]]-1] = 1;
		}
		for (int j=0; j<3; j++) {
			if (c[j] == 0) {
				for (int k=0; k<3; k++) {
					if (a[d[k]] == 0) {
						a[d[k]] = j+1;
						break;
					} 
				}
			}
		}
	}
	for (int i=1; i<=n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
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