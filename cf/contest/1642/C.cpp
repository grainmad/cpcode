#include <bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;

int n, x;
ll a[N];

void sol() {
	map<ll, int> mp;
	ll t; 
	cin >> n >> x;
	for (int i=0; i<n; i++) {
		cin >> t;
		mp[t]++;
	}
	for (auto& i:mp) {
		if (mp.count(i.first*x)) {
			int mn = min(mp[i.first*x], i.second);
			i.second -= mn;
			mp[i.first*x] -= mn; 
		}
	}
	int ans = 0;
	for (auto& i:mp) {
		ans += i.second;
	}
	cout << ans << '\n';

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}