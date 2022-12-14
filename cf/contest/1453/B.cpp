#include <bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;

ll a[N];

void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	ll ds = 0;
	for (int i=1; i<n; i++) {
		ds += abs(a[i]-a[i-1]);
	}
	ll ans = 1e18;
	for (int i=1; i<n-1; i++) {
		ans = min(ans, ds-abs(a[i]-a[i-1])-abs(a[i]-a[i+1])+abs(a[i-1]-a[i+1]));
	}
	ans = min(ans, ds-abs(a[0]-a[1]));
	ans = min(ans, ds-abs(a[n-1]-a[n-2]));
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