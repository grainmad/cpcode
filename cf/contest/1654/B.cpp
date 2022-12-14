#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int cnt[26];

void sol() {
	string s;
	memset(cnt, 0, sizeof(cnt));
	cin >> s;
	int n = s.size();
	for (char i:s) {
		cnt[i-'a']++;
	}
	// for (int i=0; i<26; i++) cout << cnt[i] << " "; cout << endl;
	for (int i=0; i<n; i++) {
		if (cnt[s[i]-'a'] > 1) {
			cnt[s[i]-'a']--;
		} else {
			cout << s.substr(i) << endl;
			break;
		}
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