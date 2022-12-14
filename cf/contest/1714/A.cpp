#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n, H, M;
	cin >> n >> H >> M;
	int T = H*60+M, D = 24*60;
	int ans = D;
	for (int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		int t = x*60+y;
		ans = min(ans, (t-T+D)%D);
	}
	cout << ans/60 << " " << ans%60 << endl;
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