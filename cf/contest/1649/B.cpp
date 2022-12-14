#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

int a[N];

void sol() {
	int n;
	ll mx = 0, sm = 0;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		mx = max(mx, 1LL*a[i]);
		sm += a[i];
	}
	if (sm == 0) cout << "0" << endl;
	else if (sm - mx < mx) cout << 2*mx-sm << endl;
	else cout << 1 << endl;
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