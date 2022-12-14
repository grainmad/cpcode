#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 200005
using namespace std;

int b[N], p[N], r[N], ans[N];

void sol() {
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> b[i];
	}
	for (int i=1; i<=n; i++) {
		cin >> p[i];
		r[p[i]] = i;
	}
	for (int i=1; i<=n; i++) {
		if (r[b[p[i]]]>i) {
			cout << "-1\n";
			return ;
		}
		ans[p[i]] = i-r[b[p[i]]];
	}
	for (int i=1; i<=n; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
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