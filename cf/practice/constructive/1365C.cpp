#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 200005
using namespace std;

int a[N], b[N], p[N], cnt[N];

void sol() {
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		p[a[i]] = i;
	}
	for (int i=1; i<=n; i++) {
		cin >> b[i];
	}
	for (int i=1; i<=n; i++) {
		cnt[(p[b[i]]-i+n)%n]++;
	}
	int ans = 0;
	for (int i=0; i<n; i++) {
		ans = max(ans, cnt[i]);
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