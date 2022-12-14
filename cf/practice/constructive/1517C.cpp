#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n;
	cin >> n;
	std::vector<vector<int>> v(n+1, vector<int>(n+1, 0));
	for (int i=1; i<=n; i++) {
		int num; cin >> num;
		int x = i, y = i, c = num;
		while (c && x<=n && y>=1 && v[x][y] == 0) {
			v[x][y] = num;
			if (y-1>=1 && v[x][y-1] == 0) y--;
			else x++;
			c--;
		}
	} 
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=i; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
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