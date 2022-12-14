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
	map<int,int> mp;
	for (int i=0, j=0; i<n && j<m; i==n-1?j++:i++) {
		for (int x=i, y=j; x>=0&&y<m; x--,y++) {
			mp[a[x][y]]++;
		}
		for (int x=i, y=j; x>=0&&y<m; x--,y++) {
			if (mp.count(b[x][y])) {
				if (--mp[b[x][y]] == 0) mp.erase(b[x][y]);
			}
		}
		if (!mp.empty()) {
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