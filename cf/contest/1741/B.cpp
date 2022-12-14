#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n;
	cin >> n;
	if (n == 2) {
		cout << "2 1\n";
	} else if (n == 3) {
		cout << "-1\n";
	} else {
		for (int i=0; i<n; i++) {
			cout << (i+2)%n+1 << " \n"[n-1==i];
		}
	}
}

int main() {
	// freopen("out.txt", "w", stdout);
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