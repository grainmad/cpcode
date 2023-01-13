#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

ll a[N];

void sol() {
	map<int,int> mp;
	int n, m, k;
	cin >> n >> m >> k;
	ll sum = 0;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		mp[a[i]]++;
		sum += a[i];
	}
	for (int i=m*k; i<n; i++) {
		sum -= mp.begin()->first;
		if (--mp.begin()->second==0) {
			mp.erase(mp.begin());
		}
	}
	cout << sum << "\n";
	for (int i=0, cnt=0; i<n; i++) {
		if (mp.count(a[i])) {
			cnt++;
			if (cnt%m == 0) cout << i+1 << " ";
			if (--mp[a[i]]==0) mp.erase(a[i]);
			if (cnt == m*(k-1)) break;
		}
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