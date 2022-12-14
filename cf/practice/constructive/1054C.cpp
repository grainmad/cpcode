#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 1005
using namespace std;

int l[N], r[N];

void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> l[i];
	}
	for (int i=0; i<n; i++) {
		cin >> r[i];
	}
	vector<int> ans(n, 0);
	int cnt, p = n;
	do {
		cnt = 0;
		vector<int> v(n, 0);
		for (int i=0; i<n; i++) {
			if (ans[i] == 0 && l[i] == 0 && r[i] == 0) {
				ans[i] = p;
				v[i] = -1;
				cnt++;
			}
		}
		p--;
		int add = 0;
		for (int i=0; i<n; i++) {
			add += v[i];
			if (ans[i] == 0) l[i] += add;
		}
		add = 0;
		for (int i=n-1; i>=0; i--) {
			add += v[i];
			if (ans[i] == 0) r[i] += add;
		}
		// for (int i=0; i<n; i++) {
		// 	if (l[i]<0 || r[i]<0) {
		// 		cout << "NO\n";
		// 		return ;
		// 	}
		// }
	} while (cnt != 0);
	if (count(ans.begin(), ans.end(), 0)) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for (int i:ans) cout << i << " ";
		cout << "\n";
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