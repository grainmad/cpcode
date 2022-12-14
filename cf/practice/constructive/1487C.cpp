#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n;
	cin >> n;
	int tie = (n-1)*n*3/2%n;
	int win = (n-1)*n/2-tie;
	int a = tie*2/n, b = win/n;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			if (j-i<=b) cout << "1 ";
			else if (j-i<=a+b) cout << "0 ";
			else cout << "-1 ";
		}
	}
	cout << "\n";
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