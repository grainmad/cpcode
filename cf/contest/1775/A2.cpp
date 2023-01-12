#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
	string s;
	cin >> s;
	int n = s.size();
	for (int i=1; i<n-1; i++) {
		if (s[i] == 'a') {
			string a = s.substr(0,i), b = "a", c = s.substr(i+1);
			if (a>=b && b<=c) {
				cout << a << " " << b << " " << c << endl;
				return ;
			}
			break;
		}
	}
	for (int i=1; i<n-1; i++) {
		if (s[i] == 'b') {
			string a = s.substr(0,i), b = s.substr(i,n-i-1), c = s.substr(n-1);
			if (a<=b && b>=c) {
				cout << a << " " << b << " " << c << endl;
				return ;
			}
			break;
		}
	}
	cout << ":(\n";
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