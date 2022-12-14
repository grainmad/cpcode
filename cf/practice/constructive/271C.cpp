#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 1000005
using namespace std;


void sol() {
	int n, k;
	cin >> n >> k;
	if (3*k>n) {
		cout << "-1";
		return ;
	}
	for (int i=0; i<n; i++) {
		if (i+k>=n) {
			cout << (i%k+1)%k+1 << " ";
		} else {
			cout << i%k+1 << " ";
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