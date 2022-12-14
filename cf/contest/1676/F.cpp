#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	map<int,int> mp;
	int n, k;
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		mp[x]++;
		mp[x-1];
		mp[x+1];
	}
	std::vector<pair<int,int>> v(mp.begin(), mp.end());
	// for (auto i:v) {
	// 	cout << i.first << " " << i.second << " ";
	// } cout << endl;
	int ans = -2, l, r, i = 0;
	int p = 0;
	while (i < v.size()) {
		while (i < v.size() && v[i].second < k) {
			i++;
			p = i;
		}
		if (i == v.size()) break;
		if (i-p-1 > ans) {
			ans = i-p-1;
			l = v[p].first, r = v[i].first;
		}
		i++;
	}
	if (ans == -2) cout << "-1" << endl;
	else cout << l << " " << r << endl;
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