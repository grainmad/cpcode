#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	string s;
	cin >> s;
	int a = 0, b = 0;
	for (int i=0; i<s.size(); i++) {
		if (s[i] == '1') {
			if (a) {
				cout << "1 1" << endl;
				a = 0;
			} else {
				cout << "1 3" << endl;
				a = 1;
			}
		} else {
			if (b) {
				cout << "1 1" << endl;
				b = 0;
			} else {
				cout << "3 1" << endl;
				b = 1;
			}
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