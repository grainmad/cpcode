//17:01 17:23
#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

int m;
ll a[N];
ll b[N];

void sol() {
	cin >> m;
	for (int i=0; i<m; i++) {
		cin >> a[i];
	}
	for (int i=0; i<m; i++) {
		cin >> b[i];
	}
	for (int i=m-2; i>=0; i--) {
		a[i] += a[i+1];
	}
	for (int i=1; i<m; i++) {
		b[i] += b[i-1];
	}
	ll ans = 1e10;
	for (int i=0; i<m; i++) {
		// cout << a[i] << " " << b[i] << endl;
		ll t = 0;
		if (i-1>=0) t = max(t, b[i-1]);
		if (i+1<m) t = max(t, a[i+1]);
		ans = min(ans, t);
	}
	cout << ans << '\n';
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
}