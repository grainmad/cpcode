	#include <bits/stdc++.h>
	//#define SINGLE_INPUT
	#define ll long long
	#define N 500005
	#define MOD 998224353
	using namespace std;


	void sol() {
		string s;
		cin >> s;
		if (s[0] != 'Y' && s[0] != 'e' && s[0] != 's') {
			cout << "NO\n";
			return;
		}
		for (int i=1; i<s.size(); i++) {
			if (s[i] == 'Y' && s[i-1] == 's') continue;
			if (s[i] == 's' && s[i-1] == 'e') continue;
			if (s[i] == 'e' && s[i-1] == 'Y') continue;
			cout << "NO\n"; return ;
		}
		cout << "YES\n";
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