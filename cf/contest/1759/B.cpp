#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998224353
using namespace std;


void sol() {
	int m, s;
	cin >> m >> s;
	std::vector<int> v(1000, 0);
	int mx = 0;
	for (int i=0; i<m; i++) {
		int x; cin >> x;
		mx = max(mx, x);
		v[x] = 1;
	}
	for (int i=1; i<=mx; i++) {
		if (!v[i]) s-=i;
	}
	if (s <= 0) {
		cout << (s==0?"YES\n":"NO\n");
		return ;
	}
	mx++;
	while (s>0) {
		s -= mx;
		if (s <= 0) {
			cout << (s==0?"YES\n":"NO\n");
			return ;
		}
		mx++;
	}
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