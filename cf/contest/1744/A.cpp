#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 505
using namespace std;

int a[N];

void sol() {
	int n; string s;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	cin >> s;
	map<int,char> mp;
	for (int i=0; i<n; i++) {
		if (!mp.count(a[i])) {
			mp[a[i]] = s[i];
		}
		if (mp[a[i]] != s[i]) {
			cout << "NO\n";
			return ;
		}
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