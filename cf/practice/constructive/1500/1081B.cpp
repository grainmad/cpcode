#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[N];

void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int idx = 1;
	map<int,pair<int,int>> mp;
	map<int,int> cnt;
	vector<int> ans(n);
	for (int i=0; i<n; i++) {
		if (mp[a[i]].first == 0) {
			if (n-a[i]<0) {
				cout << "Impossible\n";
				return ;
			}
			mp[a[i]] = {n-a[i], idx++};
		}
		ans[i] = mp[a[i]].second;
		cnt[ans[i]]++;
		mp[a[i]].first--;
	}
	for (int i=0; i<n; i++) {
		if (cnt[ans[i]] != n-a[i]) {
			cout << "Impossible\n";
			return ;
		}
	}
	cout << "Possible\n";
	for (int i:ans) cout << i << " ";
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