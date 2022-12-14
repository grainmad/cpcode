#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

unordered_map<ll,int> mp;
bool dfs(ll u) {
	if (mp.count(u) && mp[u] != 0) {
		mp[u]--;
		return true;
	}
	if (u == 1) return false;
	ll l = u/2, r = u-l;
	if (!dfs(l)) return false;
	if (!dfs(r)) return false;
	return true;
}

void sol() {
	mp.clear();
	int n;
	ll s = 0;
	cin >> n;
	for (int i=0; i<n; i++) {
		ll x; cin >> x;
		mp[x]++;
		s += x;
	}
	if (dfs(s)) cout << "YES\n";
	else cout <<"NO\n";

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