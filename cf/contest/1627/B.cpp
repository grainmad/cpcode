//B
#include <bits/stdc++.h>
#define P pair<int, int>
#define x first 
#define y second 
using namespace std;


int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void sol() {
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	queue<P> que;
	int dis = n/2+m/2;
	if (n%2==0 && m%2==0) {
		que.push({n/2, m/2}); vis[n/2][m/2] = true;
		que.push({n/2-1, m/2}); vis[n/2-1][m/2] = true;
		que.push({n/2, m/2-1}); vis[n/2][m/2-1] = true;
		que.push({n/2-1, m/2-1}); vis[n/2-1][m/2-1] = true;
	} 
	if (n%2 && m%2==0) {
		que.push({n/2, m/2}); vis[n/2][m/2] = true;
		que.push({n/2, m/2-1}); vis[n/2][m/2-1] = true;
	}
	if (n%2==0 && m%2) {
		que.push({n/2, m/2}); vis[n/2][m/2] = true;
		que.push({n/2-1, m/2}); vis[n/2-1][m/2] = true;
	}
	if (n%2 && m%2) {
		que.push({n/2, m/2}); vis[n/2][m/2] = true;
	}
//	int cnt = 0;
	vector<int> ans;
	while (!que.empty()) {
		int sz = que.size();
		for (int i=0; i<sz; i++) {
			P u = que.front(); que.pop();
//			if (cnt < m*n) {
//				
//				cnt++;
//			}
			ans.push_back(dis);
			for (int i=0; i<4; i++) {
				int mx = dx[i] + u.x;
				int my = dy[i] + u.y;
				if (mx < 0 || mx >= n || my < 0 || my >= m || vis[mx][my]) continue;
				vis[mx][my] = true;
				que.push({mx, my});
			}
		}
		dis++;
	}
	for (int i=0; i<ans.size()-1; i++) {
		cout << ans[i] << " ";
	}
	cout << ans.back() << '\n';
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
	return 0;
}
