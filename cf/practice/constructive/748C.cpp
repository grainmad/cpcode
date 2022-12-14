#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

char c[200];

void sol() {
	c['L'] = 'R'; c['R'] = 'L';
	c['U'] = 'D'; c['D'] = 'U';
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	map<char,int> mp;
	for (char i:s) {
		if (mp.count(i)==0 && (mp.size() == 2 || mp.count(c[i]))) {
			ans++;
			mp.clear();
		}
		mp[i]++;
	}
	if (!mp.empty()) ans++;
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