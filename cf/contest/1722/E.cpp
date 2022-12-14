#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 1005
using namespace std;

ll st[N][N];

void sol() {
	memset(st, 0, sizeof(st));
	int n, q;
	cin >> n >> q;
	for (int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		st[x][y] += x*y;
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			st[i][j] += st[i][j-1]+st[i-1][j]-st[i-1][j-1];
		}
	}
	for (int i=0; i<q; i++) {
		int hs, ws, hb, wb;
		cin >> hs >> ws >> hb >> wb;
		hb--; wb--;
		cout << st[hb][wb] - st[hb][ws] - st[hs][wb] + st[hs][ws] << "\n";
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