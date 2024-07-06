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
	int n;
	cin >> n;
	vector<ll> a(n);
	for (auto& i:a) cin >> i;
	sort(a.begin(), a.end());
	if (a[n-1] == 0) {
		cout << "0\n";
		return ;
	}
	ll s = accumulate(a.begin(), a.begin()+n-1, 0LL);
	if (s+1 < a[n-1]) {
		cout << a[n-1]-s << "\n";
	} else {
		cout << "1\n";
	}
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