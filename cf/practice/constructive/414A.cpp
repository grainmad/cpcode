#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n, k;
	cin >> n >> k;
	if (n/2>k) {
		cout << "-1\n";
		return ;
	}
	if (n == 1) { 
		cout << ((k == 0)?"1":"-1");
	} else {
		cout << (k-n/2+1) << " " << 2*(k-n/2+1) << " ";
		for (int i=0, j=1e9; i<n-2; i++, j--) {
			cout << j << " ";
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