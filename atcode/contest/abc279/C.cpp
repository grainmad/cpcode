#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

string g[N];

void sol() {
	int h, w;
	cin >> h >> w;
	for (int i=0; i<h; i++) {
		cin >> g[i];
	}
	map<ll,int> mp;
	for (int i=0; i<w; i++) {
		ll u = 0;
		for (int j=0; j<h; j++) {
			u = 2*u%MOD;
			if (g[j][i] == '.') u = (u+1)%MOD;
		}
		mp[u]++;
	}
	for (int i=0; i<h; i++) {
		cin >> g[i];
	}
	for (int i=0; i<w; i++) {
		ll u = 0;
		for (int j=0; j<h; j++) {
			u = 2*u%MOD;
			if (g[j][i] == '.') u = (u+1)%MOD;
		}
		if (--mp[u] == 0) mp.erase(u);
	}
	cout << (mp.size()?"No\n":"Yes\n") << endl;
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