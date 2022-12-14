#include <bits/stdc++.h>
#define ll long long
#define N 1005
using namespace std;

int mp[N][N];
struct Node {
	int x, y, c;
};
std::vector<Node> ans;
int n, m;

int block(int x, int y) {
	int rt = -1;
	for (int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			if (mp[x+i][y+j] != 0) {
				if (rt == -1) rt = mp[x+i][y+j];
				if (rt != mp[x+i][y+j]) return 0;
			}
		}
	}
	return rt;
}


void set0(int x, int y) {
	mp[x][y] = 0;
	mp[x+1][y] = 0;
	mp[x][y+1] = 0;
	mp[x+1][y+1] = 0;
}

void sol() {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> mp[i][j];
		}
	}
	queue<pair<int,int>> que;
	for (int i=0; i<n-1; i++) {
		for (int j=0; j<m-1; j++) {
			int c = block(i, j);
			if (c > 0) {
				que.push({i,j});
				ans.push_back({i, j, c});
				set0(i, j);
			}
		}
	}

	while (!que.empty()) {
		auto u = que.front(); que.pop();
		for (int i=-1; i<=1; i++) {
			for (int j=-1; j<=1; j++) {
				int x = u.first+i, y = u.second+j;
				if (x<0 || x>=n-1 || y<0 || y>=m-1) continue;
				int c = block(x, y);
				if (c > 0) {
					que.push({x, y});
					ans.push_back({x, y, c});
					set0(x, y);
				}
			}
		}
	}
	for (int j=0; j<n; j++) {
		for (int k=0; k<m; k++) {
			if (mp[j][k] != 0) {
				cout << "-1\n";
				return;
			}
		}
	} 
	
	cout << ans.size() << '\n';
	for (int i=ans.size()-1; i>=0; i--) {
		// for (int j=0; j<2; j++) {
		// 	for (int k=0; k<2; k++) {
		// 		mp[ans[i].x+j][ans[i].y+k] = ans[i].c;
		// 	}
		// }
		cout << ans[i].x+1 << " " << ans[i].y+1 << " " << ans[i].c << '\n';
	}
// 	for (int j=0; j<n; j++) {
// 		for (int k=0; k<m; k++) {
// 			cout << mp[j][k] << " ";
// 		} cout << endl;
// 	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	sol();
}