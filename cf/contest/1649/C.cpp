#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

random_device seed;
ranlux48 engine(seed());
int random(int l, int r) {
	uniform_int_distribution<> distrib(l, r);
	return distrib(engine);
}
template<class t,class u> ostream& operator<<(ostream& os,const pair<t,u>& p) {
	return os<<'['<<p.first<<", "<<p.second<<']';
}
template<class t> ostream& operator<<(ostream& os,const vector<t>& v) {
	os<<'['; int s = 1;
	for(auto e:v) { if (s) s = 0; else os << ", "; os << e; }
	return os<<']';
}
template<class t,class u> ostream& operator<<(ostream& os,const map<t,u>& mp){
	os<<'{'; int s = 1;
	for(auto [x,y]:mp) { if (s) s = 0; else os << ", "; os<<x<<": "<<y; }
	return os<<'}';
}


void sol() {
	int n, m;
	cin >> n >> m;
	map<int,vector<int>> r, c;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			int x;
			cin >> x;
			r[x].push_back(i);
			c[x].push_back(j);
		}
	}
	ll ans = 0;
	for (auto& [i,j]:r) {
		sort(j.begin(), j.end());
		ll ps= 0;
		for (ll t=1; t<j.size(); t++) {
			ans += t*(j[t]-j[0])-ps;
			ps += j[t]-j[0];
		}
	}
	for (auto& [i,j]:c) {
		sort(j.begin(), j.end());
		ll ps= 0;
		for (ll t=1; t<j.size(); t++) {
			ans += t*(j[t]-j[0])-ps;
			ps += j[t]-j[0];
		}
	}
	cout << ans << "\n";
}

int main() {
	cout << setprecision(15) << fixed;
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