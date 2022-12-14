#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	string s;
	cin >> s;
	if (s.size() == 1) {
		cout << "NO" << endl;
		return;
	}
	bool flag = true;
	int p = -1;
	for (int i=0; i<s.size(); i++) {
		if (s[i] == 'a') {
			if (i-p == 2) flag = false;
			p = i;
		}
	}
	if (s.size()-p == 2) flag = false;
	p = -1;
	for (int i=0; i<s.size(); i++) {
		if (s[i] == 'b') {
			if (i-p == 2) flag = false;
			p = i;
		}
	}
	if (s.size()-p == 2) flag = false;
	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;
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