#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n;
	cin >> n;
	vector<int> p;
	int cnt = 0;
	for (int i=1; i<=n; i++) {
		ll x;
		cin >> x;
		while (x%2==0) {
			cnt++;
			x >>= 1;
		}
		int u = i, c=0;
		while (u%2==0) {
			u>>=1;
			c++;
		}
		if (c) p.push_back(c);
	}
	sort(p.rbegin(), p.rend());
	if (cnt >= n) {
		cout << "0\n";
		return ;
	}
	for (int i=0; i<p.size(); i++) {
		cnt += p[i];
		if (cnt >= n) {
			cout << i+1 << "\n";
			return ;
		}
	}
	cout << "-1\n";
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