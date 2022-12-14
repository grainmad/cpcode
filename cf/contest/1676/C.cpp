#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n, m;
	cin >> n >> m;
	std::vector<string> v(n);
	for (int i=0; i<n; i++) {
		cin >> v[i];
	}
	int ans = N;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			int cnt = 0;
			for (int k=0; k<m; k++) {
				cnt += abs(v[i][k]-v[j][k]);
			}
			ans = min(ans, cnt);
		}
	}
	cout << ans << endl;
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