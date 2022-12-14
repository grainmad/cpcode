//A
#include <bits/stdc++.h>
using namespace std;
char mp[55][55];
int n, m, r, c;
void sol() {
	cin >> n >> m >> r >> c;
	r--; c--;
	for (int i=0; i<n; i++) {
		cin>> mp[i];
	}
	if (mp[r][c] == 'B') {
		cout << 0 << endl;
		return ;
	} 
	bool one = false;
	for (int i=0; i<n; i++) {
		if (mp[i][c] == 'B') one = true;
	}
	for (int i=0; i<m; i++) {
		if (mp[r][i] == 'B') one = true;
	}
	if (one) {
		cout << 1 << endl;
		return ;
	}
	bool allw = true;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (mp[i][j] == 'B') {
				allw = false;
			}
		}
	}
	if (allw) cout << -1 <<endl;
	else cout << 2 << endl;
	
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
