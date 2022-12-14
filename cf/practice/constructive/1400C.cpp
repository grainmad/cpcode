#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	string s; int n, x;
	cin >> s;
	cin >> x;
	n = s.size();
	string a(n, '@');
	for (int i=0; i<n; i++) {
		if (s[i] == '0') {
			if (i-x>=0) a[i-x] = '0';
			if (i+x<n) a[i+x] = '0';
		}
	}
	for (int i=0; i<n; i++) {
		if (s[i] == '1') {
			if (i-x>=0 && a[i-x] != '0' || i+x<n && a[i+x] != '0') {
				if (i-x>=0 && a[i-x] != '0') a[i-x] = '1';
				if (i+x<n && a[i+x] != '0') a[i+x] = '1';
			} else {
				cout << "-1\n";
				return ;
			}
		}
	}
	for (char& i:a) if (i=='@') i = '1';
	cout << a << "\n";

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