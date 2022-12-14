#include <bits/stdc++.h>
#define ll long long
#define N 105
using namespace std;

int a[N];

void sol() {
	memset(a, 0, sizeof(a));
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		int x; cin >> x;
		a[x]++;
	}
	for (int i=0; i<m; i++) {
		int x; cin >> x;
		a[x]++;
	}
	int ans = 0;
	for (int i=1; i<=100; i++) {
		if (a[i] == 2) ans++;
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
	return 0;
}