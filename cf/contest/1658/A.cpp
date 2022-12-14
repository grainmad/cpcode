#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n, ans = 0;
	string s;
	cin >> n >> s;
	int p = -1;
	for (int i=0; i<s.size(); i++) {
		if (s[i] == '0') {
			if (p != -1) {
				if (i-p == 1) ans+=2;
				if (i-p == 2) ans++;
			}
			p = i;
		}
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