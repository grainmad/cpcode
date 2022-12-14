#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 1000005
using namespace std;

int n, m;
string g[N];
int sx, sy;
bool bfs(int x, int y) {
	vector<vector<int>> v(n, vector<int>(m, 0));
	v[x][y] = 1;
	queue<pair<int,int>> que;
	que.emplace(x, y);
	int cnt = 0;
	while (!que.empty()) {
		auto [a, b] = que.front(); que.pop();
		for (int i=0; i<4; i++) {
			int da = a + (i-1)%2;
			int db = b + (i-2)%2;
			if (da<0 || da>=n || db<0 || db>=m || g[da][db] == '#' || v[da][db]) continue;
			if (da == sx && db == sy) {
				cnt++;
				if (cnt==2) {
					return true;
				}
			} else {
				v[da][db] = 1;
				que.emplace(da, db);
			}
		}
	}
	return false;
}

void sol() {
	cin >> n >> m;
	for (int i=0; i<n; i++) cin >> g[i];
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (g[i][j] == 'S') {
				sx = i; sy = j;
			}
		}
	}
	for (int i=0; i<4; i++) {
		int x = sx + (i-1)%2;
		int y = sy + (i-2)%2;
		if (x<0 || x>=n || y<0 || y>=m || g[x][y] == '#') continue;
		if (bfs(x, y)) {
			cout << "Yes\n";
			return ;
		}
	}
	cout << "No\n";
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