#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 50005
using namespace std;


void sol() {
	std::vector<pair<int,ll>> v1, v2;
	int n, m, k;
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		int a; ll cnt=1; cin >> a;
		while (a%m == 0) {
			cnt *= m;
			a /= m;
		}
		if (!v1.empty() && v1.back().first == a) {
			v1.back().second += cnt;
		} else {
			// v1.push_back({a, cnt});
			v1.emplace_back(a, cnt);
		}
	}
	cin >> k;
	for (int i=0; i<k; i++) {
		int a; ll cnt=1; cin >> a;
		while (a%m == 0) {
			cnt *= m;
			a /= m;
		}
		if (!v2.empty() && v2.back().first == a) {
			v2.back().second += cnt;
		} else {
			// v2.push_back({a, cnt});
			v2.emplace_back(a, cnt);
		}

	}
	if (v1.size() != v2.size()) {
		cout << "No" << endl;
		return ;
	}
	for (int i=0; i<v1.size(); i++) {
		if (v1[i] != v2[i]) {
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
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