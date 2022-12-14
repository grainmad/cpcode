#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
	string s, t;
	cin >> s >> t;
	if (t.size()>s.size()) {
		cout << "No\n";
		return ;
	}
	int n = s.size(), m = t.size();
	for (int i=0; i<=n-m; i++) {
		if (s.substr(i, m) == t) {
			cout << "Yes\n";
			return ;
		}
	}
	cout << "No\n";
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