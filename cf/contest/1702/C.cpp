#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

// int a[N];

void sol() {
	map<int,pair<int,int>> mp;
	int n, q, t;
	cin >> n >> q;
	for (int i=0; i<n; i++) {
		cin >> t;
		if (mp.count(t)) {
			mp[t].second = i;
		} else {
			mp[t] = {i,i};
		}
	}
	for (int i=0; i<q; i++) {
		int x, y;
		cin >> x >> y;
		if (mp.count(x) && mp.count(y) && mp[x].first < mp[y].second) cout << "YES" << endl;
		else cout << "NO" << endl;
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