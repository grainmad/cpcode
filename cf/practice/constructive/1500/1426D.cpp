#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n;
	cin >> n;
	map<ll, int> mp;
	mp[0] = 0;
	int cnt = 0; ll pre = 0;
	for (int i=0; i<n; i++) {
		ll x; cin >> x;
		pre += x;
		if (mp.count(pre) && mp[pre] == cnt) {
			pre = x;
			cnt++;
			mp[x] = cnt;
			mp[0] = cnt;
		} else mp[pre] = cnt;
	}
	cout << cnt << endl;
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