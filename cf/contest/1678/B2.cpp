#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n; cin >> n;
	string s1, s2; cin >> s1;
	s2 = s1;
	int p = 0, i = 1;
	while (i < n) {
		if (s1[i] != s1[i-1]) {
			if ((i-p)%2) {
				s1[i] = s1[i-1];
				p = i+1;
				i++;
			} else {
				p = i;
			}
		}
		i++;
	}
	cout << s1 << endl;
	i = n-1, p = n-1;
	while (i >= 0) {
		if (s2[i] != s2[i+1]) {
			if ((p-i)%2) {
				s2[i] = s2[i+1];
				p = i-1;
				i--;
			} else {
				p = i;
			}
		}
		i--;
	}
	cout << s2 << endl;
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