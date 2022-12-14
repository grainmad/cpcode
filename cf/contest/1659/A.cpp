#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n, r, b;
	cin >> n >> r >> b;
	int t = r/(b+1);
	int k = r%(b+1);
	string s;
	for (int i=0; i<=b; i++) {
		if (i<k) {
			s += string(t+1, 'R');
		} else {
			s += string(t, 'R');
		}
		s.push_back('B');	
		
	}

	cout << s.substr(0, n) << endl;
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