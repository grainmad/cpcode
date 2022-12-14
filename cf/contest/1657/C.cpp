#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

string s;

void sol() {
	int n;
	cin >> n >> s;
	int c=0, i=0;
	while (i < n) {
		if (i+1 < n && s[i] == '(' && s[i+1] == '(') {
			c++;
			i += 2;
		} else if (i+1 < n && s[i] == ')' && s[i+1] == ')') {
			c++;
			i += 2;
		} else if (i+1 < n && s[i] == '(' && s[i+1] == ')') {
			c++;
			i += 2;
		} else {
			if (s[i] == '(') break;
			int j;
			for (j=i+1; j<n; j++) {
				if (s[j] == ')') break;
			}
			if (j == n) break;
			c++;
			i = j+1;
		}
	}
	cout << c << " " << n-i << endl;
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