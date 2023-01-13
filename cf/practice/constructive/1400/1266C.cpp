#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 10005
using namespace std;

void sol() {
	int r, c;
	cin >> r >> c;
	if (r == c && r == 1) {
		cout << "0" << endl;
	} else if (r == 1) {
		for (int i=2; i<=c+1; i++) cout << i << " "; cout << endl;
	} else if (c == 1) {
		for (int i=2; i<=r+1; i++) cout << i << endl;
	} else 
	for (int i=1; i<=r; i++) {
		for (int j=r+1; j<=r+c; j++) {
			cout << i*j << " ";
		}
		cout << endl;
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