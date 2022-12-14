#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 2005
#define INF 0x3f3f3f3f
using namespace std;

ll a[N];
int n;

void sol() {
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	vector<ll> p(n+1, 0);
	for (int i=1; i<=n; i++) p[i] = p[i-1] + a[i-1];
	int ans = n;
	for (int i=1; i<=n; i++) {
		int k = i;
		int cnt = i;
		for (int j=i; j<=n; j++) {
			if (p[j]-p[k]==p[i]) {
				cnt = max(cnt, j-k);
				k = j;
			}
		}

		if(k == n) ans = min(ans, cnt);
	}
	cout << ans << "\n";
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