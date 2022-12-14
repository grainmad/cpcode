#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 200005
using namespace std;


void sol() {
	int n;
	cin >> n;
	int x = 0;
	for (int i=0; i<n-3; i++) {
		cout << i << " ";
		x ^= i;
	}
	cout << (1<<20)+x << " " << (3<<20) << " " << (1<<21) << "\n";
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