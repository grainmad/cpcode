#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n; string s;
	cin >> n >> s;
	int id = 0;
	vector<int> st0, st1, ans;
	for (int i=0; i<n; i++) {
		if (s[i] == '0') {
			if (st1.empty()) {
				st0.push_back(++id);
			} else {
				st0.push_back(st1.back());
				st1.pop_back();
			}
			ans.push_back(st0.back());
		} else {
			if (st0.empty()) {
				st1.push_back(++id);
			} else {
				st1.push_back(st0.back());
				st0.pop_back();
			}
			ans.push_back(st1.back());
		}
	}
	cout << id << "\n";
	for (int i:ans) cout << i << " ";
	cout << "\n";
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