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
	for (int i=1; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			auto a = s.substr(0,i), b = s.substr(i,j-i), c = s.substr(j);
			if (a<=b && c<=b || a>=b && c>=b) {
				cout << a << " " << b << " " << c << endl;
				return ;
			}
		}
	}
	cout << ":(" << endl;
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