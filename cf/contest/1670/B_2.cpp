#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;



void sol() {
	int n; cin >> n;
	string s; cin >> s;
	int k; cin >> k;
	std::vector<int> v(26, 0);
	for (int i=0; i<k; i++) {
		string t; cin >> t;
		v[t[0]-'a'] = 1;
	}
	// for (int i:v) cout << i << " ";cout << endl;
	int ans = 0;
	int p = 0;
	for (int i=0; i<n; i++) {
		if (v[s[i]-'a']) {
			ans = max(ans, i-p);
			p = i;
		}
	}
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