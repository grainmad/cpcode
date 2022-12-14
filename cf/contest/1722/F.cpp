#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 55
using namespace std;

string g[N];
int n, m;
int lx, rx, ly, ry;
int dfs(int x, int y) {
	lx = min(lx, x);
	rx = max(rx, x);
	ly = min(ly, y);
	ry = max(ry, y);
	int rt = 1;
	g[x][y] = '.';
	for (int i=-1; i<2; i++) {
		for (int j=-1; j<2; j++) {
			int dx = x + i;
			int dy = y + j;	
			if (dx<0 || dx>=n || dy<0 || dy>=m || g[dx][dy] == '.') continue;
			rt += dfs(dx, dy);
		}
	}
	return rt;
}

void sol() {
	cin >> n >> m;
	for (int i=0; i<n; i++) cin >> g[i];
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (g[i][j] == '*') {
				lx = n, rx = -1, ly = m, ry = -1;
				int cnt = dfs(i,j);
				// cout << i << " iu " << u << endl;
				// cout << j << " jv " << v << endl;
				// cout << cnt << endl;
				if (cnt != 3 || rx-lx>1 || ry-ly>1) {
					cout << "NO\n";
					return ;
				}
			}
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