#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

void sol() {
	map<int, int> mp;
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		mp[x]++;
	}
	int mx = 0;
	for (auto& i:mp) {
		mx = max(mx, i.second);
	}
	int t = 0, u = mx;
	while (u<n) {
		u *=2;
		t++;
	}
	cout << t+n-mx << endl;
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