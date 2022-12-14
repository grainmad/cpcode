//B2
#include <bits/stdc++.h>
using namespace std;

void slove() {
	const int maxn = 1e9+7;
	int n, l, r, c;
	int ml = maxn, mr = 0, len = 0, lc = maxn, rc = maxn, lenc = maxn;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> l >> r >> c;
		if (l < ml) ml = l, lc = maxn;
		if (l == ml) lc = min(lc, c);
		if (r > mr) mr = r, rc = maxn;
		if (r == mr) rc = min(rc, c);
		if (r-l+1 > len) len = r-l+1, lenc=maxn;
		if (r-l+1 == len) lenc = min(lenc, c);
		int ans = lc+rc;
		if (mr-ml+1 == len) ans = min(ans, lenc);
		cout << ans << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		slove();
	}
	return 0;
}
