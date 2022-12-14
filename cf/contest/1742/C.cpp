#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

string s[8];

void sol() {
	int n = 8;
	for (int i=0; i<n; i++) {
		cin >> s[i];
	}
	for (int i=0; i<n; i++) {
		int r=0;
		for (int j=0; j<n; j++) {
			if (s[i][j] == 'R') r++;
		}
		if (r == n) {
			cout << "R\n";
			return ;
		} 
	}
	for (int i=0; i<n; i++) {
		int b=0;
		for (int j=0; j<n; j++) {
			if (s[j][i] == 'B') b++;
		}
		if (b == n) {
			cout << "B\n";
			return ;
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