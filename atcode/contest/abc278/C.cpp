#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998224353
using namespace std;


void sol() {
	int n, q;
	cin >> n >> q;
	set<pair<int,int>> mp;
	for (int i=0; i<q; i++) {
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 1) {
			mp.insert({a,b});
		}
		if (t == 2) {
			mp.erase({a,b});
		}
		if (t == 3) {
			if (mp.count({a, b}) && mp.count({b, a})) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		}
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