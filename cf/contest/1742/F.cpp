#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n;
	cin >> n;
	vector<ll> s(26,0), t(26, 0);
	s[0] = t[0] = 1;
	for (int i=0; i<n; i++) {
		int ty, len; string ss;
		cin >> ty >> len >> ss;
		// cout << ty << " " << len << " " << ss << endl;
		for (char i:ss) {
			int v = i-'a';
			if (ty == 1) s[v] += len;
			else t[v] += len;
		}
		
		// for (int i:s) {
		// 	cout << i << " ";
		// } cout << endl;
		// for (int i:t) {
		// 	cout << i << " ";
		// } cout << endl;

		int ok = 0, h1=0, h2=0;
		for (int i=25; i>0; i--) {
			if (s[i]) h1 = 1;
			if (t[i]) h2 = 1;
		}
		if (h2 == 1 || h1 == 0 && s[0]<t[0]) ok = 1;
		cout << (ok?"YES\n":"NO\n");
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