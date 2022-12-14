#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	unordered_map<string,int> mp;
	int n;
	ll ans = 0;
	cin >> n;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		string t = s;
		for (char i='a'; i<='k'; i++) {
			if (i == s[0]) continue;
			t[0] = i;
			if (mp.count(t)) ans += mp[t];
		}
		t = s;
		for (char i='a'; i<='k'; i++) {
			if (i == s[1]) continue;
			t[1] = i;
			if (mp.count(t)) ans += mp[t];
		}
		mp[s]++;
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