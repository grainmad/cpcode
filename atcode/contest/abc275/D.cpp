#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

map<ll,ll> mp;

ll dfs(ll x) {
	if (mp.count(x)) return mp[x];
	return mp[x] = dfs(x/2)+dfs(x/3);
}

void sol() {
	mp[0] = 1;
	ll n; cin >> n;
	cout << dfs(n) << endl;
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