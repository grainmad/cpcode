#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[N];

void sol() {
	int n;
	cin >> n;
	int cnt = 0;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		if (a[i] == i) cnt++;
	}
	if (cnt == n) {
		cout << "0\n";
	} else if (cnt == 0) {
		cout << "1\n";
	} else {
		int p=1;
		while (p<=n && a[p] == p) {
			cnt--;
			p++;
		}
		p = n;
		while (p>=0 && a[p] == p) {
			cnt--;
			p--;
		}
		if (cnt == 0) cout << "1\n";
		else cout << "2\n";
	}
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