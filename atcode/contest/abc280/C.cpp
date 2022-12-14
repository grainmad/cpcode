#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
	string s, t;
	cin >> s >> t;
	for (int i=0; i<s.size(); i++) {
		if (s[i] != t[i]) {
			cout << i+1 << endl;
			return ;
		}
	}
	cout << s.size()+1 << endl;
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