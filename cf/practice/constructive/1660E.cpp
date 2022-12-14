#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 2005
using namespace std;

string g[N];

void sol() {
	int n, cnt1=0;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> g[i];
		cnt1 += count(g[i].begin(), g[i].end(), '1');
	}
	int ans = n*n;
	for (int i=0; i<n; i++) {
		int cnt = 0;
		for (int j=0; j<n; j++) {
			cnt += g[(i+j)%n][j]=='1';
		}
		ans = min(ans, cnt1+n-2*cnt);
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