//B
#include <bits/stdc++.h>
using namespace std;

struct Range {
	int l, r;
	bool operator<(Range& o) {
		return r-l > o.r-o.l;
	}
} ranges[1005];

int st[1005];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		memset(st, 0, sizeof(st));
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> ranges[i].l >> ranges[i].r;
		}
		sort(ranges, ranges+n);
		for (int i=0; i<n; i++) {
			for (int j=ranges[i].l; j<=ranges[i].r; j++) {
				st[j] = i+1;
			}
		}
		for (int i=1; i<=n; i++) {
			if (st[i] != 0) {
				cout << ranges[st[i]-1].l << " " << ranges[st[i]-1].r << " " << i << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
