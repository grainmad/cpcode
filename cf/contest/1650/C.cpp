#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;


void sol() {
	std::vector<pair<int,int>> v;
	unordered_map<int,int> mp;
	int n, m;
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		ll x, w;
		cin >> x >> w;
		mp[x] = i+1;
		v.push_back({x, w});
	}
	sort(v.begin(), v.end(), [](pair<int,int> & a, pair<int,int> & b) {
		return a.second < b.second;
	});
	ll sm = 0;
	for (int i=0; i<2*n; i++) {
		sm += v[i].second;
	}
	cout << sm << "\n";
	sort(v.begin(), v.begin()+2*n);
	int l = 0, r = 2*n-1;
	while (l < r) {
		cout << mp[v[l].first] << " " << mp[v[r].first] << "\n";
		l++, r--;
	}
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