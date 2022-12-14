#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
using namespace std;

int a[N];
int v[N];
map<int,int> mp;

void sol() {
	int n; cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	ll ans = 0;
	for (int i=0; i<n; i++) {
		mp[a[i]]--;
		if (mp[a[i]] == 0) mp.erase(a[i]);
		if (v[a[i]]) continue;
		v[a[i]] = 1;
		ans += mp.size();
	}
	cout << ans << endl;
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