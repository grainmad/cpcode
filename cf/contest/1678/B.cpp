#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n; cin >> n;
	string s; cin >> s;
	std::vector<int> v;
	int p = 0;
	for (int i=1; i<n; i++) {
		if (s[i] != s[i-1]) {
			v.push_back(i-p);
			p = i;
		}
	}
	v.push_back(n-p);
	int sz = v.size();
	std::vector<int> v2 = v;
	for (int i=sz-2; i>=0; i--) {
		if (v2[i+1]%2) {
			v2[i+1]++; v2[i]--;
		}
	}
	for (int i: v2) {
		cout << i << " ";
	} cout << endl;
	int ans = 0;
	for (int i=1; i<sz; i++) {
		if (v[i-1]%2) {
			v[i-1]++; v[i]--;
			ans++;
		}
	}
	for (int i: v) {
		cout << i << " ";
	} cout << endl;
	cout << ans << endl;
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