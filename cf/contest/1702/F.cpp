#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	map<int,int> mp;
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		int x; cin >> x;
		while (x%2 == 0) {
			x/=2;
		}
		mp[x]++;
	}
	for (int i=0; i<n; i++) {
		int x; cin >> x;
		while (x) {
			if (mp.count(x)) {
				mp[x]--;
				if (mp[x] == 0) mp.erase(x);
				break;
			}
			x/=2;
		}
	}
	cout << (mp.empty()?"YES":"NO") << endl;
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