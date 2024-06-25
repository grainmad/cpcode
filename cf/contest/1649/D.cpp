#include <bits/stdc++.h>
// #define SINGLE_INPUT
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
	ll n, c;
	cin >> n >> c;
	vector<int> vis(c+1), ps(c+1);
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		vis[x] = 1;
	}
	vector<ll> a;
	for (int i=1; i<=c; i++) {
		ps[i] = vis[i] + ps[i-1];
		if (vis[i]) a.push_back(i);
	}
	for (ll i:a) {
		for (int j=1; j*i<=c; j++) {
			if (vis[j]) continue;
			if (ps[min(i*(j+1)-1, c)] != ps[i*j-1]) {
				cout << "No\n";
				return ;
			}
		}
	}
	cout << "Yes\n";


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