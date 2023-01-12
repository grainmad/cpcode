#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

bool check(set<int>& a, map<int,int>& b) {
	for (int i:a) {
		if (!b.count(i) || b[i] == 1) return false;
	}
	return true;
}

void sol() {
	int n;
	cin >> n;
	std::vector<set<int>> st(n);
	map<int,int> v;
	for (int i=0; i<n; i++) {
		int ki, p; cin >> ki;
		for (int j=0; j<ki; j++) {
			cin >> p;
			st[i].insert(p);
			v[p]++;
		}
	}
	for (int i=0; i<n; i++) {
		if (check(st[i], v)) {
			cout << "yes\n";
			return ;
		}
	}
	cout << "no\n";
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