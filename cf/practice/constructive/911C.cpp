#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 5005
using namespace std;

int a[N];

void sol() {
	int x;
	for (int i=0; i<3; i++) {
		cin >> x;
		a[x]++;
	}
	for (int i=1; i<=3; i++) {
		if (a[i] >= i) {
			cout << "YES" << endl;
			return ;
		}
	}
	if (a[2] == 1 && a[4] == 2) cout << "YES" << endl;
	else cout << "NO" << endl;
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