#include <bits/stdc++.h>

using namespace std;

int n, k;
int mp[505][505];


void sol() {
	cin >> n >> k;
	if (k == 1) {
		cout << "YES" << "\n";
		for (int i=1; i<=n; i++) {
			cout << i << "\n";
		}
		return;
	}
	if (n%2 == 1) cout << "NO" << "\n";
	else {
		for (int i=1; i<=n*k/2; i++) {
			mp[(i-1)/k][(i-1)%k] = 2*i;
		}
		for (int i=1; i<=n*k/2; i++) {
			mp[(i-1)/k+n/2][(i-1)%k] = 2*i-1;
		}
		cout << "YES" << "\n";
		for (int i=0; i<n; i++) {
			cout << mp[i][0];
			for (int j=1; j<k; j++) {
				cout << " " << mp[i][j];
			}
			cout << "\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		sol();
	}
	return 0;
}