#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[N], b[N];

void sol() {
	int n, l, r;
	cin >> n >> l >> r;
	map<int,int> mp;
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=1; i<=n; i++) cin >> b[i];
	for (int i=1; i<=n; i++) {
		if (l<=i && i<=r) {
			if (++mp[a[i]] == 0) mp.erase(a[i]);
			if (--mp[b[i]] == 0) mp.erase(b[i]);
		} else if (a[i] != b[i]) {
			cout << "LIE\n";
			return;
		}
	}
	cout << (mp.empty()?"TRUTH\n":"LIE\n");
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